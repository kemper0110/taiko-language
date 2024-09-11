//
// Created by Danil on 25.08.2024.
//

#include "../include/ClassFile/bytecode.h"
#include "../include/types.h"
#include "Expression/Arithmetic.h"
#include <concepts>
#include <stack>
#include <string>
#include <variant>
#include <map>
#include <any>
#include <vector>
#include <fstream>
#include <iostream>
#include "../include/utils.h"

u2 swap_endian(u2 value) {
    return (value >> 8) | (value << 8);
}

u4 swap_endian(u4 value) {
    return ((value >> 24) & 0x000000FF) |
           ((value >> 8) & 0x0000FF00) |
           ((value << 8) & 0x00FF0000) |
           ((value << 24) & 0xFF000000);
}

u1 read_u1(std::istream &is) {
    u1 byte;
    is.read(reinterpret_cast<char *>(&byte), 1);
    return byte;
}

u2 read_u2(std::istream &is) {
    u2 word;
    is.read(reinterpret_cast<char *>(&word), 2);
    return swap_endian(word);
}

u4 read_u4(std::istream &is) {
    u4 dword;
    is.read(reinterpret_cast<char *>(&dword), 4);
    return swap_endian(dword);
}

void write(std::ostream& out, u1 byte) {
    out.write(reinterpret_cast<char *>(&byte), 1);
}

void write(std::ostream& out, u2 word) {
    word = swap_endian(word);
    out.write(reinterpret_cast<char *>(&word), 2);
}

void write(std::ostream& out, u4 dword) {
    dword = swap_endian(dword);
    out.write(reinterpret_cast<char *>(&dword), 4);
}