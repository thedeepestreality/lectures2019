#include <iostream>
#include <stdarg.h>

int sum(int count, int x, ...)
{
	int s = x;
	va_list args;
	va_start(args, x);
	while (--count)
		s += va_arg(args, int);
	va_end(args);
	return s;
}

double prod(double x, ...)
{
	double result = x;
	double currArg = x;
	va_list args;
	va_start(args, x);
	while ((currArg = va_arg(args,double)) != 0)
		result *= currArg;
	va_end(args);
	return result;
}

int main()
{
	std::cout << sum(3, 4, 8, 9) << std::endl;
	std::cout << sum(3, 4, 8, 9, 10) << std::endl;
	std::cout << sum(3, 4, 8) << std::endl;

	double x = 5;
	std::cout << prod(4, x,x, 0.0) << std::endl;
	std::cout << prod(4.0, 5.5) << std::endl;

	double(*varArgFunc)(double, ...);
	varArgFunc = prod;
	std::cout << varArgFunc(4.0f, 5.5f, 3.2f,0.0f) << std::endl;

	system("pause");
	return 0;
}