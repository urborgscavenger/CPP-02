#include <iostream>
#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;
    WriteLine(a.getRawBits());
    WriteLine(b.getRawBits());
    WriteLine(c.getRawBits());
    return 0;
}