#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.h"


class Rectangle : public Polygon
{
public:
    Rectangle();
    Rectangle(std::initializer_list<Point> points);
    Rectangle(const Rectangle &other) = default;
    Rectangle(Rectangle &&other) noexcept = default;
    ~Rectangle() noexcept override = default;

    Rectangle& operator=(const Rectangle& other) = default;
    Rectangle& operator=(Rectangle&& other) noexcept = default;
};

#endif