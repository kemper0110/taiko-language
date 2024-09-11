use pest_derive::Parser;

#[derive(Parser)]
#[grammar = "grammar/Taiko.pest"]
pub struct TaikoParser;

#[derive(Debug)]
pub enum BinOp {
    Add,
    Subtract,
    Multiply,
    Divide,
    Power,
}

pub enum TaikoToken {
    BinOp(BinOp),
    Num(f64),
}

impl BinOp {
    // Convert from a Rule to a BinOp variant
    pub fn from_rule(rule: Rule) -> Option<BinOp> {
        match rule {
            Rule::add => Some(BinOp::Add),
            Rule::subtract => Some(BinOp::Subtract),
            Rule::multiply => Some(BinOp::Multiply),
            Rule::divide => Some(BinOp::Divide),
            Rule::power => Some(BinOp::Power),
            _ => None,
        }
    }
    pub fn priority(&self) -> i32 {
        match self {
            BinOp::Add => 1,
            BinOp::Subtract => 1,
            BinOp::Multiply => 2,
            BinOp::Divide => 2,
            BinOp::Power => 3,
        }
    }
    pub fn as_string(&self) -> &str {
        match self {
            BinOp::Add => "+",
            BinOp::Subtract => "-",
            BinOp::Multiply => "*",
            BinOp::Divide => "/",
            BinOp::Power => "^",
        }
    }
}