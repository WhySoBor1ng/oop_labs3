#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Polygon.h"

class Trapezoid : public Polygon
{
public:
    Trapezoid();
    Trapezoid(std::initializer_list<Point> points);
    Trapezoid(const Trapezoid &other);
    Trapezoid(Trapezoid &&other) noexcept;
    ~Trapezoid() noexcept override = default;

    Point get_center() const override;

    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;

    bool operator==(const Trapezoid &other) const;
    explicit operator double() const override;
    friend std::istream &operator>>(std::istream &istream, Trapezoid &object);
    friend std::ostream &operator<<(std::ostream &ostream, const Trapezoid &object);
};

std::istream &operator>>(std::istream &istream, Trapezoid &object);
std::ostream &operator<<(std::ostream &ostream, const Trapezoid &object);

#endif 
