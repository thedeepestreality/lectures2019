#include <iostream>
#include <fstream>

int main()
{
	std::ifstream in;
	in.open("in.txt");
	if (!in.is_open())
	{
		std::cout << "Failed to open file" << std::endl;
		system("pause");
		return 1;
	}
	
	int rows, cols;
	in >> rows >> cols;
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		matrix[i] = new int[cols];
		for (int j = 0; j < cols; ++j)
			in >> matrix[i][j];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			std::cout << matrix[i][j] << ' ';
		std::cout << std::endl;
	}

	for (int i = 0; i < rows; ++i)
		delete[] matrix[i];
	delete[] matrix;

	in.close();
	
	system("pause");
	return 0;
}