#ifndef POINT_H
#define POINT_H

#include <iostream>

struct Point
{
    double x;
    double y;

    Point();
    Point(double x, double y);
    ~Point();

    friend std::istream &operator>>(std::istream &istream, Point &point);
    friend std::ostream &operator<<(std::ostream &ostream, const Point &point);
};

std::istream &operator>>(std::istream &istream, Point &point);
std::ostream &operator<<(std::ostream &ostream, const Point &point);

#endif