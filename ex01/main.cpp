#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    WriteLine("a is " << a);
    WriteLine("b is " << b);
    WriteLine("c is " << c);
    WriteLine("d is " << d);
    WriteLine("a is " << a.toInt() << " as integer");
    WriteLine("b is " << b.toInt() << " as integer");
    WriteLine("c is " << c.toInt() << " as integer");
    WriteLine("d is " << d.toInt() << " as integer");
    return 0;
}