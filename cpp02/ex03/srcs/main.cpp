#include "Point.hpp"

void testCase(const Point& a, const Point& b, const Point& c, const Point& p, const std::string& description) {
	std::cout << description << ": ";
	bool inside = bsp(a, b, c, p);
	std::cout << (inside ? "INSIDE" : "OUTSIDE") << std::endl;
}

int main() {
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	std::cout << "Triangle: A(0,0), B(10,0), C(0,10)" << std::endl;

	// Inside
	testCase(a, b, c, Point(3, 3), "Point (3,3) inside");

	// Outside
	testCase(a, b, c, Point(10, 10), "Point (10,10) outside");

	// On edge AB
	testCase(a, b, c, Point(5, 0), "Point (5,0) on edge AB");

	// On edge AC
	testCase(a, b, c, Point(0, 5), "Point (0,5) on edge AC");

	// On edge BC
	testCase(a, b, c, Point(5, 5), "Point (5,5) on edge BC");

	// On vertex A
	testCase(a, b, c, Point(0, 0), "Point (0,0) at vertex A");

	// Different triangle orientation
	Point d(-5, -5), e(-10, -5), f(-5, -10);
	testCase(d, e, f, Point(-6, -6), "Point (-6,-6) inside rotated triangle");
	testCase(d, e, f, Point(-11, -11), "Point (-11,-11) outside rotated triangle");

	return 0;
}
