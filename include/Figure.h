#ifndef FIGURE_H
#define FIGURE_H

#include "Point.h"

class Figure
{
public:
    virtual ~Figure() noexcept = default;

    virtual Point get_center() const = 0;

    Figure& operator=(const Figure& other) = delete;
    Figure& operator=(Figure&& other) = delete;
    virtual explicit operator double() const = 0;
};

#endif