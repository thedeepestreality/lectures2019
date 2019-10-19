#include <iostream>
#include "hell.h"

int global = 2;

//Global only in current file
static int staticVar = 0; 

int foo(int k)
{
	static int counter = 1/k;
	return ++counter;
}

inline double sqr(double x)
{
	return x * x * x;
}

int main()
{
	hell();

	std::cout << foo(1) << std::endl;
	std::cout << foo(0) << std::endl;

	std::cout << sqr(2) << std::endl;

	system("pause");
	return 0;
}