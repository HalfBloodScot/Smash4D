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

Matrix operator*(const double& scalar, const Matrix& rhs) {
    Matrix scaled = rhs;
    for (auto& i : scaled.entries) {
        i *= scalar;
    }
    return scaled;
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

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
    if (lhs.width != rhs.width or lhs.height != rhs.height) {
        throw std::invalid_argument("Add: Matrix dimensions are not equal!");
    }
    Matrix sum(lhs.height, lhs.width);
    for (unsigned i = 0; i < sum.entries.size(); ++i) {
        sum.entries[i] = lhs.entries[i] + rhs.entries[i];
    }
    return sum;
}

Matrix operator-(const Matrix& lhs, const Matrix& rhs) {
    return lhs + (-1 * rhs);
}

bool operator<(const Matrix& lhs, const Matrix& rhs) {
    return lhs.normSquare() < rhs.normSquare();
}

bool operator>(const Matrix& lhs, const Matrix& rhs) {
    return lhs.normSquare() > rhs.normSquare();
}

std::ostream& operator<<(std::ostream& ostream, const Matrix& transform) {
    return (ostream << transform.toString());
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

void Matrix::clean() {
    for (auto & i : entries) {
        if (fabs(i) < 0.000001) {
            i = 0;
        }
    }
}

void Matrix::translate(const Matrix &matrix) {
    if (matrix.getHeight() != this->getHeight()) {
        throw std::invalid_argument("Translate: Matrix dimensions not aligned!");
    }
    if (matrix.getWidth() == 1) {
        for (int y = 0; y < matrix.getHeight(); ++y) {
            operator()(width - 1, y) += matrix(y);
        }
    }
}

double Matrix::norm() const {
    return sqrt(normSquare());
}

double Matrix::normSquare() const {
    double normSq = 0;
    for (auto & i : entries) {
        normSq += i * i;
    }
    return normSq;
}

Matrix Matrix::Identity(int height, int width) {
    Matrix identity(height, width);
    for (int i = 0; i < height && i < width; ++i) {
        identity(i, i) = 1;
    }
    return identity;
}
