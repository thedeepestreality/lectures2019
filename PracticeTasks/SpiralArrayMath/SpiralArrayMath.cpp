#include <iostream>

void SpiralArrayMath(int** spiral, int rows, int cols)
{
	int total = rows * cols;
	int current = 1;
	int r = 0, c = 0;
	int dr = 0, dc = 1;
	int cornerCounter = 0;
	int nextTurn = cols;
	int cornerCounterMod4;

	while (current <= total)
	{
		spiral[r][c] = current++;
		if ((current - 1) == nextTurn)
		{
			++cornerCounter;
			cornerCounterMod4 = cornerCounter % 4;
			dr = 1 - abs(cornerCounterMod4 - 1);
			dc = abs(cornerCounterMod4 - 2) - 1;
			rows -= abs(dr);
			cols -= abs(dc);
			nextTurn += (dr != 0) * rows + (dc != 0) * cols;
		}
		r += dr;
		c += dc;
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

	SpiralArrayMath(spiral, rows, cols);

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