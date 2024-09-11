//
// Created by Danil on 31.08.2024.
//

#ifndef PARSE_BYTECODE_BYTECODEEXPRESSIONCOMPILER_H
#define PARSE_BYTECODE_BYTECODEEXPRESSIONCOMPILER_H

#include <vector>
#include <stdexcept>
#include "utils.h"
#include "ExpressionCompiler.h"
#include "ClassFile/bytecode.h"


struct BytecodeExpressionCompiler : ExpressionCompiler<BytecodeExpressionCompiler> {
    std::vector<u1> out;
//    std::vector<u4> constants;

    void on_push_number(Number number);

    struct print_operation {
        opcode operator()(Plus) const {
            return opcode::iadd;
        }

        opcode operator()(Minus) const {
            return opcode::isub;
        }

        opcode operator()(Mul) const {
            return opcode::imull;
        }
    };
    void on_push_op(BinaryOperation auto op){
        out.push_back(print_operation()(op));
    }

    void on_push_argument(Argument argument);
};

#endif //PARSE_BYTECODE_BYTECODEEXPRESSIONCOMPILER_H
