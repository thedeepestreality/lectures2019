#include <iostream>

int main()
{
	double x, y;
	std::cout << "Input X: ";
	std::cin >> x;
	std::cout << "Input Y: ";
	std::cin >> y;
	double dist = x * x + y * y;
	if (dist <= 25 && dist > 1)
		std::cout << "WIN" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	system("pause");
	return 0;
}