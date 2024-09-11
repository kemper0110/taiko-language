//
// Created by Danil on 27.08.2024.
//

#ifndef PARSE_BYTECODE_CLASSFILE_H
#define PARSE_BYTECODE_CLASSFILE_H

#include <istream>
#include <variant>
#include <vector>
#include "utils.h"
#include "ConstantPool.h"

#include "AttributeInfo.h"
#include "FieldInfo.h"
#include "MethodInfo.h"

struct ClassFile {
    u4 magic = 0xCAFEBABE;
    u2 minor_version = 0x00;
    u2 major_version = 65;
    std::vector<cp_info> constant_pool;
    u2 access_flags;
    u2 this_class;
    u2 super_class;
    std::vector<u2> interfaces;
    std::vector<field_info> fields;
    std::vector<method_info> methods;
    std::vector<attribute_info> attributes;

    enum AccessFlags {
        ACC_PUBLIC = 0x0001, //	Declared public; may be accessed from outside its package.
        ACC_FINAL = 0x0010, //	Declared final; no subclasses allowed.
        ACC_SUPER = 0x0020, //	Treat superclass methods specially when invoked by the invokespecial instruction.
        ACC_INTERFACE = 0x0200, //	Is an interface, not a class.
        ACC_ABSTRACT = 0x0400, //	Declared abstract; must not be instantiated.
        ACC_SYNTHETIC = 0x1000, //	Declared synthetic; not present in the source code.
        ACC_ANNOTATION = 0x2000, //	Declared as an annotation type.
        ACC_ENUM = 0x4000, //	Declared as an enum type.
    };

    static ClassFile fromStream(std::istream &input);

    void saveToStream(std::ostream &output) const;
};


#endif //PARSE_BYTECODE_CLASSFILE_H
