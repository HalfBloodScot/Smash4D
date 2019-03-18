#ifndef RENDERCHAIN_H_INCLUDED
#define RENDERCHAIN_H_INCLUDED

#include <vector>
#include <stdexcept>
#include "Matrix.h"

class RenderChain {
public:
    RenderChain(int dimension);
    void applyKalibrationMatrix(const Matrix&);
    Matrix getKalibrationMatrix() const;
    Matrix compute(const Matrix&) const;
protected:
    std::vector<Matrix> matrices;
};

#endif //RENDERCHAIN_H_INCLUDED
