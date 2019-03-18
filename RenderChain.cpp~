#include "RenderChain.h"

RenderChain::RenderChain(int dimension) {
    for (int i = 0; i < dimension; ++i) {
        matrices.push_back(Matrix::Identity(dimension - i, dimension - i + 1));
    }
}
