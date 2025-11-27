#ifndef POLYGON_H
#define POLYGON_H

#include "Figure.h"
#include <vector>


class Polygon : public Figure
{
protected:
    Polygon() = default;
    Polygon(const Polygon& other);
    Polygon(Polygon&& other) noexcept;
    explicit Polygon(size_t vertex_count);
    Polygon(std::initializer_list<Point> points);

    Polygon& operator=(const Polygon& other);
    Polygon& operator=(Polygon&& other) noexcept;

    size_t _vertex_count;
    std::vector<Point> _points;

public:
    ~Polygon() noexcept override = default;

    explicit operator double() const override;
    bool operator==(const Polygon& other) const;

    Point get_center() const override;

    friend std::istream &operator>>(std::istream &istream, Polygon &object);
    friend std::ostream &operator<<(std::ostream &ostream, const Polygon &object);
};

std::istream &operator>>(std::istream &istream, Polygon &object);
std::ostream &operator<<(std::ostream &ostream, const Polygon &object);

#endif