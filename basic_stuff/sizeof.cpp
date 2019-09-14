#include <iostream>

int main()
{
	//Decimal
	int d = 42;
	//Octal
	int o = 052;
	//Hexadecimal
	int x = 0x2a;
	int X = 0X2A;
	//Binary (since C++14)
	int b = 0b101010;

	std::cout << "Values: " << d << ' ' << o << ' ' << x;
	std::cout << ' ' << X << ' ' << b << std::endl;

	int val = 2'000'000; //C++11 new cool feature!

	std::cout << "Size of int: " << sizeof(val) << std::endl;
	std::cout << "Size of long: " << sizeof(long) << std::endl;
	std::cout << "Size of long long: " << sizeof(long long) << std::endl;
	std::cout << "Size of short: " << sizeof(short) << std::endl;
	std::cout << "Size of char: " << sizeof(char) << std::endl;
	std::cout << "Size of float: " << sizeof(float) << std::endl;
	std::cout << "Size of double: " << sizeof(double) << std::endl;
	std::cout << "Size of bool: " << sizeof(bool) << std::endl;

	unsigned char byte = -2;
	std::cout << "Usigned val: " << (int)byte << std::endl;

	system("pause");
	return 0;
}