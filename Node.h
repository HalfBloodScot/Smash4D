#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <vector>
#include <cmath>

template <typename T>
struct Node {
    T position;
    std::vector<T*> neighbours;
    void purgeManhattenFurthest();
    void purgeFurthest();
};

template <typename T>
void Node<T>::purgeManhattenFurthest() {
    unsigned index = 0;
    double maxDist = 0;
    for (unsigned i = 0; i < neighbours.size(); ++i) {
        const double dist = abs(position - *neighbours[i]);
        if (dist > maxDist) {
            index = i;
            maxDist = dist;
        }
    }
    neighbours.erase(neighbours.begin() + index);
}


template <typename T>
void Node<T>::purgeFurthest() {
    unsigned index = 0;
    double maxDist = 0;
    for (unsigned i = 0; i < neighbours.size(); ++i) {
        const double dist = (position -  *neighbours[i]).norm();
        if (dist > maxDist) {
            index = i;
            maxDist = dist;
        }
    }
    neighbours.erase(neighbours.begin() + index);
}

#endif //NODE_H_INCLUDED
