#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(int nb)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = nb << value_static;
}

Fixed::Fixed(float nb)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = static_cast<int> (nb * (1<< value_static));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

float Fixed::toFloat() const
{
    return static_cast<float>(value) / (1 << value_static);
}

int Fixed::toInt() const
{
    return value << value_static;
}

Fixed &Fixed::operator=(const Fixed & other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat(); 
    return os; 
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw << this->value_static;
}
