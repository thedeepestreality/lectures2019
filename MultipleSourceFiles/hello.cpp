#include <iostream>
#include "hell.h"

extern int global;
int staticVar = 2;

inline double sqr(double x)
{
	return x * x;
}

void hell()
{
	std::cout << sqr(global) << std::endl;
}