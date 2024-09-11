//
// Created by Danil on 27.08.2024.
//

#ifndef PARSE_BYTECODE_CONSTANTPOOL_H
#define PARSE_BYTECODE_CONSTANTPOOL_H

#include <string>
#include <variant>
#include <vector>
#include <istream>
#include <ostream>
#include "utils.h"

enum ConstantPoolTag : u1 {
    CONSTANT_Utf8 = 1,
    CONSTANT_Integer = 3,
    CONSTANT_Float = 4,
    CONSTANT_Long = 5,
    CONSTANT_Double = 6,
    CONSTANT_Class = 7,
    CONSTANT_String = 8,
    CONSTANT_Fieldref = 9,
    CONSTANT_Methodref = 10,
    CONSTANT_InterfaceMethodref = 11,
    CONSTANT_NameAndType = 12,
    CONSTANT_MethodHandle = 15,
    CONSTANT_MethodType = 16,
    CONSTANT_InvokeDynamic = 18,
};
struct class_info {
    u2 name_index;
};
struct fieldref_info {
    u2 class_index;
    u2 name_and_type_index;
};
struct methodref_info {
    u2 class_index;
    u2 name_and_type_index;
};
struct interfaceMethodref_info {
    u2 class_index;
    u2 name_and_type_index;
};
struct string_info {
    u2 string_index;
};
struct integer_info {
    u4 value;
};
struct float_info {
    u4 value;
};
struct nameAndType_info {
    u2 name_index;
    u2 descriptor_index;
};
struct utf8_info {
    std::string str;
};
struct methodHandle_info {
    u1 reference_kind;
    u2 reference_index;
};
struct methodType_info {
    u2 descriptor_index;
};
struct invokeDynamic_info {
    u2 bootstrap_method_attr_index;
    u2 name_and_type_index;
};


struct cp_info : std::variant<
        class_info, fieldref_info, methodref_info, interfaceMethodref_info, string_info, integer_info, float_info,
        nameAndType_info, utf8_info, methodHandle_info, methodType_info, invokeDynamic_info
> {
    static cp_info fromStream(std::istream &input);

    void saveToStream(std::ostream &output) const;
};


#endif //PARSE_BYTECODE_CONSTANTPOOL_H
