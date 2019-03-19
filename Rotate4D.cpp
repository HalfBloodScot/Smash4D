//
// Created by Bryn McKerracher on 17/03/2019.
//

#include "Rotate4D.h"

Matrix Rotate4D::XY(const Matrix &matrix, double angle) {
    angle *= 3.141592 / 180.f;
    Matrix rxy(5, 5);
    rxy(0, 0) = cos(angle);
    rxy(0, 1) = sin(angle);
    rxy(1, 0) = -sin(angle);
    rxy(1, 1) = cos(angle);
    rxy(2, 2) = 1;
    rxy(3, 3) = 1;
    rxy(4, 4) = 1;
    return rxy * matrix;
}

Matrix Rotate4D::YZ(const Matrix &matrix, double angle) {
    angle *= 3.141592 / 180.f;
    Matrix ryz(5, 5);
    ryz(0, 0) = 1;
    ryz(1, 1) = cos(angle);
    ryz(1, 2) = sin(angle);
    ryz(2, 1) = -sin(angle);
    ryz(2, 2) = cos(angle);
    ryz(3, 3) = 1;
    ryz(4, 4) = 1;
    return ryz * matrix;
}

Matrix Rotate4D::XZ(const Matrix &matrix, double angle) {
    angle *= 3.141592 / 180.f;
    Matrix rxz(5, 5);
    rxz(0, 0) = cos(angle);
    rxz(0, 2) = -sin(angle);
    rxz(1, 1) = 1;
    rxz(2, 0) = sin(angle);
    rxz(2, 2) = cos(angle);
    rxz(3, 3) = 1;
    rxz(4, 4) = 1;
    return rxz * matrix;
}

Matrix Rotate4D::XU(const Matrix &matrix, double angle) {
    angle *= 3.141592 / 180.f;
    Matrix rxu(5, 5);
    rxu(0, 0) = cos(angle);
    rxu(0, 3) = sin(angle);
    rxu(1, 1) = 1;
    rxu(2, 2) = 1;
    rxu(3, 0) = -sin(angle);
    rxu(3, 3) = cos(angle);
    rxu(4, 4) = 1;
    return rxu * matrix;
}

Matrix Rotate4D::YU(const Matrix &matrix, double angle) {
    angle *= 3.141592 / 180.f;
    Matrix ryu(5, 5);
    ryu(0, 0) = 1;
    ryu(1, 1) = 1;
    ryu(1, 3) = -sin(angle);
    ryu(2, 2) = 1;
    ryu(3, 1) = sin(angle);
    ryu(3, 3) = cos(angle);
    ryu(4, 4) = 1;
    return ryu * matrix;
}

Matrix Rotate4D::ZU(const Matrix &matrix, double angle) {
    angle *= 3.141592 / 180.f;
    Matrix rzu(5, 5);
    rzu(0, 0) = 1;
    rzu(1, 1) = 1;
    rzu(2, 2) = cos(angle);
    rzu(3, 3) = cos(angle);
    rzu(4, 4) = 1;
    rzu(2, 3) = -sin(angle);
    rzu(3, 2) = sin(angle);
    return rzu * matrix;
}
