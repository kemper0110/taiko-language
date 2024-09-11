use std::io::Read;
use byteorder::ReadBytesExt;
use crate::class_file::class_file_error::ClassFileError;
use crate::class_file::attribute_info::AttributeInfo;

#[derive(Debug)]
pub struct FieldInfo {
    access_flags: u16,
    name_index: u16,
    descriptor_index: u16,
    attributes: Vec<AttributeInfo>,
}

impl FieldInfo {
    pub fn read<R: Read>(reader: &mut R) -> Result<FieldInfo, ClassFileError> {
        let access_flags = reader.read_u16::<byteorder::BigEndian>()?;
        let name_index = reader.read_u16::<byteorder::BigEndian>()?;
        let descriptor_index = reader.read_u16::<byteorder::BigEndian>()?;
        let attributes_count = reader.read_u16::<byteorder::BigEndian>()?;
        let attributes = std::iter::repeat_with(|| AttributeInfo::read(reader))
            .take(attributes_count as usize)
            .collect::<Result<Vec<AttributeInfo>, ClassFileError>>()?;

        Ok(FieldInfo {
            access_flags,
            name_index,
            descriptor_index,
            attributes,
        })
    }
}