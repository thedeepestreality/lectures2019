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