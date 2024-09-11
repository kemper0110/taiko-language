//
// Created by Danil on 30.08.2024.
//

#include "ClassFile/CodeAttribute.h"

Code_attribute Code_attribute::fromStream(std::istream &input) {
    Code_attribute ca;

    ca.attribute_name_index = read_u2(input);
    ca.attribute_length = read_u4(input);
    ca.max_stack = read_u2(input);
    ca.max_locals = read_u2(input);
    ca.code_length = read_u2(input);
    ca.code.resize(ca.code_length);
    input.read(reinterpret_cast<char *>(ca.code.data()), ca.code_length);
    ca.exception_table_length = read_u2(input);
    ca.exception_table.resize(ca.exception_table_length);
    for (auto &exception: ca.exception_table) {
        exception.start_pc = read_u2(input);
        exception.end_pc = read_u2(input);
        exception.handler_pc = read_u2(input);
        exception.catch_type = read_u2(input);
    }
    ca.attributes_count = read_u2(input);
    ca.attributes.reserve(ca.attributes_count);
    for (int i = 0; i < ca.attributes_count; ++i)
        ca.attributes.push_back(attribute_info::fromStream(input));

    return ca;
}

void Code_attribute::saveToStream(std::ostream &output) const {
    write(output, this->attribute_name_index);
    write(output, this->attribute_length);
    write(output, this->max_stack);
    write(output, this->max_locals);
    write(output, this->code_length);
    output.write(reinterpret_cast<const char *>(this->code.data()), this->code_length);
    write(output, this->exception_table_length);
    for (const auto &exception: this->exception_table) {
        write(output, exception.start_pc);
        write(output, exception.end_pc);
        write(output, exception.handler_pc);
        write(output, exception.catch_type);
    }
    write(output, this->attributes_count);
    for (const auto &attribute: this->attributes)
        attribute.saveToStream(output);
}
