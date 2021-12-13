cmake_minimum_required(VERSION 3.17)
project(tongwei3_abhitya2_seohyec2_yusongw2)

set(CMAKE_CXX_STANDARD 14)

include_directories(cs225)
include_directories(cs225/catch)
include_directories(cs225/lodepng)
include_directories(graphingpart)
include_directories(graphingpart/cs225)
include_directories(graphingpart/cs225/catch)
include_directories(graphingpart/cs225/lodepng)

add_executable(tongwei3_abhitya2_seohyec2_yusongw2
        cs225/catch/catch.hpp
        cs225/catch/catchmain.cpp
        cs225/lodepng/lodepng.cpp
        cs225/lodepng/lodepng.h
        cs225/HSLAPixel.cpp
        cs225/HSLAPixel.h
        cs225/PNG.cpp
        cs225/PNG.h
        cs225/RGB_HSL.h
        graphingpart/cs225/catch/catch.hpp
        graphingpart/cs225/catch/catchmain.cpp
        graphingpart/cs225/lodepng/lodepng.cpp
        graphingpart/cs225/lodepng/lodepng.h
        graphingpart/cs225/HSLAPixel.cpp
        graphingpart/cs225/HSLAPixel.h
        graphingpart/cs225/PNG.cpp
        graphingpart/cs225/PNG.h
        graphingpart/cs225/RGB_HSL.h
        graphingpart/Animation.cpp
        graphingpart/Animation.h
        graphingpart/circle.cpp
        graphingpart/circle.h
        graphingpart/color.h
        graphingpart/drawable.h
        graphingpart/gifFunction.hpp
        graphingpart/line.cpp
        graphingpart/line.h
        graphingpart/main.cpp
        graphingpart/shape.cpp
        graphingpart/shape.h
        graphingpart/vector2.cpp
        graphingpart/vector2.h
        graphingpart/visualize.cpp
        graphingpart/visualize.h
        shortestpath.cpp)
