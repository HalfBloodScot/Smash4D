#include <iostream>
#include <vector>
#include "Bud.h"
#include "Node.h"

std::vector<int> testnums;

int main() {
    for (int i = 0; i < 10; ++i) {
        testnums.push_back(i);
    }

    std::vector<Node<int> > list = Bud<int>::nearestNeighbours(testnums);
    
    for (auto& i : list) {
        std::cout << "Position: " << i.position << "\n";
        for (auto& n : i.neighbours) {
            std::cout << *n << "\n";
        }
        std::cout << "\n";
    }
    
    return 0;
}
