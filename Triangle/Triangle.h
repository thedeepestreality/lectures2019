#pragma once
#include <iostream>

struct Point
{
	double x;
	double y;
	Point(double _x = 0, double _y = 0) : x(_x), y(_y)
	{
		//x = _x;
		//y = _y;
		std::cout << "POINT CONSTRUCTED" << std::endl;
	}

	//Copy constructor
	Point(Point const& source) : x(source.x), y(source.y) 
	{
		std::cout << "POINT COPIED" << std::endl;
	}
};

class Triangle
{
private:
	Point _p1;
	Point _p2;
	Point _p3;

	double length(Point const& p1, Point const& p2) const;

public:
	Triangle(double x1, double y1,
			 double x2, double y2,
			 double x3, double y3) : _p1(x1,y1), _p2(x2,y2), _p3(x3,y3)
	{
		std::cout << "TRIANGLE CONSTRUCTED" << std::endl;
	}

	Triangle(Point const& p1, Point const& p2, Point const& p3) : 
		_p1(p1),
		_p2(p2),
		_p3(p3)
	{
		std::cout << _p2.x << std::endl;
	}

	double perimeter() const;
	double area() const;
};

class Tools
{
private:
	int z;
	Tools() {}
public:
	static double distance(Point p1, Point p2);
	static int staticZ;
};

struct Person
{
	char Name[16];
	char Surname[16];
	Person(char const* name)
	{
		strcpy_s(Name, name);
		Surname[0] = '\0';
	}

	Person(char const* name, char const* surname) : Person(name)
	{
		strcpy_s(Surname, surname);
	}

};