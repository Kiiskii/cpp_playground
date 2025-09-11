#pragma once

#include <iostream>
#include <climits>

class Fixed {
private:
	int _value;									// stores fixed-point value
	static const int _fractionalBits = 8;		// number of fractional bits
public:
	Fixed();									// default constructor
	Fixed(const int n);							// int constructor
	Fixed(const float f);						// float constructor
	Fixed(const Fixed& other);					// copy constructor
	
	Fixed& operator=(const Fixed& other);		// copy assignment
	
	// Arithmetic operators (operate on fixed-point values and return new Fixed objects)
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// Comparison operators (compare fixed-point values)
	bool operator<(const Fixed& other) const;
	bool operator>(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	Fixed& operator++();						// pre-increment (++x)
	Fixed& operator--();						// pre-increment (--x)

	Fixed operator++(int);						// post-increment (x++)
	Fixed operator--(int);						// post-increment (x--)

	~Fixed();									// destructor
	
	int getRawBits() const;						// getter
	void setRawBits(int const raw);				// setter
	
	float toFloat() const;
	int toInt() const;

	static const Fixed& max(const Fixed& a, const Fixed& b);	// return ref to larger value
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed); // overload operator
