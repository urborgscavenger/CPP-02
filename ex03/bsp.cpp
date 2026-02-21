#include "Point.hpp"

static Fixed area(Point const p1, Point const p2, Point const p3) {
    Fixed val = (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - (p3.getX() - p1.getX()) * (p2.getY() - p1.getY());
    if (val < Fixed(0)) {
        val = val * Fixed(-1);
    }
    return val;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed A = area(a, b, c);
    Fixed A1 = area(point, b, c);
    Fixed A2 = area(a, point, c);
    Fixed A3 = area(a, b, point);
    return (A == A1 + A2 + A3);
}