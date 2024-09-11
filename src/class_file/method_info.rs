use std::io::{Read, Write};
use byteorder::{ReadBytesExt, WriteBytesExt};
use crate::class_file::class_file_error::ClassFileError;
use crate::class_file::attribute_info::AttributeInfo;

#[derive(Debug, PartialEq)]
pub struct MethodInfo {
    access_flags: u16,
    name_index: u16,
    descriptor_index: u16,
    attributes: Vec<AttributeInfo>,
}

impl MethodInfo {
    pub fn read<R: Read>(reader: &mut R) -> Result<MethodInfo, ClassFileError> {
        let access_flags = reader.read_u16::<byteorder::BigEndian>()?;
        let name_index = reader.read_u16::<byteorder::BigEndian>()?;
        let descriptor_index = reader.read_u16::<byteorder::BigEndian>()?;
        let attributes_count = reader.read_u16::<byteorder::BigEndian>()?;
        let attributes = std::iter::repeat_with(|| AttributeInfo::read(reader))
            .take(attributes_count as usize)
            .collect::<Result<Vec<AttributeInfo>, ClassFileError>>()?;

        Ok(MethodInfo {
            access_flags,
            name_index,
            descriptor_index,
            attributes,
        })
    }

    pub fn write<W: Write>(&self, writer: &mut W) -> Result<(), std::io::Error> {
        writer.write_u16::<byteorder::BigEndian>(self.access_flags)?;
        writer.write_u16::<byteorder::BigEndian>(self.name_index)?;
        writer.write_u16::<byteorder::BigEndian>(self.descriptor_index)?;
        writer.write_u16::<byteorder::BigEndian>(self.attributes.len() as u16)?;
        for attribute in &self.attributes {
            attribute.write(writer)?;
        }
        Ok(())
    }
}