//
// Created by Danil on 27.08.2024.
//

#include "ClassFile/ConstantPool.h"

cp_info cp_info::fromStream(std::istream &input) {
    u1 tag = read_u1(input);
    switch ((ConstantPoolTag) tag) {
        case CONSTANT_Class: {
            return {
                    class_info{read_u2(input)}
            };
        }
        case CONSTANT_Methodref: {
            auto class_index = read_u2(input);
            auto name_and_type_index = read_u2(input);
            return {
                    methodref_info{class_index, name_and_type_index}
            };
        }
        case CONSTANT_NameAndType: {
            auto name_index = read_u2(input);
            auto descriptor_index = read_u2(input);
            return {
                    nameAndType_info{name_index, descriptor_index}
            };
        }
        case CONSTANT_Utf8: {
            const auto length = read_u2(input);
            std::string str;
            str.resize(length);
            input.read(reinterpret_cast<char *>(str.data()), length);
            return {
                    utf8_info{std::move(str)}
            };
        }
        case CONSTANT_String: {
            return {
                    string_info{read_u2(input)}
            };
        }
        case CONSTANT_Integer: {
            return {
                    integer_info{read_u4(input)}
            };
        }
        case CONSTANT_Float: {
            return {
                    float_info{read_u4(input)}
            };
        }
        case CONSTANT_Fieldref: {
            auto class_index = read_u2(input);
            auto name_and_type_index = read_u2(input);
            return {
                    fieldref_info{class_index, name_and_type_index}
            };
        }
        case CONSTANT_MethodType: {
            return {
                    methodType_info{read_u2(input)}
            };
        }
        case CONSTANT_MethodHandle:
        case CONSTANT_InvokeDynamic:
        case CONSTANT_InterfaceMethodref:
        case CONSTANT_Long:
        case CONSTANT_Double:
            break;
    }
    // заглушка
    return {
            utf8_info{""}
    };
}


void cp_info::saveToStream(std::ostream &output) const {
    struct Visitor {
        std::ostream &output;

        explicit Visitor(std::ostream &output) : output(output) {}

        void operator()(class_info info) {
            write(output, ConstantPoolTag::CONSTANT_Class);
            write(output, info.name_index);
        }

        void operator()(fieldref_info info) {
            write(output, ConstantPoolTag::CONSTANT_Fieldref);
            write(output, info.class_index);
            write(output, info.name_and_type_index);
        }

        void operator()(methodref_info info) {
            write(output, ConstantPoolTag::CONSTANT_Methodref);
            write(output, info.class_index);
            write(output, info.name_and_type_index);
        }

        void operator()(interfaceMethodref_info info) {
            write(output, ConstantPoolTag::CONSTANT_InterfaceMethodref);
            write(output, info.class_index);
            write(output, info.name_and_type_index);
        }

        void operator()(string_info info) {
            write(output, ConstantPoolTag::CONSTANT_String);
            write(output, info.string_index);
        }

        void operator()(integer_info info) {
            write(output, ConstantPoolTag::CONSTANT_Integer);
            write(output, info.value);
        }

        void operator()(float_info info) {
            write(output, ConstantPoolTag::CONSTANT_Float);
            write(output, info.value);
        }

        void operator()(nameAndType_info info) {
            write(output, ConstantPoolTag::CONSTANT_NameAndType);
            write(output, info.name_index);
            write(output, info.descriptor_index);
        }

        void operator()(const utf8_info &info) {
            write(output, ConstantPoolTag::CONSTANT_Utf8);
            output.write(info.str.data(), (u2) info.str.size());
        }

        void operator()(methodHandle_info info) {
            write(output, ConstantPoolTag::CONSTANT_MethodHandle);
            write(output, info.reference_kind);
            write(output, info.reference_index);
        }

        void operator()(methodType_info info) {
            write(output, ConstantPoolTag::CONSTANT_MethodType);
            write(output, info.descriptor_index);
        }

        void operator()(invokeDynamic_info info) {
            write(output, ConstantPoolTag::CONSTANT_InvokeDynamic);
            write(output, info.bootstrap_method_attr_index);
            write(output, info.name_and_type_index);
        }
    } visitor(output);
    std::visit(visitor, *this);
}

