#ifndef RENDERCHAIN_H_INCLUDED
#define RENDERCHAIN_H_INCLUDED

#include <vector>
#include "Matrix.h"

class RenderChain {
public:
    RenderChain(int dimension);
protected:
    std::vector<Matrix> matrices;
};

#endif //RENDERCHAIN_H_INCLUDED
