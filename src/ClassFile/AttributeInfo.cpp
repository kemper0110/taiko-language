//
// Created by Danil on 27.08.2024.
//

#include "ClassFile/AttributeInfo.h"

attribute_info attribute_info::fromStream(std::istream &input) {
    attribute_info s{};
    s.attribute_name_index = read_u2(input);
    const auto attribute_length = read_u4(input);
    s.info.resize(attribute_length);
    input.read(reinterpret_cast<char *>(s.info.data()), attribute_length);
    return s;
}

void attribute_info::saveToStream(std::ostream &output) const {
    write(output, this->attribute_name_index);
    write(output, (u4) this->info.size());
    output.write(reinterpret_cast<const char *>(this->info.data()), (u4) this->info.size());
}
