use std::io::{Read, Write};
use byteorder::{ReadBytesExt, WriteBytesExt};
use crate::class_file::attribute_info::AttributeInfo;
use crate::class_file::constant_pool::CpInfo;
use crate::class_file::class_file_error::ClassFileError;
use crate::class_file::field_info::FieldInfo;
use crate::class_file::method_info::MethodInfo;

#[derive(Debug, PartialEq)]
pub struct ClassFile {
    magic: u32,
    minor_version: u16,
    major_version: u16,
    constant_pool: Vec<CpInfo>,
    access_flags: u16,
    this_class: u16,
    super_class: u16,

    interfaces: Vec<u16>,
    fields: Vec<FieldInfo>,
    methods: Vec<MethodInfo>,
    attributes: Vec<AttributeInfo>,
}

impl ClassFile {
    pub fn read<R: Read>(reader: &mut R) -> Result<ClassFile, ClassFileError> {
        let magic = reader.read_u32::<byteorder::BigEndian>()?;
        let minor_version = reader.read_u16::<byteorder::BigEndian>()?;
        let major_version = reader.read_u16::<byteorder::BigEndian>()?;
        let constant_pool_count = reader.read_u16::<byteorder::BigEndian>()?;
        let constant_pool = std::iter::repeat_with(|| CpInfo::read(reader))
            .take((constant_pool_count - 1) as usize)
            .collect::<Result<Vec<CpInfo>, ClassFileError>>()?;
        let access_flags = reader.read_u16::<byteorder::BigEndian>()?;
        let this_class = reader.read_u16::<byteorder::BigEndian>()?;
        let super_class = reader.read_u16::<byteorder::BigEndian>()?;
        let interfaces_count = reader.read_u16::<byteorder::BigEndian>()?;
        let interfaces = std::iter::repeat_with(|| reader.read_u16::<byteorder::BigEndian>())
            .take(interfaces_count as usize)
            .collect::<Result<Vec<u16>, std::io::Error>>()?;
        let fields_count = reader.read_u16::<byteorder::BigEndian>()?;
        let fields = std::iter::repeat_with(|| FieldInfo::read(reader))
            .take(fields_count as usize)
            .collect::<Result<Vec<FieldInfo>, ClassFileError>>()?;

        let methods_count = reader.read_u16::<byteorder::BigEndian>()?;
        let methods = std::iter::repeat_with(|| MethodInfo::read(reader))
            .take(methods_count as usize)
            .collect::<Result<Vec<MethodInfo>, ClassFileError>>()?;

        let attributes_count = reader.read_u16::<byteorder::BigEndian>()?;
        let attributes = std::iter::repeat_with(|| AttributeInfo::read(reader))
            .take(attributes_count as usize)
            .collect::<Result<Vec<AttributeInfo>, ClassFileError>>()?;

        Ok(ClassFile {
            magic,
            minor_version,
            major_version,
            constant_pool,
            access_flags,
            this_class,
            super_class,
            interfaces,
            fields,
            methods,
            attributes,
        })
    }

    pub fn write<W: Write>(&self, writer: &mut W) -> Result<(), std::io::Error> {
        writer.write_u32::<byteorder::BigEndian>(self.magic)?;
        writer.write_u16::<byteorder::BigEndian>(self.minor_version)?;
        writer.write_u16::<byteorder::BigEndian>(self.major_version)?;
        writer.write_u16::<byteorder::BigEndian>((self.constant_pool.len() + 1) as u16)?;
        for constant_pool in &self.constant_pool {
            constant_pool.write(writer)?;
        }
        writer.write_u16::<byteorder::BigEndian>(self.access_flags)?;
        writer.write_u16::<byteorder::BigEndian>(self.this_class)?;
        writer.write_u16::<byteorder::BigEndian>(self.super_class)?;
        writer.write_u16::<byteorder::BigEndian>(self.interfaces.len() as u16)?;
        for interface in &self.interfaces {
            writer.write_u16::<byteorder::BigEndian>(*interface)?;
        }
        writer.write_u16::<byteorder::BigEndian>(self.fields.len() as u16)?;
        for field in &self.fields {
            field.write(writer)?;
        }
        writer.write_u16::<byteorder::BigEndian>(self.methods.len() as u16)?;
        for method in &self.methods {
            method.write(writer)?;
        }
        writer.write_u16::<byteorder::BigEndian>(self.attributes.len() as u16)?;
        for attribute in &self.attributes {
            attribute.write(writer)?;
        }
        Ok(())
    }
}
