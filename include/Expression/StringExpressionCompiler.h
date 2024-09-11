//
// Created by Danil on 31.08.2024.
//

#ifndef PARSE_BYTECODE_STRINGEXPRESSIONCOMPILER_H
#define PARSE_BYTECODE_STRINGEXPRESSIONCOMPILER_H

#include "ExpressionCompiler.h"

struct StringExpressionCompiler : ExpressionCompiler<StringExpressionCompiler> {
    std::string &out;

    explicit StringExpressionCompiler(std::string &out) : out(out) {
    }

    struct print_operation {
        std::string_view operator()(Plus op) const {
            return "iadd";
        }

        std::string_view operator()(Minus op) const {
            return "isub";
        }

        std::string_view operator()(Mul op) const {
            return "imul";
        }
    };

    void on_push_number(Number number);

    void on_push_op(BinaryOperation auto op) {
        out += "\n" + std::string(print_operation()(op));
    }

    void on_push_argument(Argument argument);
};

#endif //PARSE_BYTECODE_STRINGEXPRESSIONCOMPILER_H
