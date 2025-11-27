#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Polygon.h"

class Trapezoid : public Polygon
{
public:
    Trapezoid();
    Trapezoid(std::initializer_list<Point> points);
    Trapezoid(const Trapezoid &other) = default;
    Trapezoid(Trapezoid &&other) noexcept = default;
    ~Trapezoid() noexcept override = default;

    Trapezoid& operator=(const Trapezoid& other) = default;
    Trapezoid& operator=(Trapezoid&& other) noexcept = default;
};

#endif 
