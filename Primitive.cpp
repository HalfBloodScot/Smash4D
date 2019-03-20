//
// Created by Bryn McKerracher on 17/03/2019.
//

#include "Primitive.h"

std::string Primitive::toString() const {
    std::string output;
    for (auto& i : vertices) {
        output += i.toString() + ",\n";
    }
    return output;
}

void Primitive::transform(const Matrix& matrix) {
    for (auto& i : vertices) {
        i = matrix * i;
    }
}

Matrix& Primitive::operator()(int num) {
    return vertices[num];
}

const Matrix& Primitive::operator()(int num) const {
    return vertices[num];
}

int Primitive::vertexCount() const {
    return vertices.size();
}

void Primitive::translate(const Matrix &matrix) {
    for (auto & i : vertices) {
        i.translate(matrix);
    }
}

void Primitive::findVertexNeighbours() {
    //Remove current links.
    for (auto& i : vertices) {
        i.parent = nullptr;
        i.neighbours.clear();
    }
    //Update links
    Vertex* current = &vertices.front();
    for (auto& i : vertices) {
        
    }
}
