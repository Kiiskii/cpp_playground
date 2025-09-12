#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	// std::cout << "Point default constructor called." << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	// std::cout << "Point constructor called." << std::endl;
}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {
	// std::cout << "Point copy constructor called." << std::endl;
}

Point::~Point() {
	// std::cout << "Point destructor called." << std::endl;
}

float Point::getX() const {
	return _x.toFloat();
}

float Point::getY() const {
	return _y.toFloat();
}

float Point::getTriangleArea(Point const& a, Point const& b, Point const& c) {
	float res = 0.5f * std::abs(a.getX() * (b.getY() - c.getY()) +
								b.getX() * (c.getY() - a.getY()) +
								c.getX() * (a.getY() - b.getY()));

	return res;
}
