#include "Polygon.h"
#include <algorithm>


Polygon::Polygon(std::initializer_list<Point> points) : _vertex_count(points.size()), _points(points)
{
    if (_vertex_count < 3) {
        throw std::invalid_argument("Polygon must have at least 3 points");
    }
}

Polygon::Polygon(size_t vertex_count) : _vertex_count(vertex_count), _points(std::vector<Point>(vertex_count)) {}

Polygon::Polygon(const Polygon &other) : _vertex_count(other._vertex_count), _points(other._points) {}

Polygon::Polygon(Polygon &&other) noexcept : _vertex_count(other._vertex_count), _points(std::move(other._points)) {}

bool Polygon::operator==(const Polygon& other) const
{
    std::vector<Point> first_points = _points;
    std::vector<Point> second_points = other._points;
    std::sort(first_points.begin(), first_points.end());
    std::sort(second_points.begin(), second_points.end());

    return first_points == second_points;
}

Polygon &Polygon::operator=(const Polygon &other)
{
    if (this != &other)
    {
        _vertex_count = other._vertex_count;
        _points = other._points;
    }

    return *this;
}

Polygon &Polygon::operator=(Polygon &&other) noexcept
{
    _vertex_count = other._vertex_count;
    _points = std::move(other._points);

    return *this;
}

Polygon::operator double() const
{
    double area = 0.0;
    for (size_t i = 0; i < _vertex_count; ++i)
    {
        size_t j = (i + 1) % _vertex_count;
        area += _points[i].x * _points[j].y;
        area -= _points[j].x * _points[i].y;
    }
    area = std::abs(area) / 2.0;
    return area;
}

std::istream &operator>>(std::istream &istream, Polygon &object)
{
    Point point;
    for (int i = 0; i < object._vertex_count; i++)
    {
        istream >> point;
        object._points[i] = point;
    }

    return istream;
}

std::ostream &operator<<(std::ostream &ostream, const Polygon &object)
{
    for (int i = 0; i < object._vertex_count; i++)
    {
        ostream << object._points[i];
    }

    return ostream;
}

Point Polygon::get_center() const
{
    double average_x = 0;
    double average_y = 0;

    for (size_t i = 0; i < _vertex_count; i++)
    {
        average_x += _points[i].x;
        average_y += _points[i].y;
    }

    average_x /= _vertex_count;
    average_y /= _vertex_count;

    return {average_x, average_y};
}