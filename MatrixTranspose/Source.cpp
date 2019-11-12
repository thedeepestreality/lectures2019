#include <iostream>
#include <fstream>

void transpose(int** original, int** transposed, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			transposed[j][i] = original[i][j];
}

void matrixToFile(	int** matrix,
					int rows,
					int cols,
					std::ofstream& fout)
{
	fout << rows << ' ' << cols << std::endl;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			fout << matrix[i][j] << ' ';
		fout << std::endl;
	}
}

int main()
{
	std::ifstream fin;
	std::ofstream fout;
	int rows, cols;
	int** originalMatrix;
	int** transposedMatrix;
	fin.open("in.txt");
	if (!fin.is_open())
	{
		std::cout << "Failed to open input file" << std::endl;
		system("pause");
		return 1;
	}

	fout.open("out.txt");
	if (!fout.is_open())
	{
		std::cout << "Failed to open output file" << std::endl;
		system("pause");
		return 1;
	}

	fin >> rows >> cols;
	originalMatrix = new int* [rows];
	transposedMatrix = new int* [cols];
	for (int i = 0; i < rows; ++i)
		originalMatrix[i] = new int[cols];
	for (int i = 0; i < cols; ++i)
		transposedMatrix[i] = new int[rows];

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			fin >> originalMatrix[i][j];

	transpose(originalMatrix, transposedMatrix, rows, cols);
	matrixToFile(transposedMatrix, cols, rows, fout);

	fout.close();
	fin.close();
	system("pause");
	return 0;
}