#include <iostream>

int main()
{
	int rows, cols, total, current = 1;
	int nrows, ncols;
	int** spiral;
	int r = 0, c = 0;
	int dr = 0, dc = 1;
	int cornerCounter = 0;
	int nextTurn;
	int cornerCounterMod4;

	std::cout << "ROWS: ";
	std::cin >> nrows;
	std::cout << "COLS: ";
	std::cin >> ncols;
	cols = ncols;
	rows = nrows;

	nextTurn = cols;

	total = rows * cols;
	spiral = new int* [rows];
	for (int i = 0; i < rows; ++i)
		spiral[i] = new int[cols];

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

	for (int i = 0; i < nrows; ++i)
	{
		for (int j = 0; j < ncols; ++j)
			std::cout << spiral[i][j] << '\t';
		std::cout << std::endl;
	}

	for (int i = 0; i < rows; ++i)
		delete[] spiral[i];
	delete[] spiral;

	system("pause");
	return 0;
}