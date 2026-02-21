#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    Point inside(5.0f, 5.0f);
    Point outside(15.0f, 5.0f);
    Point onEdge(5.0f, 0.0f);

    WriteLine("Triangle: " << a << ", " << b << ", " << c);
    WriteLine("Point inside: " << inside << " -> " << (bsp(a, b, c, inside) ? "true" : "false"));
    WriteLine("Point outside: " << outside << " -> " << (bsp(a, b, c, outside) ? "true" : "false"));
    WriteLine("Point on edge: " << onEdge << " -> " << (bsp(a, b, c, onEdge) ? "true" : "false"));

    return 0;
}