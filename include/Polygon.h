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
    Polygon(int count, std::vector<Point> points);
    virtual ~Polygon() noexcept;

    virtual Point get_center() const = 0;

    virtual operator double() const = 0;
};

#endif