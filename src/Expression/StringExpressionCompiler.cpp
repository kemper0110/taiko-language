//
// Created by Danil on 31.08.2024.
//

#include "Expression/StringExpressionCompiler.h"

void StringExpressionCompiler::on_push_number(Number number) {
    out += "\nbipush\n" + std::to_string(number.value);
}

void StringExpressionCompiler::on_push_argument(Argument argument) {
    out += "\niload_" + std::to_string(argument.index);
}
