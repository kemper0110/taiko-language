//
// Created by Danil on 31.08.2024.
//

#include "Expression/compileToBytecode.h"
#include "Expression/BytecodeExpressionCompiler.h"

std::vector<u1> compileToBytecode(const std::vector<token> &input) {
    BytecodeExpressionCompiler compiler;
    for (const auto &token: input)
        std::visit(compiler, token);
    compiler.afterlife();
    return compiler.out;
}
