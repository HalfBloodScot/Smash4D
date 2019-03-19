//
// Created by Bryn McKerracher on 17/03/2019.
//

#ifndef SMASH4D_TRANSFORM_H
#define SMASH4D_TRANSFORM_H

#include <vector>
#include <sstream>
#include <ostream>
#include <cmath>
#include <stdexcept>

class Matrix {
public:
    Matrix();
    Matrix(int _height, int _width = 1);
    double& operator()(int y, int x = 0);
    const double& operator()(int y, int x = 0) const;
    int getHeight() const;
    int getWidth() const;
    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);
    friend std::ostream& operator<<(std::ostream&, const Matrix&);
    std::string toString() const;
    void clean();
    void translate(const Matrix&);

    static Matrix Identity(int height, int width);
protected:
    int height, width;
    std::vector<double> entries;
};

#endif //SMASH4D_TRANSFORM_H
