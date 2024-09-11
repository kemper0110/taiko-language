use std::io::{Read, Write};
use byteorder::{ReadBytesExt, WriteBytesExt};
use crate::class_file::class_file_error::ClassFileError;


#[repr(u8)]
enum ConstantPoolTag {
    ConstantUtf8 = 1,
    ConstantInteger = 3,
    ConstantFloat = 4,
    ConstantLong = 5,
    ConstantDouble = 6,
    ConstantClass = 7,
    ConstantString = 8,
    ConstantFieldref = 9,
    ConstantMethodref = 10,
    ConstantInterfaceMethodref = 11,
    ConstantNameAndType = 12,
    ConstantMethodHandle = 15,
    ConstantMethodType = 16,
    ConstantInvokeDynamic = 18,
}

#[derive(Debug, PartialEq)]
struct ClassInfo {
    name_index: u16,
}

#[derive(Debug, PartialEq)]
struct FieldrefInfo {
    class_index: u16,
    name_and_type_index: u16,
}

#[derive(Debug, PartialEq)]
struct MethodrefInfo {
    class_index: u16,
    name_and_type_index: u16,
}

#[derive(Debug, PartialEq)]
struct InterfaceMethodrefInfo {
    class_index: u16,
    name_and_type_index: u16,
}

#[derive(Debug, PartialEq)]
struct StringInfo {
    string_index: u16,
}

#[derive(Debug, PartialEq)]
struct IntegerInfo {
    value: u32,
}

#[derive(Debug, PartialEq)]
struct FloatInfo {
    value: u32,
}

#[derive(Debug, PartialEq)]
struct NameAndTypeInfo {
    name_index: u16,
    descriptor_index: u16,
}

#[derive(Debug, PartialEq)]
struct Utf8Info {
    str: String,
}

#[derive(Debug, PartialEq)]
struct MethodHandleInfo {
    reference_kind: u8,
    reference_index: u16,
}

#[derive(Debug, PartialEq)]
struct MethodTypeInfo {
    descriptor_index: u16,
}

#[derive(Debug, PartialEq)]
struct InvokeDynamicInfo {
    bootstrap_method_attr_index: u16,
    name_and_type_index: u16,
}

#[derive(Debug, PartialEq)]
pub enum CpInfo {
    ClassInfo(ClassInfo),
    FieldrefInfo(FieldrefInfo),
    MethodrefInfo(MethodrefInfo),
    InterfaceMethodrefInfo(InterfaceMethodrefInfo),
    StringInfo(StringInfo),
    IntegerInfo(IntegerInfo),
    FloatInfo(FloatInfo),
    NameAndTypeInfo(NameAndTypeInfo),
    Utf8Info(Utf8Info),
    MethodHandleInfo(MethodHandleInfo),
    MethodTypeInfo(MethodTypeInfo),
    InvokeDynamicInfo(InvokeDynamicInfo),
}

impl TryFrom<u8> for ConstantPoolTag {
    type Error = ();

    fn try_from(value: u8) -> Result<Self, Self::Error> {
        match value {
            1 => Ok(ConstantPoolTag::ConstantUtf8),
            3 => Ok(ConstantPoolTag::ConstantInteger),
            4 => Ok(ConstantPoolTag::ConstantFloat),
            5 => Ok(ConstantPoolTag::ConstantLong),
            6 => Ok(ConstantPoolTag::ConstantDouble),
            7 => Ok(ConstantPoolTag::ConstantClass),
            8 => Ok(ConstantPoolTag::ConstantString),
            9 => Ok(ConstantPoolTag::ConstantFieldref),
            10 => Ok(ConstantPoolTag::ConstantMethodref),
            11 => Ok(ConstantPoolTag::ConstantInterfaceMethodref),
            12 => Ok(ConstantPoolTag::ConstantNameAndType),
            15 => Ok(ConstantPoolTag::ConstantMethodHandle),
            16 => Ok(ConstantPoolTag::ConstantMethodType),
            18 => Ok(ConstantPoolTag::ConstantInvokeDynamic),
            _ => Err(()),
        }
    }
}

