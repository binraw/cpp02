#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(int nb)
{
    this->value = nb << value_static;
}

Fixed::Fixed(float nb)
{
    this->value = roundf(nb * (1<< value_static));
}

Fixed::Fixed(const Fixed &other)
{
	
	*this = other;
}

float Fixed::toFloat() const
{
    return static_cast<float>(value) / (1 << value_static);
}

int Fixed::toInt() const
{
    return value >> value_static;
}

Fixed &Fixed::operator=(const Fixed & other)
{

	if (this != &other)
		this->value = other.getRawBits();
	
	return *this;
}
Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->value + other.value);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->value - other.value);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;

    result.value = (this->value * other.value) >> this->value_static;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed(this->value / other.value);
}

bool Fixed::operator>(const Fixed& other) const
{
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->value != other.value;
}

Fixed& Fixed::operator++()
{
    this->value++;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->value++;
    return temp;
}

Fixed& Fixed::operator--()
{
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->value--;
    return temp;
}


std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat(); 
    return os; 
}

Fixed::~Fixed()
{

}
int Fixed::getRawBits(void) const
{
	
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw << this->value_static;
}


Fixed Fixed::min(Fixed& a, Fixed& b)
{
    if (a.value >= b.value)
        return b;
    return a;
}

Fixed Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.value >= b.value)
        return b;
    return a;
}

Fixed Fixed::max(Fixed& a, Fixed& b)
{
    if (a.value >= b.value)
        return a;
    return b;
}

Fixed Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.value >= b.value)
        return a;
    return b;
}