#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.h"

class Rectangle : public Polygon
{
public:
    Rectangle();
    virtual ~Rectangle() noexcept;
    Rectangle(const Rectangle &other);
    Rectangle(Rectangle &&other);

    virtual Point get_center() const override;
    virtual double get_area() const;

    virtual operator double() const override;
};

#endif