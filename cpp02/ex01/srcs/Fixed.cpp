#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called." << std::endl;
	long long int tmp = static_cast<long long int>(n) * (1 << _fractionalBits);
	if (tmp > INT32_MAX || tmp < INT32_MIN)
		_value = (tmp > INT32_MAX) ? INT32_MAX : INT32_MIN;
	else
		_value = static_cast<int>(tmp);
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called." << std::endl;
	long long int tmp = static_cast<long long int>(
		roundf(f * (1 << _fractionalBits)));
	if (tmp > INT32_MAX || tmp < INT32_MIN)
		_value = (tmp > INT32_MAX) ? INT32_MAX : INT32_MIN;
	else
		_value = static_cast<int>(tmp);
}

Fixed::Fixed(const Fixed& other) : _value(other._value) {
	std::cout << "Copy constructor called." << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other)
		_value = other._value;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called." << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called." << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called." << std::endl;
	_value = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
	return _value >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
