#include "Renderer.h"

Renderer::Renderer(int _dimension, sf::RenderWindow& _renderWindow) :
    renderChain(_dimension), renderWindow(_renderWindow), dimension(_dimension)
{}

void Renderer::draw(const Primitive& primitive) {
    for (int i = 0; i < primitive.vertexCount(); ++i) {
        draw(primitive(i));
    }
}

void Renderer::draw(const Matrix& matrix) {
    Matrix collapsed = renderChain.compute(matrix);
    
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(5, 5));
    rect.setFillColor(sf::Color::White);
    rect.setPosition(sf::Vector2f(collapsed(0)* 50, collapsed(1) * 50));
    renderWindow.draw(rect);
}
