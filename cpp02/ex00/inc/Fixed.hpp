#pragma once

#include <iostream>

class Fixed {
private:
	int _value;								// stores fixed-point value
	static const int _fractionalBits = 8;	// number of fractional bits
public:
	Fixed();								// default constructor
	Fixed(const Fixed& other);				// copy constructor
	Fixed& operator=(const Fixed& other);	// copy assignment
	~Fixed();								// destructor
	
	int getRawBits() const;					// getter
	void setRawBits(int const raw);			// setter
};
