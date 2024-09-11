use crate::grammar::taiko_parser::{BinOp, Rule, TaikoParser, TaikoToken};
use pest::iterators::Pairs;
use pest::Parser;
use std::fmt::Display;
use std::io::Read;

mod class_file;
mod grammar;


fn calculate_on_stack(tokens: Vec<TaikoToken>) -> f64 {
    let mut stack: Vec<f64> = Vec::new();
    for token in tokens {
        match token {
            TaikoToken::Num(num) => {
                stack.push(num);
            },
            TaikoToken::BinOp(op) => {
                let a = stack.pop().unwrap();
                let b = stack.pop().unwrap();
                stack.push(match op {
                    BinOp::Add => a + b,
                    BinOp::Subtract => a - b,
                    BinOp::Multiply => a * b,
                    BinOp::Divide => a / b,
                    BinOp::Power => a.powf(b),
                });
            }
        }
    }
    stack.pop().unwrap()
}

fn eval(expression: Pairs<Rule>) -> f64 {
    let mut out: Vec<TaikoToken> = Vec::new();
    let mut stack: Vec<BinOp> = Vec::new();
    for record in expression {
        match record.as_rule() {
            Rule::num | Rule::int => {
                out.push(TaikoToken::Num(record.as_str().parse::<f64>().unwrap()));
            }
            Rule::add | Rule::subtract | Rule::multiply | Rule::divide | Rule::power => {
                let op = BinOp::from_rule(record.as_rule()).unwrap();
                while !stack.is_empty() && stack.last().unwrap().priority() < op.priority() {
                    out.push(TaikoToken::BinOp(stack.pop().unwrap()));
                }
                stack.push(op);
            }
            Rule::expr => {
                out.push(TaikoToken::Num(eval(record.into_inner())));
            }
            _ => {}
        }
    }
    while !stack.is_empty() {
        out.push(TaikoToken::BinOp(stack.pop().unwrap()));
    }
    calculate_on_stack(out)
}


fn main() {
    // let file_name = "C:\\Users\\Danil\\IdeaProjects\\compile-java\\target\\classes\\org\\danil\\Expression.class";
    // let mut file = File::open(&file_name).expect("file not found");
    // let class_file = ClassFile::read(&mut file).expect("failed to read class file");
    // println!("{:#?}", class_file);

    let input = r#"2 * (2 + 2)"#;

    let pairs = TaikoParser::parse(Rule::calculation, input)
        .expect("failed to parse")
        .next().unwrap().into_inner()
        ;

    let result = eval(pairs);
    println!("{}", result);
}
