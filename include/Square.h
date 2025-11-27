#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"


class Square : public Rectangle
{
public:
    Square();
    Square(std::initializer_list<Point> points);
    Square(const Square &other) = default;
    Square(Square &&other) noexcept = default;
    ~Square() noexcept override = default;

    Square &operator=(const Square &other) = default;
    Square &operator=(Square &&other) noexcept = default;
};

#endif
