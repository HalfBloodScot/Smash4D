//
// Created by Bryn McKerracher on 17/03/2019.
//
#ifndef SMASH4D_PRIMITIVE_H
#define SMASH4D_PRIMITIVE_H

#include <vector>
#include "Matrix.h"

class Primitive {
public:
    std::string toString() const;
    void transform(const Matrix&);
    Matrix& operator()(int num);
    const Matrix& operator()(int num) const;
    int vertexCount() const;
protected:
    std::vector<Matrix> vertices;
};


#endif //SMASH4D_PRIMITIVE_H
