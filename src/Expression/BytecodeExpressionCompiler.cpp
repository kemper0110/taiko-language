//
// Created by Danil on 31.08.2024.
//

#include "Expression/BytecodeExpressionCompiler.h"


void BytecodeExpressionCompiler::on_push_number(Number number) {
    out.push_back(opcode::bipush);
    out.push_back((u1) number.value);
}

void BytecodeExpressionCompiler::on_push_argument(Argument argument) {
    if (argument.index >= 4)
        throw std::runtime_error("no iload for this argument!");
    out.push_back(opcode::iload_0 + argument.index);
}
