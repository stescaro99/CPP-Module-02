#include "Point.hpp"

bool bsp(Point const p, Point const v[3])
{
	Fixed x = p.getX();
	Fixed y = p.getY();
	Fixed ax = v[0].getX();
	Fixed ay = v[0].getY();
	Fixed bx = v[1].getX();
	Fixed by = v[1].getY();
	Fixed cx = v[2].getX();
	Fixed cy = v[2].getY();

	Fixed zero = Fixed();
	short d = 0;

	if ((x - ax) * (by - ay) - (y - ay) * (bx - ax) > zero)
		d++;
	if ((x - bx) * (cy - by) - (y - by) * (cx - bx) > zero)
		d++;
	if ((x - cx) * (ay - cy) - (y - cy) * (ax - cx) > zero)
		d++;

	if (d == 0 || d == 3)
		return true;
	return false;
}
