#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		Fixed x;
		Fixed y;

	public:
		Point();		
		Point(const Point &point);
		Point(float const x, float const y);
		Point &operator=(const Point &point);
		~Point();

		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp(Point const p, Point const v[3]);

#endif