#include <iostream>
#include "Matrix.h"

void pause() {
    std::string temp;
    std::getline(std::cin, temp);
}

int main() {
    Matrix a(3, 3);
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

    pause();
    return 0;
}