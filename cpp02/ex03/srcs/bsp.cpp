#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float triangle = Point::getTriangleArea(a, b, c);
	float pab = Point::getTriangleArea(point, a, b);
	float pbc = Point::getTriangleArea(point, b, c);
	float pca = Point::getTriangleArea(point, c, a);

	if (triangle == (pab + pbc + pca)) {
		return (pab > 0 && pbc > 0 && pca > 0);
	}
	return false;
}
