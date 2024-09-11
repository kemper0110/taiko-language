//
// Created by Danil on 31.08.2024.
//

#ifndef PARSE_BYTECODE_COMPILETOBYTECODE_H
#define PARSE_BYTECODE_COMPILETOBYTECODE_H

#include <string>
#include <vector>
#include "Arithmetic.h"
#include "types.h"

std::vector<u1> compileToBytecode(const std::vector<token> &input);

#endif //PARSE_BYTECODE_COMPILETOBYTECODE_H
