#pragma once

#include <iostream>
#include <climits>

class Fixed {
private:
	int _value;								// stores fixed-point value
	static const int _fractionalBits = 8;	// number of fractional bits
public:
	Fixed();								// default constructor
	Fixed(const int n);						// int constructor
	Fixed(const float f);					// float constructor
	Fixed(const Fixed& other);				// copy constructor
	Fixed& operator=(const Fixed& other);	// copy assignment
	~Fixed();								// destructor
	
	int getRawBits() const;					// getter
	void setRawBits(int const raw);			// setter
	
	float toFloat() const;
	int toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed); // overload operator
