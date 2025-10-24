#ifndef FIGURE_H
#define FIGURE_H

#include "Point.h"

class Figure
{
public:
    virtual ~Figure() noexcept;

    virtual Point get_center() const = 0;

    virtual operator double() const = 0;
};

#endif