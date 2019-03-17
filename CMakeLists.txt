cmake_minimum_required(VERSION 3.12)
project(Smash4D)

set(CMAKE_CXX_STANDARD 17)

add_executable(Smash4D main.cpp Matrix.cpp Matrix.h Primitive.cpp Primitive.h Primitives/HyperCube.cpp Primitives/HyperCube.h Rotate4D.cpp Rotate4D.h RenderChain.cpp RenderChain.h)
