#include <iostream>
#include "base64.h"

int main()
{
	char* encoded = base64Encode("666", 3);
	std::cout << encoded << std::endl;
	system("pause");
	return 0;
}