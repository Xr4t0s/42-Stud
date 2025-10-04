#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point {
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point( void );
		Point( const float a, const float b );
		Point( const Point& rhs );

		Point& operator=( const Point& rhs );
		Point	operator-( const Point sub) const;

		float	getFloatX( void ) const;
		float	getFloatY( void ) const;
		int		getIntX( void ) const;
		int		getIntY( void ) const;

		~Point( void ); 
};

bool			bsp( Point const a, Point const b, Point const c, Point const point);
bool			minX( Point const a, Point const b );
bool			minY( Point const a, Point const b );
float			cross(Point const& u, Point const& v);
std::ostream& 	operator<<(std::ostream& os, Point const& obj);

#endif
