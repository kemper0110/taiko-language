//
// Created by Danil on 27.08.2024.
//

#include "ClassFile/FieldInfo.h"

field_info field_info::fromStream(std::istream &input) {
    field_info s{};
    s.access_flags = read_u2(input);
    s.name_index = read_u2(input);
    s.descriptor_index = read_u2(input);
    u2 attributes_count = read_u2(input);
    s.attributes.reserve(attributes_count);
    for (int i = 0; i < attributes_count; ++i)
        s.attributes.push_back(attribute_info::fromStream(input));
    return s;
}

void field_info::saveToStream(std::ostream &output) const {
    write(output, this->access_flags);
    write(output, this->name_index);
    write(output, this->descriptor_index);
    write(output, (u2) this->attributes.size());
    for (const auto &attribute: this->attributes)
        attribute.saveToStream(output);
}
