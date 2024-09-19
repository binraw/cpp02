#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <string>


class Fixed {
	public:
	Fixed();

	Fixed(const Fixed &other);
    Fixed (int nb);
    Fixed (float nb);
	
	Fixed &operator=(const Fixed& other);
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
    static Fixed min(Fixed& a, Fixed& b);
    static Fixed min(const Fixed& a, const Fixed& b);
    static Fixed max(Fixed& a, Fixed& b);
    static Fixed max(const Fixed& a, const Fixed& b);

private:
	int value;
	static const  int value_static = 8; 
};



#endif