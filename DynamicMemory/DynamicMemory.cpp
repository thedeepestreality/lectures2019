#include <iostream>
#include <time.h>

//Sum of two matrix int dynamic memory

//Function declarations
void fillMatrix(int** matrix, int rows, int cols);
void printMatrix(int** matrix, int rows, int cols);
void addMatrix( int** left, 
				int** right, 
				int** matrix, 
				int rows, 
				int cols);

int main()
{
	srand(time(NULL));
	int rows, cols;
	int** left;
	int** right;
	int** result;

	std::cout << "ROWS: ";
	std::cin >> rows;
	std::cout << "COLS: ";
	std::cin >> cols;

	left = new int* [rows];
	right = new int* [rows];
	result = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		left[i] = new int[cols];
		right[i] = new int[cols];
		result[i] = new int[cols];
	}
	fillMatrix(left, rows, cols);
	fillMatrix(right, rows, cols);
	addMatrix(left, right, result, rows, cols);

	std::cout << "LEFT: " << std::endl;
	printMatrix(left, rows, cols);
	std::cout << "RIGHT: " << std::endl;
	printMatrix(right, rows, cols);
	std::cout << "RESULT: " << std::endl;
	printMatrix(result, rows, cols);

	for (int i = 0; i < rows; ++i)
	{
		delete[] left[i];
		delete[] right[i];
		delete[] result[i];
	}
	delete[] left;
	delete[] right;
	delete[] result;

	system("pause");
	return 0;
}

//Function definitions

void fillMatrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			matrix[i][j] = rand() % 21 - 10;
}

void printMatrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			std::cout << matrix[i][j] << '\t';
		std::cout << std::endl;
	}
}

void addMatrix( int** left, 
				int** right, 
				int** result, 
				int rows, 
				int cols)
{
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			result[i][j] = left[i][j]+right[i][j];
}

