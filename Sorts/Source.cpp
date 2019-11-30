#include <iostream>
#include <time.h>
#include "sorts.h"
#include "utils.h"

bool LessDouble(double left, double right)
{
	return left < right;
}

int main()
{
//	srand(time(NULL));
//	int size = 1e4;
//	double* arr = new double[size];
//	double* sortedArr = new double[size];
//
//	genRandArray(arr, size);
//	copyArray(arr, sortedArr, size);
////	printArray(arr, size);
//
//	//clock_t start = clock();
//	
//	/*tic();
//	bubbleSort(sortedArr, size);
//	std::cout << "Bubble random elapsed time: " << toc() << std::endl;
//
//	genSortedArray(sortedArr, size);
//	tic();
//	bubbleSort(sortedArr, size, LessDouble);
//	std::cout << "Bubble sorted elapsed time: " << toc() << std::endl;
//
//	genReverseSortedArray(sortedArr, size);
//	tic();
//	bubbleSort<double>(sortedArr, size, [](double l, double r) {return l < r; });
//	std::cout << "Bubble reverse elapsed time: " << toc() << std::endl;
//	*/
//
//	//copyArray(arr, sortedArr, size);
//	tic();
//	selectionSort(sortedArr, size);
//	std::cout << "Selection random elapsed time: " << toc() << std::endl;
//
//	genSortedArray(sortedArr, size);
//	tic();
//	selectionSort(sortedArr, size);
//	std::cout << "Selection sorted elapsed time: " << toc() << std::endl;
//
//	genReverseSortedArray(sortedArr, size);
//	tic();
//	selectionSort(sortedArr, size);
//	std::cout << "Selection reverse elapsed time: " << toc() << std::endl;
//
//	copyArray(arr, sortedArr, size);
//	tic();
//	insertionSort(sortedArr, size);
//	std::cout << "Insertion random elapsed time: " << toc() << std::endl;
//
//	genSortedArray(sortedArr, size);
//	tic();
//	insertionSort(sortedArr, size);
//	std::cout << "Insertion sorted elapsed time: " << toc() << std::endl;
//
//	genReverseSortedArray(sortedArr, size);
//	tic();
//	insertionSort(sortedArr, size);
//	std::cout << "Insertion reverse elapsed time: " << toc() << std::endl;
//
//
//	//clock_t finish = clock();
//	//std::cout << "Time elapsed: " << (double)(finish - start) / CLOCKS_PER_SEC << std::endl;
//
////	printArray(sortedArr, size);
//
//	delete[] arr;
//	delete[] sortedArr;

	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	for (int i = 0; i <= 14; ++i)
	{
		int idx = binarySearchRecursive(arr, 13, i);
		std::cout << idx << std::endl;
	}
	system("pause");
	return 0;
}