//
// Created by Danil on 31.08.2024.
//

#ifndef PARSE_BYTECODE_EXPRESSIONCOMPILER_H
#define PARSE_BYTECODE_EXPRESSIONCOMPILER_H

#include <stack>
#include "Arithmetic.h"


template<typename ConcreteCompiler>
struct ExpressionCompiler {
    std::stack<bin_op> stack{};

    void operator()(Number number) {
        (static_cast<ConcreteCompiler *>(this))->on_push_number(number);
    }

    void operator()(Argument argument) {
        (static_cast<ConcreteCompiler *>(this))->on_push_argument(argument);
    }

    void operator()(LParen) {}

    void operator()(RParen) {}

    void operator()(BinaryOperation auto op) {
        const auto comparer = [op](auto top_op) {
            return priority_operation()(op) <= priority_operation()(top_op);
        };
        while (!stack.empty() && std::visit(comparer, stack.top())) {
            std::visit([this](auto &&op) { this->self_on_push_op(op); }, stack.top());
            stack.pop();
        }
        stack.emplace(op);
    }

    void afterlife() {
        while (!stack.empty()) {
            std::visit([this](auto &&op) { this->self_on_push_op(op); }, stack.top());
            stack.pop();
        }
    }

    void self_on_push_op(BinaryOperation auto op) {
        (static_cast<ConcreteCompiler *>(this))->on_push_op(op);
    }
};

#endif //PARSE_BYTECODE_EXPRESSIONCOMPILER_H
