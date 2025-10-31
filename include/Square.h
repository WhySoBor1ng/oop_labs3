#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"


class Square : public Rectangle
{
public:
    Square();
    Square(std::initializer_list<Point> points);
    Square(const Square &other);
    Square(Square &&other) noexcept;
    ~Square() noexcept override = default;

    Square &operator=(const Square &other);
    Square &operator=(Square &&other) noexcept;

    friend std::istream &operator>>(std::istream &istream, Square &object);
    friend std::ostream &operator<<(std::ostream &ostream, const Square &object);
};

std::istream &operator>>(std::istream &istream, Square &object);
std::ostream &operator<<(std::ostream &ostream, const Square &object);

#endif
