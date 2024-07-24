#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const Point &point) : x(point.x), y(point.y)
{
}

Point::Point(float const x, float const y) : x(x), y(y)
{
}

Point &Point::operator=(const Point &point)
{
	if (this != &point)
	{
		this->x = point.getX();
		this->y = point.getY();
	}
	return *this;
}

Point::~Point()
{
}

Fixed Point::getX(void) const
{
	return this->x;
}

Fixed Point::getY(void) const
{
	return this->y;
}
