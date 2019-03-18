//
// Created by Bryn McKerracher on 17/03/2019.
//

#include "Rotate4D.h"

Matrix Rotate4D::XY(const Matrix &matrix, double angle) {

}

Matrix Rotate4D::ZU(const Matrix &, double angle) {
    angle *= 3.141592 / 180.f;
    Matrix rzu(5, 5);
    rzu(0, 0) = 1;
    rzu(1, 1) = 1;
    rzu(2, 2) = cos(angle);
    rzu(3, 3) = cos(angle);
    rzu(4, 4) = 1;
    rzu(2, 3) = -sin(angle);
    rzu(3, 2) = sin(angle);
}