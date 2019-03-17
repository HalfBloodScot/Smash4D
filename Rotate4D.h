//
// Created by Bryn McKerracher on 17/03/2019.
//

#ifndef SMASH4D_ROTATE_H
#define SMASH4D_ROTATE_H

#include "Matrix.h"
#include <cmath>

struct Rotate4D {
    static Matrix XY(const Matrix&, double angle);
    static Matrix ZU(const Matrix&, double angle);
};


#endif //SMASH4D_ROTATE_H
