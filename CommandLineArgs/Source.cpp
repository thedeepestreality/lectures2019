#include <iostream>

int main(int argc, char* argv[], char* env[])
{
	for (int i = 0; i < argc; ++i)
	{
		std::cout << argv[i] << std::endl;
	}
	std::cout << "ENVIRONMENT" << std::endl;
	int j = 0;
	while (env[j] != NULL)
	{
		std::cout << env[j] << std::endl;
		++j;
	}

	//int sum = 0;
	//for (int i = 1; i < argc; ++i)
	//{
	//	sum += atoi(argv[i]);
	//}
	//std::cout << sum << std::endl;
	system("pause");
	return 0;
}