#include <iostream>

class DynArray
{
private:
	int* _arr;
	int _size;

	void init(int size)
	{
		_size = size;
		_arr = new int[_size];
		for (int i = 0; i < _size; ++i)
			_arr[i] = 0;
	}

public:
	/* 
	//Конструктор по умолчанию
	DynArray() 
	{
		std::cout << "YA RODILSIA!!!" << std::endl;
		init(1);
	}
	*/

	DynArray(int size = 1)
	{
		init(size);
	}

	~DynArray()
	{
		if (_size > 0)
			delete[] _arr;
	}
	

	void print()
	{
		for (int i = 0; i < _size; ++i)
			std::cout << _arr[i] << " ";
		std::cout << std::endl;
	}
};

/*
void print(DynArray& arrObj)
{
	for (int i = 0; i < arrObj.size; ++i)
		std::cout << arrObj.arr[i] << " ";
	std::cout << std::endl;
}*/

void print(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}
int main()
{
	DynArray arr1;
	DynArray arrObj(10);
	//arrObj.init(10);
	arrObj.print();

	//delete[] arrObj.arr;
	system("pause");
	return 0;
}