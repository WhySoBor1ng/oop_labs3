#ifndef POLYGON_H
#define POLYGON_H

#include "Figure.h"
#include <vector>

class Polygon : public Figure
{
protected:
    int _vertex_count;
    std::vector<Point> _points;

public:
    Polygon(int count, std::vector<Point>const& points);
    ~Polygon() noexcept override = default;

    Point get_center() const override = 0;

    explicit operator double() const override = 0;
};

#endif