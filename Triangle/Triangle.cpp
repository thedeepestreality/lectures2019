#include "Triangle.h"

double Triangle::perimeter() const
{
	return length(_p1, _p2) + length(_p2, _p3) + length(_p1, _p3);
}

double Triangle::length(Point const& p1, Point const& p2) const
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double Triangle::area() const
{
	double a = length(_p1, _p2);
	double b = length(_p2,_p3);
	double c = length(_p1, _p3);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Tools::distance(Point p1, Point p2)
{
	//z = 2; //Error!
	staticZ = 2;
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int Tools::staticZ = 2;