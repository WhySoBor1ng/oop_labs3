#include "Trapezoid.h"


Trapezoid::Trapezoid() : Polygon(4) {}

Trapezoid::Trapezoid(std::initializer_list<Point> points) : Polygon(points)
{
    if (_vertex_count != 4) {
        throw std::invalid_argument("Trapezoid must have 4 points");
    }
}

Trapezoid::Trapezoid(const Trapezoid &other) : Polygon(other) {}

Trapezoid::Trapezoid(Trapezoid &&other) noexcept : Polygon(other) {}

Point Trapezoid::get_center() const
{
    return Polygon::get_center();
}

Trapezoid &Trapezoid::operator=(const Trapezoid &other)
{
    Polygon::operator=(other);
    return *this;
}

Trapezoid &Trapezoid::operator=(Trapezoid &&other) noexcept
{
    Polygon::operator=(other);
    return *this;
}

bool Trapezoid::operator==(const Trapezoid &other) const
{
    return Polygon::operator==(other);
}

std::istream &operator>>(std::istream &istream, Trapezoid &object)
{
    return istream >> static_cast<Polygon&>(object);
}

std::ostream &operator<<(std::ostream &ostream, const Trapezoid &object)
{
    return ostream << static_cast<const Polygon&>(object);
}

Trapezoid::operator double() const
{
    return Polygon::operator double();
}