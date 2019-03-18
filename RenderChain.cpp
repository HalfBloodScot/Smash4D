#include "RenderChain.h"

RenderChain::RenderChain(int dimension) {
    for (int i = 0; i < dimension; ++i) {
        matrices.push_back(Matrix::Identity(dimension - i, dimension + 1 - i));
    }
    matrices.push_back(Matrix(3, 3));
}

void RenderChain::applyKalibrationMatrix(const Matrix& matrix) {
    matrices.back() = matrix;
}

Matrix RenderChain::getKalibrationMatrix() const {
    return matrices.back();
}

Matrix RenderChain::compute(const Matrix& matrix) const {
    if (matrix.getHeight() != matrices.front().getWidth())  {
        throw std::invalid_argument("Compute: Matrices dimensions do not match!");
    }
    Matrix transform = matrix;
    for (auto& i : matrices) {
        transform = i * transform;
    }
    return transform;
}
