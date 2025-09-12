#pragma once

#include "Fixed.hpp"

class Point {
private:
	const Fixed _x;
	const Fixed _y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& other);
	Point& operator=(Point& other) = delete;
	~Point();

	float getX() const;
	float getY() const;
	static float getTriangleArea(Point const& a, Point const& b, Point const& c);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
