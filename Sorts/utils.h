#pragma once
#include <stdlib.h>
#include <iostream>
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

static high_resolution_clock::time_point start;

void tic()
{
	start = high_resolution_clock::now();
}

long toc()
{
	return duration_cast<milliseconds>(high_resolution_clock::now() - start).count();
}

bool LessDouble(double left, double right)
{
	return left < right;
}

template <typename Type>
void Swap(Type& a, Type& b)
{
	Type tmp = a;
	a = b;
	b = tmp;
}

void genRandArray(double Array[], int size)
{
	for (int i = 0; i < size; ++i)
		Array[i] = (double) rand() / RAND_MAX;
}

void genSortedArray(double Array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		double d = (double)i / size;
		Array[i] = d;
	}
}

void genReverseSortedArray(double Array[], int size)
{
	genSortedArray(Array, size);
	for (int i = 0; i < size / 2; ++i)
		Swap(Array[i], Array[size - i - 1]);
}

template <typename Type>
void printArray(Type Array[], int size)
{
	for (int i = 0; i < size; ++i)
		std::cout << Array[i] << ' ';
	std::cout << std::endl;
}

template <typename Type>
void copyArray(Type source[], Type destination[], int size)
{
	for (int i = 0; i < size; ++i)
		destination[i] = source[i];
}

template <typename Type>
bool Greater(Type left, Type right)
{
	return left > right;
}

template <typename Type>
int binarySearchRecursive(Type Array[], int size, Type val)
{
	if (size == 0) return -1;
	int middle = size / 2;
	if (Array[middle] == val)
		return middle;

	if (middle == 0)
		return -1;

	if (Array[middle] > val)
		return binarySearchRecursive(Array, middle, val);
	
	int idx = binarySearchRecursive(Array + middle + 1, size - middle - 1, val);
	return idx >=0 ? middle + 1 + idx : idx;
}

template <typename Type>
int binarySearchIterative(Type Array[], int size, Type val)
{
	int leftBound = 0;
	int rightBound = size - 1;
	int middle = (leftBound + rightBound) / 2;
	while (leftBound <= rightBound)
	{
		if (Array[middle] == val) 
			return middle;
		if (Array[middle] > val)
			rightBound = middle - 1;
		else
			leftBound = middle + 1;
		middle = (leftBound + rightBound) / 2;
	}
	return -1;
}

template <typename Type>
int binarySearchForSort(Type Array[], int size, Type val)
{
	int leftBound = 0;
	int rightBound = size - 1;
	int middle = (leftBound + rightBound) / 2;
	while (leftBound < rightBound)
	{
		if (Array[middle] > val)
			rightBound = middle - 1;
		else
			leftBound = middle + 1;
		middle = (leftBound + rightBound) / 2;
	}
	return middle;
}

void qSortKiller(double* Array, int size)
{
	int* origidx = new int[size];
	for (int i = 0; i < size; i++)
		origidx[i] = i;

	int rPos = size - 1;

	for (int lPos = 0; lPos < rPos; ++lPos)
	{
		int pivotIdx = (rPos + lPos + 1) / 2;
		Swap(origidx[lPos], origidx[pivotIdx]);
	}

	for (int i = 0; i < size; i++)
	{
		int idx = origidx[i];
		Array[idx] = (double)i/ size;
	}

	delete[] origidx;
}