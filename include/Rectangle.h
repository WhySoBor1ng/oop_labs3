#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.h"

class Rectangle : public Polygon
{
public:
    Rectangle();
    virtual ~Rectangle() noexcept;
    Rectangle(const Rectangle &other);
    Rectangle(Rectangle &&other) noexcept;

    virtual Point get_center() const override;

    Rectangle &operator=(const Rectangle &other);
    Rectangle &operator=(Rectangle &&other) noexcept;
    bool operator==(const Rectangle &other) const;

    virtual operator double() const override;
    virtual friend std::istream &operator>>(std::istream &istream, Rectangle &object);
    virtual friend std::ostream &operator<<(std::ostream &ostream, const Rectangle &object);
};

std::istream &operator>>(std::istream &istream, Polygon &object);
std::ostream &operator<<(std::ostream &ostream, const Polygon &object);

#endif