#pragma once

//Поразрядная сортировка (рекурсия)
void radixSortRec(int* Array, int size, int digit)
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
		while ((leftIdx < rightIdx) && ((Array[leftIdx] & mask) == 0))
			++leftIdx;
		while ((rightIdx > leftIdx) && ((Array[rightIdx] & mask) != 0))
			--rightIdx;
		if (leftIdx != rightIdx)
			Swap(Array[leftIdx], Array[rightIdx]);
		else
			break;
	}

	int splitIdx = ((Array[leftIdx] & mask) == 0) ? leftIdx + 1 : leftIdx;
	radixSortRec(Array, splitIdx, digit - 1);
	radixSortRec(Array + splitIdx, size - splitIdx, digit - 1);
}

void radixSortStable(int* Array, int size)
{
	for (int digit = 0; digit < 32; ++digit)
	{
		int mask = (1 << digit);
		for (int i = 0; i < size - 1; ++i)
		{
			int key = Array[i + 1];
			int j = i;
			for (; j >= 0; --j)
			{
				if ((Array[j]&mask) > (key&mask))
					Array[j + 1] = Array[j];
				else
					break;
			}
			Array[j + 1] = key;
		}
	}
}

//Поразрядная сортировка
void radixSort(int* Array, int size)
{
	for (int i = 0; i < size; ++i)
		Array[i] ^= INT_MIN;

	radixSortRec(Array, size, 31);

	for (int i = 0; i < size; ++i)
		Array[i] ^= INT_MIN;
}