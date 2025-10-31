#include "Rectangle.h"


Rectangle::Rectangle() : Polygon(4) {}

Rectangle::Rectangle(std::initializer_list<Point> points) : Polygon(points)
{
    if (_vertex_count != 4) {
        throw std::invalid_argument("Rectangle must have 4 points");
    }
}

Rectangle::Rectangle(const Rectangle &other) : Polygon(other) {}

Rectangle::Rectangle(Rectangle &&other) noexcept : Polygon(other) {}

Point Rectangle::get_center() const
{
    return Polygon::get_center();
}

Rectangle &Rectangle::operator=(const Rectangle &other)
{
    Polygon::operator=(other);
    return *this;
}

Rectangle &Rectangle::operator=(Rectangle &&other) noexcept
{
    Polygon::operator=(other);
    return *this;
}

bool Rectangle::operator==(const Rectangle &other) const
{
    return Polygon::operator==(other);
}

std::istream &operator>>(std::istream &istream, Rectangle &object)
{
    return istream >> static_cast<Polygon&>(object);
}

std::ostream &operator<<(std::ostream &ostream, const Rectangle &object)
{
    return ostream << static_cast<const Polygon&>(object);
}

Rectangle::operator double() const
{
    return Polygon::operator double();
}