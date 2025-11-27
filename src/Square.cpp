#include "Square.h"


Square::Square() : Rectangle() {}

Square::Square(std::initializer_list<Point> points) : Rectangle(points)
{
    if (_vertex_count != 4) {
        throw std::invalid_argument("Square must have 4 points");
    }
}