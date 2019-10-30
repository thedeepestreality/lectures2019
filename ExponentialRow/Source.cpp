#include <iostream>

void eval(double x1, double dx, int N, double eps, double** result)
{
	for (int i = 0; i < N; ++i)
	{
		double curr = x1-1;
		double elem = x1-1;
		int n = 1;
		double sum = 1;
		while (abs((int)round(curr/eps)) >= 1
)
		{
			sum += curr;
			++n;
			curr *= elem / n;
		}
		result[0][i] = x1;
		result[1][i] = sum;
		x1 += dx;
	}
}

void print(double** table, int N)
{
	std::cout << "TABLE: " << std::endl;
	std::cout << "X\tRow\tExp" << std::endl;
	for (int i = 0; i < N; ++i)
	{
		std::cout << table[0][i] << '\t' << table[1][i] << '\t' << exp(table[0][i]-1)<< std::endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc < 5)
	{
		std::cout << "Must have 4 argumens" << std::endl;
	}

	double x1 = atof(argv[1]);
	double dx = atof(argv[2]);
	int N = atoi(argv[3]);
	double eps = atof(argv[4]);
	std::cout << "ARGUMENTS: " << std::endl;
	std::cout << x1 << ' ' << dx << ' ' << N << ' ' << eps << std::endl << std::endl;

	double* table[2] = { new double[N], new double[N] };
	eval(x1, dx, N, eps, table);
	print(table, N);

	//MAGIC! 0.3 != 0.3!
	//double x = 0.1 + 0.2;
	//std::cout.precision(32);
	//std::cout << 0.1 << ' ' << 0.2 << ' ' << std::endl;
	//std::cout << 0.3 <<' '<< x << ' ' << (x == 0.3) << std::endl;

	delete[] table[0];
	delete[] table[1];
	system("pause");
	return 0;
}