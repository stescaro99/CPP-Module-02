#include "Point.hpp"

int main( void ) {

	Point const v[3] = {Point(0.0f, 0.0f), Point(4.0f, 0.0f), Point(0.0f, 4.0f)};
	Point p(10.0f, 10.0f);
	Point q(1.0f, 1.0f);

	if (bsp(p, v))
		std::cout << "Point p is in triangle" << std::endl;
	else
		std::cout << "Point p is not in triangle" << std::endl;
	if (bsp(q, v))
		std::cout << "Point q is in triangle" << std::endl;
	else
		std::cout << "Point q is not in triangle" << std::endl;
return 0;
}