#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    WriteLine(a);
    WriteLine(++a);
    WriteLine(a);
    WriteLine(a++);
    WriteLine(a);
    WriteLine(b);
    WriteLine(Fixed::max( a, b ));
    return 0;
}