#include <iostream>

typedef unsigned long long ull;

ull factorialIter(int N)
{
	ull prod = 1;
	for (int i = 2; i <= N; ++i)
		prod *= i;
	return prod;
}

ull factorialRec(int N)
{
	if (N <= 1) return 1;

	return N * factorialRec(N - 1);
}

void hanoi(int n, int from = 1, int to = 2, int tmp = 3)
{
	if (n > 1)
	{
		hanoi(n - 1, from, tmp, to);
		hanoi(1, from, to);
		hanoi(n - 1, tmp, to, from);
	}
	else
		std::cout << from << " -> " << to << std::endl;
}

int main()
{
	std::cout << factorialIter(5) << std::endl;
	std::cout << factorialRec(5) << std::endl;

	hanoi(4);

	system("pause");
	return 0;
}