impl CpInfo {
    pub fn read<R: Read>(reader: &mut R) -> Result<CpInfo, ClassFileError> {
        let tag = reader.read_u8()?;
        match ConstantPoolTag::try_from(tag)? {
            ConstantPoolTag::ConstantClass => Ok(CpInfo::ClassInfo(ClassInfo {
                name_index: reader.read_u16::<byteorder::BigEndian>()?,
            })),
            ConstantPoolTag::ConstantFieldref => Ok(CpInfo::FieldrefInfo(FieldrefInfo {
                class_index: reader.read_u16::<byteorder::BigEndian>()?,
                name_and_type_index: reader.read_u16::<byteorder::BigEndian>()?,
            })),
            ConstantPoolTag::ConstantMethodref => Ok(CpInfo::MethodrefInfo(MethodrefInfo {
                class_index: reader.read_u16::<byteorder::BigEndian>()?,
                name_and_type_index: reader.read_u16::<byteorder::BigEndian>()?,
            })),
            ConstantPoolTag::ConstantInterfaceMethodref => Ok(CpInfo::InterfaceMethodrefInfo(
                InterfaceMethodrefInfo {
                    class_index: reader.read_u16::<byteorder::BigEndian>()?,
                    name_and_type_index: reader.read_u16::<byteorder::BigEndian>()?,
                },
            )),
            ConstantPoolTag::ConstantString => Ok(CpInfo::StringInfo(StringInfo {
                string_index: reader.read_u16::<byteorder::BigEndian>()?,
            })),
            ConstantPoolTag::ConstantInteger => Ok(CpInfo::IntegerInfo(IntegerInfo {
                value: reader.read_u32::<byteorder::BigEndian>()?,
            })),
            ConstantPoolTag::ConstantFloat => Ok(CpInfo::FloatInfo(FloatInfo {
                value: reader.read_u32::<byteorder::BigEndian>()?,
            })),
            ConstantPoolTag::ConstantNameAndType => Ok(CpInfo::NameAndTypeInfo(NameAndTypeInfo {
                name_index: reader.read_u16::<byteorder::BigEndian>()?,
                descriptor_index: reader.read_u16::<byteorder::BigEndian>()?,
            })),
            ConstantPoolTag::ConstantUtf8 => {
                let len = reader.read_u16::<byteorder::BigEndian>()?;
                let mut bytes = vec![0; len as usize];
                reader.read_exact(&mut bytes)?;
                Ok(CpInfo::Utf8Info(Utf8Info {
                    str: String::from_utf8(bytes)?,
                }))
            },
            ConstantPoolTag::ConstantMethodHandle => Ok(CpInfo::MethodHandleInfo(MethodHandleInfo {
                reference_kind: reader.read_u8()?,
                reference_index: reader.read_u16::<byteorder::BigEndian>()?,
            })),
            ConstantPoolTag::ConstantMethodType => Ok(CpInfo::MethodTypeInfo(MethodTypeInfo {
                descriptor_index: reader.read_u16::<byteorder::BigEndian>()?,
            })),
            ConstantPoolTag::ConstantInvokeDynamic => Ok(CpInfo::InvokeDynamicInfo(InvokeDynamicInfo {
                bootstrap_method_attr_index: reader.read_u16::<byteorder::BigEndian>()?,
                name_and_type_index: reader.read_u16::<byteorder::BigEndian>()?,
            })),
            _ => {
                Err(ClassFileError::from(std::io::Error::new(std::io::ErrorKind::InvalidData, format!("invalid constant pool tag {}", tag.to_string()))))
            }
        }
    }

    pub fn write<W: Write>(&self, writer: &mut W) -> Result<(), std::io::Error> {
        match self {
            CpInfo::ClassInfo(info) => {
                writer.write_u8(ConstantPoolTag::ConstantClass as u8)?;
                writer.write_u16::<byteorder::BigEndian>(info.name_index)?;
            },
            CpInfo::FieldrefInfo(info) => {
                writer.write_u8(ConstantPoolTag::ConstantFieldref as u8)?;
                writer.write_u16::<byteorder::BigEndian>(info.class_index)?;
                writer.write_u16::<byteorder::BigEndian>(info.name_and_type_index)?;
            },
            CpInfo::MethodrefInfo(info) => {
                writer.write_u8(ConstantPoolTag::ConstantMethodref as u8)?;
                writer.write_u16::<byteorder::BigEndian>(info.class_index)?;
                writer.write_u16::<byteorder::BigEndian>(info.name_and_type_index)?;
            },
            CpInfo::InterfaceMethodrefInfo(info) => {
                writer.write_u8(ConstantPoolTag::ConstantInterfaceMethodref as u8)?;
                writer.write_u16::<byteorder::BigEndian>(info.class_index)?;
                writer.write_u16::<byteorder::BigEndian>(info.name_and_type_index)?;
            },
            CpInfo::StringInfo(info) => {
                writer.write_u8(ConstantPoolTag::ConstantString as u8)?;
                writer.write_u16::<byteorder::BigEndian>(info.string_index)?;
            },
            CpInfo::IntegerInfo(info) => {
                writer.write_u8(ConstantPoolTag::ConstantInteger as u8)?;
                writer.write_u32::<byteorder::BigEndian>(info.value)?;
            },
            CpInfo::FloatInfo(info) => {
                writer.write_u8(ConstantPoolTag::ConstantFloat as u8)?;
                writer.write_u32::<byteorder::BigEndian>(info.value)?;
            },
            CpInfo::NameAndTypeInfo(info) => {
                writer.write_u8(ConstantPoolTag::ConstantNameAndType as u8)?;
                writer.write_u16::<byteorder::BigEndian>(info.name_index)?;
                writer.write_u16::<byteorder::BigEndian>(info.descriptor_index)?;
            },
            CpInfo::Utf8Info(info) => {
                writer.write_u8(ConstantPoolTag::ConstantUtf8 as u8)?;
                let bytes = info.str.as_bytes();
                writer.write_u16::<byteorder::BigEndian>(bytes.len() as u16)?;
                writer.write_all(bytes)?;
            },
            CpInfo::MethodHandleInfo(info) => {
                writer.write_u8(ConstantPoolTag::ConstantMethodHandle as u8)?;
                writer.write_u8(info.reference_kind)?;
                writer.write_u16::<byteorder::BigEndian>(info.reference_index)?;
            },
            CpInfo::MethodTypeInfo(info) => {
                writer.write_u8(ConstantPoolTag::ConstantMethodType as u8)?;
                writer.write_u16::<byteorder::BigEndian>(info.descriptor_index)?;
            },
            CpInfo::InvokeDynamicInfo(info) => {
                writer.write_u8(ConstantPoolTag::ConstantInvokeDynamic as u8)?;
                writer.write_u16::<byteorder::BigEndian>(info.bootstrap_method_attr_index)?;
                writer.write_u16::<byteorder::BigEndian>(info.name_and_type_index)?;
            },
        }
        Ok(())
    }
}