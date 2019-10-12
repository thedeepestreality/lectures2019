#include <iostream>
#include <time.h>

void fillArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
		arr[i] = rand() % 101;
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << '\t';
	std::cout << std::endl;
}

int minElement(int arr[], int size)
{
	int idx = 0;
	for (int i = 0; i < size; ++i)
		idx = arr[i] < arr[idx] ? i : idx;
	return idx;
}

int maxElement(int arr[], int size)
{
	int idx = 0;
	for (int i = 0; i < size; ++i)
		idx = arr[i] > arr[idx] ? i : idx;
	return idx;
}

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int size;
	int* arr;
	int minElemIdx, maxElemIdx;
	std::cout << "Size of array: ";
	std::cin >> size;

	arr = new int[size];

	fillArray(arr, size);
	printArray(arr, size);

	minElemIdx = minElement(arr, size);
	maxElemIdx = maxElement(arr, size);
	Swap(arr[minElemIdx], arr[maxElemIdx]);

	printArray(arr, size);
	delete[] arr;

	system("pause");
	return 0;
}