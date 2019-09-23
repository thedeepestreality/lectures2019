#include <iostream>

int main()
{
	const int ROWS = 10;
	const int COLS = 5;
	int snake[ROWS][COLS];
	int currVal = 1;
	//Filling
	for (int i = 0; i < ROWS; ++i)
	{
		if (i % 2 == 0)
			for (int j = 0; j < COLS; ++j)
				snake[i][j] = currVal++;
		else
			for (int j = COLS - 1; j >= 0; --j)
				snake[i][j] = currVal++;
	}
	//Displaying
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
			std::cout << snake[i][j] << "\t";
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}