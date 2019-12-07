#pragma once

//Слияние для mergeSort
template <typename Type>
void merge(Type Array[], int size, int splitIdx)
{
	int lpos = 0;
	int rpos = splitIdx;
	int pos = 0;
	Type* tmpSorted = new Type[size];

	while (lpos < splitIdx && rpos < size)
		tmpSorted[pos++] = Array[lpos] < Array[rpos] ? Array[lpos++] : Array[rpos++];

	while (lpos < splitIdx)
		tmpSorted[pos++] = Array[lpos++];

	while (rpos < size)
		tmpSorted[pos++] = Array[rpos++];

	for (int i = 0; i < size; ++i)
		Array[i] = tmpSorted[i];
	delete[] tmpSorted;
}

//Сортировка слиянием
template <typename Type>
void mergeSort(Type Array[], int size)
{
	if (size <= 1) return;

	int splitIdx = size / 2;
	mergeSort(Array, splitIdx);
	mergeSort(Array + splitIdx, size - splitIdx);
	merge(Array, size, splitIdx);
}