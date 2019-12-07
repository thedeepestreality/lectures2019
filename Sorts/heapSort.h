#pragma once

//Просеивание элемента через пирамиду
//(для пирамиальной сортировки)
template <typename Type>
void heapElem(Type* Array, int size, int idx)
{
	while (idx * 2 + 1 < size)
	{
		if (idx * 2 + 2 < size)
		{
			int maxIdx = (Array[idx * 2 + 1] > Array[idx * 2 + 2]) ?
				idx * 2 + 1
				: idx * 2 + 2;
			if (Array[maxIdx] > Array[idx])
			{
				Swap(Array[maxIdx], Array[idx]);
				idx = maxIdx;
			}
			else
				break;
		}
		else
		{
			if (Array[2 * idx + 1] > Array[idx])
			{
				Swap(Array[2 * idx + 1], Array[idx]);
			}
			break;
		}
	}
}

//Пирамидальная сортировка
template <typename Type>
void heapSort(Type* Array, int size)
{
	//1. Make heap
	for (int i = size / 2 - 1; i >= 0; --i)
		heapElem(Array, size, i);
	//2. Sort
	for (int i = 0; i < size; ++i)
	{
		Swap(Array[0], Array[size - i - 1]);
		heapElem(Array, size - i - 1, 0);
	}
}