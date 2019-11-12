#include <iostream>
#include <exception>

int gcd(int x, int y)
{
	if (x == 0 || y == 0) throw 1;
	if (x < 0) throw "First argument is negative";
	if (y < 0) throw std::runtime_error("Second argument is negative");
	while (x != y)
		x > y ? x -= y : y -= x;
	return x;
}

int main()
{
	try
	{
		gcd(1, -1);
		int x = gcd(1, 1);
		std::cout << x << std::endl;
		
	}
	catch (int errNum)
	{
		std::cout << "Arguments are zero" << std::endl;
		system("pause");
		return 1;
	}
	catch (const char* errorMsg)
	{
		std::cout << errorMsg << std::endl;
		system("pause");
		return 1;
	}
	catch (...)
	{
		std::cout << "Unknown error" << std::endl;
		system("pause");
		return 1;
	}
	
	system("pause");
	return 0;
}