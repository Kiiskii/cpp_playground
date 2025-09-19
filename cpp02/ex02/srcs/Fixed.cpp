#include "Fixed.hpp"
#include <cmath>

// constructors commented out for clearer tests

Fixed::Fixed() : _value(0) {
	//std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const int n) {
	//std::cout << "Int constructor called." << std::endl;
	_value = n << _fractionalBits;
}

Fixed::Fixed(const float f) {
	//std::cout << "Float constructor called." << std::endl;
	_value = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) : _value(other.getRawBits()) {
	//std::cout << "Copy constructor called." << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	//std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called." << std::endl;
}

int Fixed::getRawBits() const {
	//std::cout << "getRawBits member function called." << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	//std::cout << "setRawBits member function called." << std::endl;
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

Fixed& Fixed::operator++() {
	_value += 1;
	return *this;
}

Fixed& Fixed::operator--() {
	_value -= 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	_value += 1;
	return temp;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	_value -= 1;
	return temp;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>(const Fixed& other) const {
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed temp;

	int raw = this->getRawBits() + other.getRawBits();
	temp.setRawBits(raw);
	return temp;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed temp;

	int raw = this->getRawBits() - other.getRawBits();
	temp.setRawBits(raw);
	return temp;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed temp;

	long long raw = (static_cast<long long>(this->getRawBits()) * other.getRawBits()) >> _fractionalBits;
	temp.setRawBits(raw);
	return temp;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed temp;

	long long raw = (static_cast<long long>(this->getRawBits()) << _fractionalBits) / other.getRawBits();
	temp.setRawBits(raw);
	return temp;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a._value >= b._value) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a._value >= b._value) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a._value < b._value) ? a : b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a._value < b._value) ? a : b;
}
