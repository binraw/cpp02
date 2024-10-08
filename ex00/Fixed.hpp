#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <string>


class Fixed {
	public:
	Fixed();

	Fixed(const Fixed &);
	
	Fixed &operator=(const Fixed &);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int value;
	static const  int value_static = 8; 
};

#endif
