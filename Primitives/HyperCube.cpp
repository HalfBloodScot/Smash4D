//
// Created by Bryn McKerracher on 17/03/2019.
//

#include "HyperCube.h"

HyperCube::HyperCube() {
    vertices.resize(16, Matrix(5));
    for (int i = 0; i < 16; ++i) {
        for (int k = 0; k < 4; ++k) {
            vertices[i](k) = (i & (1 << k)) >> k;
        }
        //Set scale to 100
        vertices[i](4) = 100;
    }
}