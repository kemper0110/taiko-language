
#[derive(Debug)]
pub enum ClassFileError {
    IoError(std::io::Error),
    InvalidTagError,
    FromUtf8Error(std::string::FromUtf8Error),
}

impl From<std::io::Error> for ClassFileError {
    fn from(err: std::io::Error) -> ClassFileError {
        ClassFileError::IoError(err)
    }
}

impl From<std::string::FromUtf8Error> for ClassFileError {
    fn from(err: std::string::FromUtf8Error) -> ClassFileError {
        ClassFileError::FromUtf8Error(err)
    }
}

// Since TryFrom<u8> for ConstantPoolTag returns a () error, we map it to our custom error.
impl From<()> for ClassFileError {
    fn from(_: ()) -> ClassFileError {
        ClassFileError::InvalidTagError
    }
}