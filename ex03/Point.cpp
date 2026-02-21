#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Fixed& x, const Fixed& y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::~Point() {}

Fixed Point::getX() const {
    return this->x;
}

Fixed Point::getY() const {
    return this->y;
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.getX() << ", " << point.getY() << ")";
    return os;
}