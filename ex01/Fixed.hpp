#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <string>


class Fixed {
	public:
	Fixed();

	Fixed(const Fixed &);
    Fixed (int nb);
    Fixed (float nb);
	
	Fixed &operator=(const Fixed &);
    // Fixed &operator<<(const Fixed &);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

private:
	int value;
	static const  int value_static = 8; 
};



#endif
