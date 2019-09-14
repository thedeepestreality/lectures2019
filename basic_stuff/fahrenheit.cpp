#include <iostream>

int main()
{
	//Table header
	std::cout << "F\tC\tS" << std::endl;
	//Print only 4 significant digits
	std::cout.precision(4);
	for (double F = 0; F <= 100; F += 10)
	{
		double C = 5.0/9.0 * (F - 32);
		std::cout << F << '\t' << C << '\t';
		if (C > 30)
			std::cout << "Hot";
		else if (C < 5)
			std::cout << "Cold";
		else
			std::cout << "Norm";
		std::cout << std::endl;
	}

	system("pause");
	return 0;
}