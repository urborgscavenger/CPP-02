#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
    WriteLine("Default constructor called");
}

Fixed::Fixed(const int intValue) : value(intValue << fractionalBits) {
    WriteLine("Int constructor called");
}

Fixed::Fixed(const float floatValue) : value(roundf(floatValue * (1 << fractionalBits))) {
    WriteLine("Float constructor called");
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
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->value) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
    return this->value >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}