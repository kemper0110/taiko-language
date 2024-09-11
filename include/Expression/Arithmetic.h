//
// Created by Danil on 25.08.2024.
//

#ifndef PARSE_BYTECODE_ARITHMETIC_H
#define PARSE_BYTECODE_ARITHMETIC_H

#include <variant>
#include <string_view>
#include <string>

struct Plus {
};
struct Minus {
};
struct Mul {
};
struct Number {
    int value;
};
struct LParen {
};
struct RParen {
};
struct Argument {
    int index;
};

template<typename T>
concept BinaryOperation =
std::is_same_v<T, Plus> ||
std::is_same_v<T, Minus> ||
std::is_same_v<T, Mul>;

using token = std::variant<Plus, Minus, Mul, Number, Argument, LParen, RParen>;
using bin_op = std::variant<Plus, Minus, Mul>;


template<class... Ts>
struct overloaded : Ts ... {
    using Ts::operator()...;
};


struct priority_operation {
    int operator()(BinaryOperation auto op) const {
        if constexpr (std::is_same_v<decltype(op), Plus> || std::is_same_v<decltype(op), Minus>)
            return 1;
        else
            return 2;
    }
};


#endif //PARSE_BYTECODE_ARITHMETIC_H
