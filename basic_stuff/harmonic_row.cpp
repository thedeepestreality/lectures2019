#include <iostream>

int main()
{
	int N, i;
	double sum = 0;
	std::cout << "Input N: ";
	std::cin >> N;
	
	//For without body
	//for (int i = 1; i <= N; ++i, sum += 1.0/i);

	for (i = 1; i <= N; ++i)
		sum += 1.0 / i;
	std::cout << "FOR-LOOP: " << sum << std::endl;
	i = sum = 0;

	while (++i <= N)
		sum += 1.0/i;
	std::cout << "WHILE-LOOP: " << sum << std::endl;
	sum = 0;
	i = 1;

	do
		sum += 1.0 / i;
	while (++i <= N);
	std::cout << "DO-WHILE-LOOP: " << sum << std::endl;

	system("pause");
	return 0;
}