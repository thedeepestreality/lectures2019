#include <iostream>
#include <time.h>
#include "sorts.h"
#include "utils.h"

typedef void (*sortFunc)(double*, int);

void testSort(int size, sortFunc sort, const char name[])
{
	double* sortedArray = new double[size];

	genRandArray(sortedArray, size);
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

	qSortKiller(sortedArray, size);
	tic();
	sort(sortedArray, size);
	std::cout << name << " killer elapsed time: " << toc() << std::endl;

	std::cout << std::endl;
	delete[] sortedArray;
}

int main()
{
	srand(time(NULL));
	const int size = 7;
	//testSort(size, insertionSortBinary, "InsertionSortBinary");
	/*testSort(size, mergeSort, "MergeSort");
	testSort(size, qSortIter, "QuickSort");
	testSort(size, heapSort, "HeapSort");*/

	int test[size] = { 10, 5, 15, -2, -4, 0, 22 };
	radixSortStable(test, size);
	printArray(test, size);

	system("pause");
	return 0;
}