#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Matrix.h"
#include "Rotate4D.h"
#include "RenderChain.h"
#include "Renderer.h"
#include "Primitives/HyperCube.h"

void pause() {
    std::string temp;
    std::getline(std::cin, temp);
}

int main() {
    RenderChain rChain(4);

    HyperCube  hyCube;
    Primitive newCube = Rotate4D::XY(hyCube, 57);

    Matrix mover(5);
    Matrix invMover(5);
    for (int i = 0; i < mover.getHeight() - 1; ++i) {
        invMover(i) = -7;
        mover(i) = 7;
    }

    newCube.translate(mover);

    sf::RenderWindow renderWindow(sf::VideoMode(800, 600), "Test");
    Renderer renderer(4, renderWindow);
    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::White);
    shape.setSize(sf::Vector2f(5, 5));
    sf::Clock clock;
    while (renderWindow.isOpen()) {
        sf::Event event;
        while (renderWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                renderWindow.close();
            }
        }
        renderWindow.clear();

        const float deltaTime = clock.restart().asSeconds();

        newCube.translate(invMover);
        newCube = Rotate4D::XY(newCube, 45 * deltaTime);
        newCube = Rotate4D::XU(newCube, 32 * deltaTime);
        newCube = Rotate4D::ZU(newCube, 46 * deltaTime);
        newCube.translate(mover);

        renderer.draw(newCube);

        renderWindow.display();
    }
    return 0;
}
