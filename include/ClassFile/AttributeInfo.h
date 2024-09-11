//
// Created by Danil on 27.08.2024.
//

#ifndef PARSE_BYTECODE_ATTRIBUTEINFO_H
#define PARSE_BYTECODE_ATTRIBUTEINFO_H

#include <istream>
#include <ostream>
#include <vector>
#include "utils.h"

struct attribute_info {
    u2 attribute_name_index;
    std::vector<u1> info;

    static attribute_info fromStream(std::istream &input);

    void saveToStream(std::ostream &output) const;
};

#endif //PARSE_BYTECODE_ATTRIBUTEINFO_H
