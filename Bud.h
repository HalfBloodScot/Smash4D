#ifndef BUD_H_INCLUDED
#define BUD_H_INCLUDED

#include <vector>
#include <cmath>
#include <algorithm>
#include "Node.h"

template <typename T>
struct Bud {
    static std::vector<Node<T> > nearestManhattenNeighbours(std::vector<T>&, unsigned numNeighs = 1);
    static std::vector<Node<T> > nearestNeighbours(std::vector<T>&, unsigned numNeighs = 1);
};

template <typename T>
std::vector<Node<T> > Bud<T>::nearestManhattenNeighbours(std::vector<T>& vertices, unsigned numNeighs) {
    std::vector<Node<T> > nodes;
    nodes.resize(vertices.size());
    for (unsigned i = 0; i < vertices.size(); ++i) {
        nodes[i].position = vertices[i];
    }
    for (unsigned i = 0; i < nodes.size(); ++i) {
        for (unsigned k = 0; k < vertices.size(); ++k) {
            //Make sure we don't count self as a neighbour.
            if (i != k) {
                nodes[i].neighbours.push_back(&vertices[k]);
                while (nodes[i].neighbours.size() > numNeighs) {
                    nodes[i].purgeManhattenFurthest();
                }
            }
        }
    }
    return nodes;
}

template <typename T>
std::vector<Node<T> > Bud<T>::nearestNeighbours(std::vector<T>& vertices, unsigned numNeighs) {
    std::vector<Node<T> > nodes;
    nodes.resize(vertices.size());
    for (unsigned i = 0; i < vertices.size(); ++i) {
        nodes[i].position = vertices[i];
    }
    for (unsigned i = 0; i < nodes.size(); ++i) {
        for (unsigned k = 0; k < vertices.size(); ++k) {
            //Make sure we don't count self as a neighbour.
            if (i != k) {
                nodes[i].neighbours.push_back(&vertices[k]);
                while (nodes[i].neighbours.size() > numNeighs) {
                    nodes[i].purgeFurthest();
                }
            }
        }
    }
    return nodes;
}

#endif //BUD_H_INCLUDED
