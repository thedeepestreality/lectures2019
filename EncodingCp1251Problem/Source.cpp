#include <fstream>
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Rus");
	std::fstream fin;
	fin.open("in.txt");
	if (!fin.is_open())
	{
		std::cout << "Failed to open file" << std::endl;
		system("pause");
		return 1;
	}

	char c = fin.get();
	while (c != EOF)
	{
		std::cout << c;
		c = fin.get();
	}
	std::cout << std::endl;
	fin.close();
	system("pause");
	return 0;
}