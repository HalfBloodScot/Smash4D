#include "Vertex.h"

int Vertex::updateNearestNeighbours(int numNeighs, std::vector<Vector>& vertices) {
    maxNeighs = numNeighs;
}

bool Vertex::nearerThanNeighbour(const Vertex& vertex) const {
    if (neighbours.size() < maxNeighs) {
        return true;
    }
    for (auto& i : neighbours) {
        if (vertex.normSquare() < i->normSquare()) {
            return true;
        }
    }
    return false;
}
