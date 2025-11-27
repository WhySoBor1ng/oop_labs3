#include "Rectangle.h"


Rectangle::Rectangle() : Polygon(4) {}

Rectangle::Rectangle(std::initializer_list<Point> points) : Polygon(points)
{
    if (_vertex_count != 4) {
        throw std::invalid_argument("Rectangle must have 4 points");
    }
}