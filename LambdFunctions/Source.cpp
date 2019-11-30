#include <iostream>

typedef double(*fdouble)(double);

static double a = 2;
double sqr(double x)
{
	return a * x * x;
}

auto summator(fdouble f1, fdouble f2)
{
	return [f1,f2](double x) {return f1(x) + f2(x); };
}

int main()
{
	auto fsqr = sqr;
	
	double aLocal = 3;
	double bLocal = 1;
	auto lsqr = 
		[aLocal,&bLocal](double x) -> int{ return aLocal * x * x + bLocal; };
	aLocal = 4;
	bLocal = 2;
	std::cout << fsqr(2.5) << " " << lsqr(2.5) << std::endl;

	auto summ = summator(sqr, sin);
	std::cout << summ(1.57) << std::endl;

	system("pause");
	return 0;
}