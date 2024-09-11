//
// Created by Danil on 31.08.2024.
//

#include "Expression/compileToString.h"
#include "Expression/StringExpressionCompiler.h"

std::string compileToString(const std::vector<token> &input) {
    std::string out;
    StringExpressionCompiler compiler(out);
    for (const auto &token: input)
        std::visit(compiler, token);
    compiler.afterlife();
    return out;
}
