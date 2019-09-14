#include <iostream>

int main()
{
	std::cout << "Input day of week: ";
	int d;
	std::cin >> d;
	switch (d)
	{
		case 1: 
		{
			std::cout << "Monday" << std::endl; 
			break;
		}

		case 2: 
		{
			std::cout << "Tuesday" << std::endl;
			break;
		}
		case 3: 
		{
			std::cout << "Wednesday" << std::endl; 
			break;
		}
		case 4:
		{
			std::cout << "Thursday" << std::endl; 
			break;
		}
		case 5: 
		{
			std::cout << "Friday" << std::endl; 
			break;
		}
		case 6: 
		{
			std::cout << "Saturday" << std::endl; 
			break;
		}
		case 0: 
		{
			std::cout << "Sunday" << std::endl; 
			break;
		}
		default: 
		{
			std::cout << "Wrong number" << std::endl;
			break;
		}
	}

	system("pause");
	return 0;
}