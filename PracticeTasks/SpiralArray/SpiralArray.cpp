#include <iostream>

void SpiralArray(int** spiral, int rows, int cols)
{
	int total = rows * cols;
	int current = 1;
	int r = 0, c = 0;
	int left = 0, right = cols - 1;
	int top = 0, bottom = rows - 1;

	while (current <= total)
	{
		if (current <= total)
		{
			do { spiral[r][c++] = current++; } while (c < right);
			++top;
		}
		if (current <= total)
		{
			do { spiral[r++][c] = current++; } while (r < bottom);
			--right;
		}
		if (current <= total)
		{
			do { spiral[r][c--] = current++; } while (c > left);
			--bottom;
		}
		if (current <= total)
		{
			do { spiral[r--][c] = current++; } while (r > top);
			++left;
		}
	}
}

int main()
{
	int rows, cols;
	int** spiral;

	std::cout << "ROWS: ";
	std::cin >> rows;
	std::cout << "COLS: ";
	std::cin >> cols;

	spiral = new int* [rows];
	for (int i = 0; i < rows; ++i)
		spiral[i] = new int[cols];

	SpiralArray(spiral, rows, cols);
	
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			std::cout << spiral[i][j] << '\t';
		std::cout << std::endl;
	}

	for (int i = 0; i < rows; ++i)
		delete[] spiral[i];
	delete[] spiral;

	system("pause");
	return 0;
}