use std::io::Read;
use byteorder::ReadBytesExt;
use crate::class_file::class_file_error::ClassFileError;

#[derive(Debug)]
pub struct AttributeInfo {
    attribute_name_index: u16,
    info: Vec<u8>,
}

impl AttributeInfo {
    pub fn read<R: Read>(reader: &mut R) -> Result<AttributeInfo, ClassFileError> {
        let attribute_name_index = reader.read_u16::<byteorder::BigEndian>()?;
        let attribute_length = reader.read_u32::<byteorder::BigEndian>()?;
        let mut info = vec![0; attribute_length as usize];
        reader.read_exact(&mut info)?;

        Ok(AttributeInfo {
            attribute_name_index,
            info,
        })
    }
}