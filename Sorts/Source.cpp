#include <iostream>
#include <time.h>
#include "sorts.h"
#include "utils.h"

int main()
{
	srand(time(NULL));
	int size = 1e5;
	double* arr = new double[size];
	double* sortedArr = new double[size];

	genRandArray(arr, size);
	copyArray(arr, sortedArr, size);
//	printArray(arr, size);

	//clock_t start = clock();
	/*
	tic();
	bubbleSort(sortedArr, size);
	std::cout << "Bubble random elapsed time: " << toc() << std::endl;

	genSortedArray(sortedArr, size);
	tic();
	bubbleSort(sortedArr, size);
	std::cout << "Bubble sorted elapsed time: " << toc() << std::endl;

	genReverseSortedArray(sortedArr, size);
	tic();
	bubbleSort(sortedArr, size);
	std::cout << "Bubble reverse elapsed time: " << toc() << std::endl;
	*/

	//copyArray(arr, sortedArr, size);
	tic();
	selectionSort(sortedArr, size);
	std::cout << "Selection random elapsed time: " << toc() << std::endl;

	genSortedArray(sortedArr, size);
	tic();
	selectionSort(sortedArr, size);
	std::cout << "Selection sorted elapsed time: " << toc() << std::endl;

	genReverseSortedArray(sortedArr, size);
	tic();
	selectionSort(sortedArr, size);
	std::cout << "Selection reverse elapsed time: " << toc() << std::endl;

	copyArray(arr, sortedArr, size);
	tic();
	insertionSort(sortedArr, size);
	std::cout << "Insertion random elapsed time: " << toc() << std::endl;

	genSortedArray(sortedArr, size);
	tic();
	insertionSort(sortedArr, size);
	std::cout << "Insertion sorted elapsed time: " << toc() << std::endl;

	genReverseSortedArray(sortedArr, size);
	tic();
	insertionSort(sortedArr, size);
	std::cout << "Insertion reverse elapsed time: " << toc() << std::endl;


	//clock_t finish = clock();
	//std::cout << "Time elapsed: " << (double)(finish - start) / CLOCKS_PER_SEC << std::endl;

//	printArray(sortedArr, size);

	delete[] arr;
	delete[] sortedArr;
	system("pause");
	return 0;
}