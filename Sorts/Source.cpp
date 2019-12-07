#include <iostream>
#include <time.h>
#include "sorts.h"
#include "utils.h"

typedef void (*sortFunc)(double*, int);

void testSort(double* Array, int size, sortFunc sort, const char name[])
{
	double* sortedArray = new double[size];

	
	copyArray(Array, sortedArray, size);
	tic();
	sort(sortedArray, size);
	std::cout << name << " random elapsed time: " << toc() << std::endl;

	genSortedArray(sortedArray, size);
	tic();
	sort(sortedArray, size);
	std::cout << name << " sorted elapsed time: " << toc() << std::endl;

	genReverseSortedArray(sortedArray, size);
	tic();
	sort(sortedArray, size);
	std::cout << name << " reverse elapsed time: " << toc() << std::endl;

	std::cout << std::endl;
	delete[] sortedArray;
}

int main()
{
	srand(time(NULL));
	int size = 1e5;
	double* Array = new double[size];
	testSort(Array, size, mergeSort, "MergeSort");
	delete[] Array;
	system("pause");
	return 0;
}