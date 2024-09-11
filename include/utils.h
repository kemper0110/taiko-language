//
// Created by Danil on 25.08.2024.
//

#ifndef PARSE_BYTECODE_UTILS_H
#define PARSE_BYTECODE_UTILS_H

#include "types.h"

u2 swap_endian(u2 value);
u4 swap_endian(u4 value);

u1 read_u1(std::istream& is);
u2 read_u2(std::istream& is);
u4 read_u4(std::istream& is);
void write(std::ostream& out, u1 byte);
void write(std::ostream& out, u2 word);
void write(std::ostream& out, u4 dword);

#endif //PARSE_BYTECODE_UTILS_H
