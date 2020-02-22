#include <iostream>
#include "Triangle.h"

void Test(Point p)
{

}

int main()
{
	//Triangle t(0,0,1,0,0,1);
	Point p(1, 2);
	Test(p);
	Point pCopy(p);
	Point pNew = p;

	Point pp;
	pp = p;

	//Point pt = { 1.5, 2.0 };
	//Triangle t = { Point(0,0), Point(1,0), Point(0,1) };

	Triangle t(Point(1, 0), Point(2, 0), Point(3, 0));

	Point* pPtr = new Point(1, 2);
	(*pPtr).x;
	pPtr->x;

	double d = Tools::distance(p, pp);
	Tools tool;
	d = tool.distance(p, pp);
	Tools::staticZ = 3;
	tool.staticZ = 4;

	system("pause");
	return 0;
}