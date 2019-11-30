#pragma once
#include "utils.h"

template <typename Type>
void bubbleSort(Type arr[], int size, bool(*comp)(Type,Type) = Greater)
{
	for (int i = 1; i < size; ++i)
		for (int j = 0; j < size - i; ++j)
			if (comp(arr[j],arr[j + 1]))
				Swap(arr[j], arr[j + 1]);
}

template <typename Type>
void selectionSort(Type arr[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int idx = 0;
		for (int j = 1; j < size - i; ++j)
			if (arr[j] > arr[idx])
				idx = j;
		Swap(arr[idx], arr[size - i - 1]);
	}
}

template <typename Type>
void insertionSort(Type arr[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		Type key = arr[i + 1];
		int j = i;
		for (; j >= 0; --j)
		{
			if (arr[j] > key)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = key;
	}
}

template <typename Type>
void insertionSortBinary(Type arr[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		if (arr[i + 1] >= arr[i]) continue;
		Type key = arr[i + 1];
		int idx = binarySearchForSort(arr, i + 1, key);
		int rightBound = key < arr[idx] ? idx : idx + 1;
		int j = i;
		for (; j >= rightBound; --j)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}

template <typename Type>
void merge(Type arr[], int size, int splitIdx)
{
	int lpos = 0;
	int rpos = splitIdx;
	int pos = 0;
	Type* tmpSorted = new Type[size];

	while (lpos < splitIdx && rpos < size)
		tmpSorted[pos++] = arr[lpos] < arr[rpos] ? arr[lpos++] : arr[rpos++];

	while (lpos < splitIdx)
		tmpSorted[pos++] = arr[lpos++];

	while(rpos < size)
		tmpSorted[pos++] = arr[rpos++];

	for (int i = 0; i < size; ++i)
		arr[i] = tmpSorted[i];
	delete[] tmpSorted;
}

template <typename Type>
void mergeSort(Type arr[], int size)
{
	if (size > 1)
	{
		int splitIdx = size / 2;
		mergeSort(arr, splitIdx);
		mergeSort(arr + splitIdx, size - splitIdx);
		merge(arr, size, splitIdx);
	}
}

