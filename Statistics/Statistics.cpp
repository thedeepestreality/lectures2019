#include <iostream>
#include <time.h>

int main()
{
	//Seed for pseudo-random numbers generator
	srand(time(NULL));
	//For cyrillic symbols in console
	setlocale(LC_ALL, "Ru");
	const int SIZE = 10;
	int lb = 10;
	int ub = 30;
	int arr[SIZE];
	int min, max;
	double mean = 0, disp = 0;
	//Filling array
	for (int i = 0; i < SIZE; ++i)
		arr[i] = lb + rand() % (ub - lb + 1);
	min = max = arr[0];
	//Array output
	for (int i = 0; i < SIZE; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	//MEAN
	for (int i = 0; i < SIZE; ++i)
		mean += arr[i];
	mean /= SIZE;
	//MIN-MAX
	for (int i = 0; i < SIZE; ++i)
	{
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	} 
	//DIPERSION
	for (int i = 0; i < SIZE; ++i)
		disp += (mean - arr[i]) * (mean - arr[i]);
	disp /= SIZE;
	disp = sqrt(SIZE);

	std::cout << "MEAN: " << mean << std::endl;
	std::cout << "MIN: " << min << std::endl;
	std::cout << "MAX: " << max << std::endl;
	std::cout << "DISP: " << disp << std::endl;

	system("pause");
	return 0;
}