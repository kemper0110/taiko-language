//
// Created by Danil on 27.08.2024.
//

#include "ClassFile/ClassFile.h"

ClassFile ClassFile::fromStream(std::istream &input) {
    ClassFile cf{};
    cf.magic = read_u4(input);
    cf.minor_version = read_u2(input);
    cf.major_version = read_u2(input);

    u2 constant_pool_count = read_u2(input);
    cf.constant_pool.reserve(constant_pool_count - 1); // !
    for (int i = 0; i < constant_pool_count - 1; ++i) // !!
        cf.constant_pool.push_back(cp_info::fromStream(input));

    cf.access_flags = read_u2(input);
    cf.this_class = read_u2(input);
    cf.super_class = read_u2(input);

    u2 interfaces_count = read_u2(input);
    cf.interfaces.reserve(interfaces_count);
    for (int i = 0; i < interfaces_count; ++i)
        cf.interfaces.push_back(read_u2(input));

    u2 fields_count = read_u2(input);
    cf.fields.reserve(fields_count);
    for (int i = 0; i < fields_count; ++i)
        cf.fields.push_back(field_info::fromStream(input));

    u2 methods_count = read_u2(input);
    cf.methods.reserve(methods_count);
    for (int i = 0; i < methods_count; ++i)
        cf.methods.push_back(method_info::fromStream(input));

    u2 attributes_count = read_u2(input);
    cf.attributes.reserve(attributes_count);
    for (int i = 0; i < attributes_count; ++i)
        cf.attributes.push_back(attribute_info::fromStream(input));

    return cf;
}

void ClassFile::saveToStream(std::ostream &output) const {
    write(output, magic);
    write(output, minor_version);
    write(output, major_version);

    write(output, (u2) (constant_pool.size() + 1));
    for (const auto &info: constant_pool)
        info.saveToStream(output);

    write(output, this->access_flags);
    write(output, this->this_class);
    write(output, this->super_class);

    write(output, (u2) this->interfaces.size());
    for (const auto &interface: this->interfaces)
        write(output, interface);

    write(output, (u2) this->fields.size());
    for (const auto &field: this->fields)
        field.saveToStream(output);

    write(output, (u2) this->methods.size());
    for (const auto &method: this->methods)
        method.saveToStream(output);

    write(output, (u2) this->attributes.size());
    for (const auto &attribute: this->attributes)
        attribute.saveToStream(output);
}
