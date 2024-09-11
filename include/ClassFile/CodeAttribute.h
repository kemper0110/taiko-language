//
// Created by Danil on 30.08.2024.
//

#ifndef PARSE_BYTECODE_CODEATTRIBUTE_H
#define PARSE_BYTECODE_CODEATTRIBUTE_H

#include <vector>
#include <istream>
#include <ostream>
#include "AttributeInfo.h"

struct Code_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 max_stack;
    u2 max_locals;
    u4 code_length;
    std::vector<u1> code;
    u2 exception_table_length;
    struct exception {
        u2 start_pc;
        u2 end_pc;
        u2 handler_pc;
        u2 catch_type;
    };
    std::vector<exception> exception_table;
    u2 attributes_count;
    std::vector<attribute_info> attributes;

    static Code_attribute fromStream(std::istream &input);

    void saveToStream(std::ostream &output) const;
};

#endif //PARSE_BYTECODE_CODEATTRIBUTE_H
