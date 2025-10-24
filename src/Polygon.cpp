#include "Polygon.h"

Polygon::Polygon(int count, std::vector<Point> points) : _vertex_count(count), _points(points) {}

Polygon::~Polygon() {}