#pragma once
#include "cs225/PNG.h"
#include "vector2.h"
namespace cs225{
    class Visualize{
        public:
            void visualize(std::vector<std::string> input);
            Vector2 maptocoord(double latitude, double longitude);
            void drawPixel(int x, int y, PNG & png);
            void drawLine(int x1, int y1, int x2, int y2, PNG & png);
    };
};