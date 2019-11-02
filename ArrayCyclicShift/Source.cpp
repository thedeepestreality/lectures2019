#include <iostream>

void rev(char str[], int shift)
{
	int sz = strlen(str);
	char* buf = new char[sz];
	shift = shift % sz;
	memcpy_s(buf, sz, str, sz);

	if (shift >= 0)
	{
		memcpy_s(str, sz,
			buf + sz - shift, shift);
		memcpy_s(str + shift, sz,
			buf, sz - shift);
	}
	else
	{
		shift = -shift;
		memcpy_s(str + sz - shift,
			sz, buf, shift);
		memcpy_s(str, sz, buf + shift,
			sz - shift);
	}

	delete[] buf;
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		std::cout << "Usage: ArrayCyclicShift.exe <string> <shift>" << std::endl;
		return 0;
	}

	rev(argv[1], atoi(argv[2]));
	std::cout << argv[1] << std::endl;
	system("pause");
	return 0;
}