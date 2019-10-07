#include <iostream>

void reverseString(char* str)
{
	int strSize = strlen(str);
	for (int i = 0; i < strSize / 2; ++i)
	{
		char tmp = str[i];
		str[i] = str[strSize - 1 - i];
		str[strSize - 1 - i] = tmp;
	}
}

void concatString(char* str1, char* str2, char* result)
{
	int strSize1 = strlen(str1);
	int strSize2 = strlen(str2);

	for (int i = 0; i < strSize1; ++i)
		result[i] = str1[i];

	for (int i = strSize1; i < strSize1 + strSize2; ++i)
		result[i] = str2[i - strSize1];

	result[strSize1 + strSize2] = '\0';
}

int main()
{
	char str1[64];
	char str2[64];
	//char strConcat[128];
	char strConcatStd[128];
	std::cout << "Input first string: ";
	std::cin >> str1;
	std::cout << "Input second string: ";
	std::cin >> str2;

	int strSize1 = strlen(str1);
	int strSize2 = strlen(str2);

	char* strConcat = new char[strSize1 + strSize2 + 1];

	std::cout << "SIZEOF: " << sizeof(str1) << std::endl;
	std::cout << "STRLEN: " << strSize1 << std::endl;

	reverseString(str1);
	reverseString(str2);
	concatString(str1, str2, strConcat);
	strcpy_s(strConcatStd, str1);
	strcat_s(strConcatStd, str2);

	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	std::cout << strConcat << std::endl;
	std::cout << strConcatStd << std::endl;

	//Example of absence of terminal symbol
	//char destroyer9000[4] = { 'H','e','l','l' };
	//std::cout << destroyer9000 << std::endl;
	
	delete[] strConcat;
	system("pause");
	return 0;
}