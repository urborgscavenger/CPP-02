#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
    WriteLine("Default constructor called");
}

Fixed::Fixed(const Fixed& other) {
    WriteLine("Copy constructor called");
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    WriteLine("Copy assignment operator called");
    if (this != &other) {
        this->value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    WriteLine("Destructor called");
}

int Fixed::getRawBits(void) const {
    WriteLine("getRawBits member function called");
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}