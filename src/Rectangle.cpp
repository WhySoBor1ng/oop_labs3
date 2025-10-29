#include "Rectangle.h"

Rectangle::Rectangle() : Polygon(4, std::vector<Point>(4)) {}

Rectangle::Rectangle(const Rectangle &other) : Polygon(other._vertex_count, other._points) {}

Rectangle::Rectangle(Rectangle &&other) noexcept : Polygon(std::move(other._vertex_count), std::move(other._points)) {}

Point Rectangle::get_center() const
{
    double average_x = 0;
    double average_y = 0;

    for (int i = 0; i < _vertex_count; i++)
    {
        average_x += _points[i].x;
        average_y += _points[i].y;
    }

    average_x /= _vertex_count;
    average_y /= _vertex_count;

    return Point(average_x, average_y);
}

Rectangle &Rectangle::operator=(const Rectangle &other) {

}

std::istream &operator>>(std::istream &istream, Polygon &object)
{
    for (int i = 0; i < 4; i++)

    // {
    //     if (!(istream >> ) && !(istream >> point.y))
    //     {
    //         throw std::invalid_argument("Invalid arguments for point");
    //     }
    // }
}