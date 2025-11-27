#include "Trapezoid.h"


Trapezoid::Trapezoid() : Polygon(4) {}

Trapezoid::Trapezoid(std::initializer_list<Point> points) : Polygon(points)
{
    if (_vertex_count != 4) {
        throw std::invalid_argument("Trapezoid must have 4 points");
    }
}