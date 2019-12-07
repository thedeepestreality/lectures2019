#pragma once

//Сортировка выбором
template <typename Type>
void selectionSort(Type Array[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int idx = 0;
		for (int j = 1; j < size - i; ++j)
			if (Array[j] > Array[idx])
				idx = j;
		Swap(Array[idx], Array[size - i - 1]);
	}
}