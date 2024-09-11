//
// Created by Danil on 27.08.2024.
//

#ifndef PARSE_BYTECODE_FIELDINFO_H
#define PARSE_BYTECODE_FIELDINFO_H

#include <istream>
#include <ostream>
#include <vector>
#include "utils.h"

#include "AttributeInfo.h"

struct field_info {
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    std::vector<attribute_info> attributes;

    static field_info fromStream(std::istream &input);

    void saveToStream(std::ostream &output) const;
};


#endif //PARSE_BYTECODE_FIELDINFO_H
