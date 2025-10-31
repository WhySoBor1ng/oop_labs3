#include "Square.h"


Square::Square() : Rectangle() {}

Square::Square(std::initializer_list<Point> points) : Rectangle(points)
{
    if (_vertex_count != 4) {
        throw std::invalid_argument("Square must have 4 points");
    }
}

Square::Square(const Square &other) : Rectangle(other) {}

Square::Square(Square &&other) noexcept : Rectangle(other) {}

Square &Square::operator=(const Square &other)
{
    Rectangle::operator=(other);
    return *this;
}

Square &Square::operator=(Square &&other) noexcept
{
    Rectangle::operator=(other);
    return *this;
}

std::istream &operator>>(std::istream &istream, Square &object)
{
    return istream >> static_cast<Rectangle&>(object);
}

std::ostream &operator<<(std::ostream &ostream, const Square &object)
{
    return ostream << static_cast<const Rectangle&>(object);
}