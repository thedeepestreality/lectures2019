#pragma once

//Поразрядная сортировка (рекурсия)
void radixSortRec(int* array, int size, int digit)
{
	if (size <= 1)
		return;

	if (digit < 0)
		return;

	int leftIdx = 0;
	int rightIdx = size - 1;
	int mask = 1 << digit;

	while (true)
	{
		while ((leftIdx < rightIdx) && ((array[leftIdx] & mask) == 0))
			++leftIdx;
		while ((rightIdx > leftIdx) && ((array[rightIdx] & mask) != 0))
			--rightIdx;
		if (leftIdx != rightIdx)
			Swap(array[leftIdx], array[rightIdx]);
		else
			break;
	}

	int splitIdx = ((array[leftIdx] & mask) == 0) ? leftIdx + 1 : leftIdx;
	radixSortRec(array, splitIdx, digit - 1);
	radixSortRec(array + splitIdx, size - splitIdx, digit - 1);
}

//Поразрядная сортировка
void radixSort(int* array, int size)
{
	for (int i = 0; i < size; ++i)
		array[i] ^= INT_MIN;

	radixSortRec(array, size, 31);

	for (int i = 0; i < size; ++i)
		array[i] ^= INT_MIN;
}