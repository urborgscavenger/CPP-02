#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

// C# Style Aliases
typedef std::string string;
#define WriteLine(x) std::cout << x << std::endl

class Fixed {
private:
    int value;
    static const int fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif