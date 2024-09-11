//
// Created by Danil on 27.08.2024.
//

#include <iostream>
#include "ClassFile/MethodInfo.h"

method_info method_info::fromStream(std::istream &input) {
    method_info s{};
    s.access_flags = read_u2(input);
//    for (const auto &acc: {
//            ACC_PUBLIC,
//            ACC_PRIVATE,
//            ACC_PROTECTED,
//            ACC_STATIC,
//            ACC_FINAL,
//            ACC_SYNCHRONIZED,
//            ACC_BRIDGE,
//            ACC_VARARGS,
//            ACC_NATIVE,
//            ACC_ABSTRACT,
//            ACC_STRICT,
//            ACC_SYNTHETIC,
//    }) {
//        if(s.access_flags & acc) {
//            std::cout << access_flag_to_string(s.access_flags & acc) << "\n";
//        }
//    }
    s.name_index = read_u2(input);
    s.descriptor_index = read_u2(input);
    u2 attributes_count = read_u2(input);
    s.attributes.reserve(attributes_count);
    for (int i = 0; i < attributes_count; ++i)
        s.attributes.push_back(attribute_info::fromStream(input));
    return s;
}

void method_info::saveToStream(std::ostream &output) const {
    write(output, this->access_flags);
    write(output, this->name_index);
    write(output, this->descriptor_index);
    write(output, (u2) this->attributes.size());
    for (const auto &attribute: this->attributes)
        attribute.saveToStream(output);
}
