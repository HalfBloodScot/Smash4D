//
// Created by Bryn McKerracher on 17/03/2019.
//

#ifndef SMASH4D_ROTATE_H
#define SMASH4D_ROTATE_H

#include "Matrix.h"
#include "Primitive.h"
#include <cmath>

struct Rotate4D {
    static Matrix XY(const Matrix&, double angle);
    static Matrix YZ(const Matrix&, double angle);
    static Matrix XZ(const Matrix&, double angle);
    static Matrix XU(const Matrix&, double angle);
    static Matrix YU(const Matrix&, double angle);
    static Matrix ZU(const Matrix&, double angle);
    static Primitive XY(const Primitive&, double angle);
    static Primitive XU(const Primitive&, double angle);
    static Primitive ZU(const Primitive&, double angle);
};

#endif //SMASH4D_ROTATE_H
