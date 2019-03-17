//
// Created by Bryn McKerracher on 17/03/2019.
//

#include "Matrix.h"

Matrix::Matrix() :
    Matrix(1)
{}

Matrix::Matrix(int _height, int _width):
    height(_height), width(_width)
{
    entries.resize(_height * _width, 0);
}

double& Matrix::operator()(int y, int x) {
    return entries[x + y * width];
}

const double& Matrix::operator()(int y, int x) const {
    return entries[x + y * width];
}

int Matrix::getHeight() const {
    return height;
}

int Matrix::getWidth() const {
    return width;
}

Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
    if (lhs.width != rhs.height) {
        throw std::invalid_argument("Multiply: Matrix dimensions do not match!");
    }
    Matrix product(lhs.height, rhs.width);
    for (int y = 0; y < product.height; ++y) {
        for (int x = 0; x < product.width; ++x) {
            double dotprod = 0;
            for (int i = 0; i < lhs.width; ++i) {
                dotprod += lhs(y, i) * rhs(i, x);
            }
            product(y, x) = dotprod;
        }
    }
    return product;
}

std::ostream& operator<<(std::ostream& ostream, const Matrix& transform) {
    ostream << transform.toString();
}

std::string Matrix::toString() const {
    std::stringstream stream;
    for (int y = 0; y < height; ++y) {
        stream << "[";
        for (int x = 0; x < width; ++x) {
            stream << operator()(y, x);
            if (x == width - 1) {
                stream << "]";
            }
            else {
                stream << " ";
            }
        }
        stream << "\n";
    }
    return stream.str();
}
