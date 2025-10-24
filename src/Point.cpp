#include "Point.h"

Point::Point() : x(0.0), y(0.0) {}

Point::Point(double x, double y) : x(x), y(y) {}

Point::~Point() {}

std::istream &operator>>(std::istream &istream, Point &point)
{
    if (!(istream >> point.x) && !(istream >> point.y))
    {
        throw std::invalid_argument("Invalid arguments for point");
    }

    return istream;
}

std::ostream &operator<<(std::ostream &ostream, const Point &point)
{
    return ostream << point.x << " " << point.y;
}