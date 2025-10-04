#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	std::cout << a.getFloatX() << " -> a(X)" << std::endl;
	std::cout << b.getFloatX() << " -> b(X)" << std::endl;
	std::cout << c.getFloatX() << " -> c(X)" << std::endl;
	std::cout << a.getFloatY() << " -> a(Y)" << std::endl;
	std::cout << b.getFloatY() << " -> b(Y)" << std::endl;
	std::cout << c.getFloatY() << " -> c(Y)" << std::endl;

	std::cout << point.getFloatX() << " -> Point(X)" << std::endl;
	std::cout << point.getFloatY() << " -> Point(Y)" << std::endl;
	
	Point pa = point - a;
	Point ab = b - a;
	Point pb = point - b;
	Point bc = c - b;
	Point pc = point - c;
	Point ca = a - c;

	float s1 = cross(pa, ab);
	float s2 = cross(pb, bc);
	float s3 = cross(pc, ca);
	if ((s1 > 0 && s2 > 0 && s3 > 0) || (s1 < 0 && s2 < 0 && s3 < 0))
		return true;

	return false;
}