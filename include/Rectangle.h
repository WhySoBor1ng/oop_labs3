#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.h"


class Rectangle : public Polygon
{
public:
    Rectangle();
    Rectangle(std::initializer_list<Point> points);
    Rectangle(const Rectangle &other);
    Rectangle(Rectangle &&other) noexcept;
    ~Rectangle() noexcept override = default;

    Point get_center() const override;

    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;

    bool operator==(const Rectangle &other) const;
    explicit operator double() const override;
    friend std::istream &operator>>(std::istream &istream, Rectangle &object);
    friend std::ostream &operator<<(std::ostream &ostream, const Rectangle &object);
};

std::istream &operator>>(std::istream &istream, Rectangle &object);
std::ostream &operator<<(std::ostream &ostream, const Rectangle &object);

#endif