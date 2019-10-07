#include <iostream>

unsigned int OctalStrToDecimal(char* octalStr)
{
	int strSize = strlen(octalStr);
	unsigned int sum = 0;
	unsigned int eightDegree = 1;

	for (int i = strSize - 1; i >= 0; --i)
	{
		sum += eightDegree * (octalStr[i] - '0');
		//sum += eightDegree * atoi(&octalStr[i]);
		eightDegree *= 8;
	}

	return sum;
}

int main()
{
	char str[7];
	std::cout << "Input string: " << std::endl;
	std::cin >> str;

	std::cout << "Decimal: " << OctalStrToDecimal(str) << std::endl;

	system("pause");
	return 0;
}