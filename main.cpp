#include <iostream>
#include <vector>
#include "Matrix.h"
#include "Rotate4D.h"
#include "RenderChain.h"
#include "Primitives/HyperCube.h"

void pause() {
    std::string temp;
    std::getline(std::cin, temp);
}

int main() {
    /*Matrix a(3, 3);
    Matrix b(3, 3);

    for (int y = 0; y < a.getHeight(); ++y) {
        for (int x = 0; x < a.getWidth(); ++x) {
            a(y, x) = x + y;
        }
    }

    for (int y = 0; y < b.getHeight(); ++y) {
        for (int x = 0; x < b.getWidth(); ++x) {
            b(y, x) = x - y - 1;
        }
    }
    std::cout << a.toString() << "\n";
    std::cout << b.toString() << "\n";
    std::cout << (a * b).toString() << "\n";
    pause(); */

    RenderChain rChain(4);

    HyperCube  hyCube;
    Primitive newCube = Rotate4D::XY(hyCube, 57);
    newCube = Rotate4D::XU(newCube, 32);
    newCube = Rotate4D::ZU(newCube, 46);

    std::vector<Matrix> oldPoints = rChain.compute(hyCube);
    std::vector<Matrix> newPoints = rChain.compute(newCube);

    for (auto & i : newPoints) {
        std::cout << i << "\n";
    }
    
    return 0;
}
