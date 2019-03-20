#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

#include <vector>
#include "Matrix.h"

class Vertex : public Matrix {
public:
    friend class Primitive;
    int updateNearestNeighbours(int numNeighs, std::vector<Vertex>& vertices);
 protected:
    bool nearerThanNeighbour(const Vertex&) const;
    std::vector<Vertex*> neighbours;
    Vertex* parent = nullptr;
    int maxNeighs = 0;
};

#endif //VERTEX_H_INCLUDED
