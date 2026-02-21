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

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->value + other.value);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->value - other.value);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long long temp = static_cast<long long>(this->value) * other.value;
    result.setRawBits(temp >> fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    long long temp = static_cast<long long>(this->value) << fractionalBits;
    result.setRawBits(temp / other.value);
    return result;
}

// Comparison operators
bool Fixed::operator==(const Fixed& other) const {
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->value != other.value;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->value < other.value;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->value > other.value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->value <= other.value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->value >= other.value;
}

// Increment/Decrement operators
Fixed& Fixed::operator++() {
    this->value += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    this->value -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

// Static member functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}