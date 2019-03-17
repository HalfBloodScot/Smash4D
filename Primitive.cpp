//
// Created by Bryn McKerracher on 17/03/2019.
//

#include "Primitive.h"

std::string Primitive::toString() const {
    std::string output;
    for (auto& i : vertices) {
        output += i.toString() + ",\n";
    }
    return output;
}