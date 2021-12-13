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
        cs225/lodepng/lodepng.cpp
        cs225/lodepng/lodepng.h
        cs225/HSLAPixel.cpp
        cs225/HSLAPixel.h
        cs225/PNG.cpp
        cs225/PNG.h
        cs225/RGB_HSL.h
        Animation.cpp
        Animation.h
        circle.cpp
        circle.h
        color.h
        drawable.h
        gifFunction.hpp
        line.cpp
        line.h
        main.cpp
        shape.cpp
        shape.h
        vector2.cpp
        vector2.h
        visualize.cpp
        visualize.h
        shortestpath.cpp)
