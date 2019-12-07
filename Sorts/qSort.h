#pragma once

//Разделение для быстрой сортировки
template <typename Type>
int qSortPartition(Type Array[], int lPos, int rPos)
{
	int pivotIdx = (rPos + lPos) / 2;
	Type pivot = Array[pivotIdx];
	while (lPos < rPos)
	{
		while (pivot >= Array[lPos] && lPos < pivotIdx)
			++lPos;
		while (Array[rPos] >= pivot && rPos > pivotIdx)
			--rPos;
		if (lPos >= rPos)
			break;

		Swap(Array[lPos], Array[rPos]);

		if (lPos == pivotIdx)
			pivotIdx = rPos;

		else if (rPos == pivotIdx)
			pivotIdx = lPos;
	}
	return lPos;
}

//Быстрая сортировка (Quick sort)
template <typename Type>
void qSort(Type* Array, int size)
{
	if (size <= 1) return;
	if (size < 1e3)
	{
		insertionSortBinary(Array, size);
		return;
	}

	int pivot = qSortPartition(Array, 0, size - 1);
	qSort(Array, pivot);
	qSort(Array + pivot + 1, size - pivot - 1);
}

//Итеративная быстрая сортировка
void qSortIter(double arr[], int size)
{
	// Create an auxiliary stack 
	double* stack = new double[size];

	// initialize top of stack 
	int top = -1;
	int l = 0;
	int h = size - 1;
	// push initial values of l and h to stack 
	stack[++top] = l;
	stack[++top] = h;

	// Keep popping from stack while is not empty 
	while (top >= 0) {
		// Pop h and l 
		h = stack[top--];
		l = stack[top--];

		// Set pivot element at its correct position 
		// in sorted array 
		int p = qSortPartition(arr, l, h);

		// If there are elements on left side of pivot, 
		// then push left side to stack 
		if (p - 1 > l) {
			stack[++top] = l;
			stack[++top] = p - 1;
		}

		// If there are elements on right side of pivot, 
		// then push right side to stack 
		if (p + 1 < h) {
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
	delete[] stack;
}