#include <iostream>
#include "remove_ref.h"
#include "class_template.h"
#include "template_template.h"
using std::cout;
using std::endl;

int main()
{
	ClassTemplate<int, 6> x;
	ClassTemplate<double, 6> y;
	x.n = 2;
	std::cout << x.n << " " << y.n << std::endl;

	//This will cause compile-time error
	//x.f();

	//remove reference modifier from template argument
	remove_reference<int&>::type r;

	Test<> z;

	system("pause");
	return 0;
}