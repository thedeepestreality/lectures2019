#include <iostream>

template <typename Type>
void rev(Type str[], int sz, int shift)
{
	int typeSize = sizeof(Type);
	Type* buf = new Type[sz];
	shift = shift % sz;
	memcpy_s(buf, sz * typeSize, str, sz * typeSize);

	if (shift >= 0)
	{
		memcpy_s(str, sz * typeSize,
			buf + sz - shift, shift * typeSize);
		memcpy_s(str + shift, sz * typeSize,
			buf, (sz - shift) * typeSize);
	}
	else
	{
		shift = -shift;
		memcpy_s(str + sz - shift, sz * typeSize, 
				buf, shift * typeSize);
		memcpy_s(str, sz * typeSize,
			buf + shift, (sz - shift) * typeSize);
	}

	delete[] buf;
}

//Специализация шаблона
//Для типа char будет вызываться эта версия
template <>
void rev<char>(char str[], int sz, int shift)
{
	char* buf = new char[sz];
	shift = shift % sz;
	memcpy_s(buf, sz, str, sz);

	if (shift >= 0)
	{
		memcpy_s(str, sz,
			buf + sz - shift, shift);
		memcpy_s(str + shift, sz ,
			buf, sz - shift);
	}
	else
	{
		shift = -shift;
		memcpy_s(str + sz - shift, sz,
			buf, shift);
		memcpy_s(str, sz,
			buf + shift, sz - shift);
	}

	delete[] buf;
}

//То же можно сделать через перегрузку функций,
//эффект будет тот же
//void rev(char str[], int sz, int shift)
//{
//	char* buf = new char[sz];
//	shift = shift % sz;
//	memcpy_s(buf, sz, str, sz);
//
//	if (shift >= 0)
//	{
//		memcpy_s(str, sz,
//			buf + sz - shift, shift);
//		memcpy_s(str + shift, sz,
//			buf, sz - shift);
//	}
//	else
//	{
//		shift = -shift;
//		memcpy_s(str + sz - shift, sz,
//			buf, shift);
//		memcpy_s(str, sz,
//			buf + shift, sz - shift);
//	}
//
//	delete[] buf;
//}


int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		std::cout << "Usage: ArrayCyclicShift.exe <string> <shift>" << std::endl;
		return 0;
	}

	rev(argv[1], strlen(argv[1]), atoi(argv[2]));
	std::cout << argv[1] << std::endl;

	double arr[5] = { 1.5, 3.14, 2.71, 0, 1};
	rev(arr, 5, 2);
	for (int i = 0; i < 5; ++i)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;

	system("pause");
	return 0;
}