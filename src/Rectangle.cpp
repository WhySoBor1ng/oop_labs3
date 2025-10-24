#include "Rectangle.h"

Rectangle::Rectangle() : Polygon(4, std::vector<Point>(4)) {}

Rectangle::~Rectangle() {}

Rectangle::Rectangle(const Rectangle &other) : Polygon(other._vertex_count, other._points) {}

Rectangle::Rectangle(Rectangle &&other) : Polygon(std::move(other._vertex_count), std::move(other._points)) {}

Point Rectangle::get_center() const
{
    double average_x;
    double average_y;

    for (int i = 0; i < _vertex_count; i++)
    {
        average_x += _points[i].x;
        average_y += _points[i].y;
    }

    average_x /= _vertex_count;
    average_y /= _vertex_count;

    return Point(average_x, average_y);
}

Rectangle &Rectangle::operator=(const Rectangle &other)
{
}