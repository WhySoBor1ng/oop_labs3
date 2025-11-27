#ifndef FIGURE_H
#define FIGURE_H

#include "Point.h"


class Figure
{
protected:
    Figure() = default;
    Figure(const Figure&) = delete;
    Figure(Figure&&) = delete;

    Figure& operator=(const Figure& other) = delete;
    Figure& operator=(Figure&& other) = delete;
public:
    virtual ~Figure() noexcept = default;

    virtual Point get_center() const = 0;

    virtual explicit operator double() const = 0;
};

#endif