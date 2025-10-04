#include "Point.hpp"
#include <iostream>

int main( void ) {
	Point a(4.0f, 2.0f);
	Point b(10.0f, 6.0f);
	Point c(11.0f, 1.0f);

	Point Point(5.0f, 2.0f);

	std::cout << bsp(a, b, c, Point) << std::endl;
}