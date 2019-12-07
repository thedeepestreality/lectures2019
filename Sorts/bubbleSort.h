#pragma once
#include "utils.h"

//Сортировка пузырьком
template <typename Type>
void bubbleSort(Type Array[], int size, bool(*comp)(Type, Type) = Greater)
{
	for (int i = 1; i < size; ++i)
		for (int j = 0; j < size - i; ++j)
			if (comp(Array[j], Array[j + 1]))
				Swap(Array[j], Array[j + 1]);
}