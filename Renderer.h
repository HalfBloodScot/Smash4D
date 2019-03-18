#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "RenderChain.h"
#include "Primitive.h"

class Renderer {
public:
    Renderer(int _dimension, sf::RenderWindow&);
    void draw(const Primitive&);
    void draw(const Matrix&);
protected:
    sf::RenderWindow& renderWindow;
    RenderChain renderChain;
    int dimension;
};

#endif //RENDERER_H_INCLUDED
