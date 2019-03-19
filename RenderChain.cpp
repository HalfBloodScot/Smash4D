#include "RenderChain.h"

RenderChain::RenderChain(int dimension) {
    for (int i = 0; i < dimension && dimension - i >= 3; ++i) {
        matrices.push_back(Matrix::Identity(dimension - i, dimension + 1 - i));
    }
    matrices.push_back(Matrix(3, 3));
    matrices.back()(0, 0) = 1;
    matrices.back()(1, 1) = 1;
}

void RenderChain::applyKalibrationMatrix(const Matrix& matrix) {
    matrices.back() = matrix;
}

Matrix RenderChain::getKalibrationMatrix() const {
    return matrices.back();
}

Matrix RenderChain::compute(const Matrix& matrix) const {
    if (matrix.getHeight() != matrices.front().getWidth())  {
        throw std::invalid_argument("Compute: Matrix dimensions do not match!");
    }
    Matrix transform = matrix;
    for (auto& i : matrices) {
        transform = i * transform;
    }
    return transform;
}

std::vector<Matrix> RenderChain::compute(const Primitive& prim) const {
    std::vector<Matrix> transforms;
    for (int i = 0; i < prim.vertexCount(); ++i) {
        transforms.push_back(compute(prim(i)));
    }
    return transforms;
}
