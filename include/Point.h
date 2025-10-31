#ifndef POINT_H
#define POINT_H

#include <iostream>


constexpr double eps = 1e-6;

struct Point
{
    double x;
    double y;

    Point();
    Point(double x, double y);
    Point(const Point &other) = default;
    Point(Point &&other) noexcept = default;
    ~Point() noexcept = default;

    bool operator<(const Point &other) const;
    bool operator==(const Point &other) const;
    Point &operator=(const Point &other);

    friend std::istream &operator>>(std::istream &istream, Point &point);
    friend std::ostream &operator<<(std::ostream &ostream, const Point &point);
};

std::istream &operator>>(std::istream &istream, Point &point);
std::ostream &operator<<(std::ostream &ostream, const Point &point);

#endif