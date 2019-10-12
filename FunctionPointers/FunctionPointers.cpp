#include <iostream>

double square(double x)
{
	return x * x;
}

double cube(double x)
{
	return x * x * x;
}

int testFunc(double x, int y)
{
	return 0;
}

double integral(double(*func)(double),
				double a, 
				double b, 
				int numIntervals = 1000)
{
	double dx = (b - a) / numIntervals;
	double sum = 0;
	for (int i = 0; i < numIntervals; ++i)
	{
		sum += func(a + dx / 2) * dx;
		a += dx;
	}
	return sum;
}

typedef double(*doubleFuncPtr)(double);

doubleFuncPtr foo()
{
	return square;
}

int main()
{
	double(*funcPtr)(double);
	funcPtr = &square;
	std::cout << square(3) << std::endl;
	std::cout << funcPtr(3) << std::endl;

	funcPtr = cube;
	std::cout << cube(3) << std::endl;
	std::cout << funcPtr(3) << std::endl;

	int(*testFuncPtr)(double, int);

	//std::cout << integral(square, -1, 1) << std::endl;
	//std::cout << integral(cube, -1, 1) << std::endl;

	doubleFuncPtr funcArray[3] = { square, cube, sin };
	for (int i = 0; i < 3; ++i)
		std::cout << integral(funcArray[i], -1, 1) << std::endl;

	system("pause");
	return 0;
}