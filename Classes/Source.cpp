#include <iostream>

class DynArray
{
private:
	int* _arr;
	int _size;
	int _capacity;

	void init(int size)
	{
		this->_capacity = size;
		_arr = new int[_capacity];
		_size = 0;
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

	DynArray(int size, int elem)
	{
		init(size);
		for (; _size < _capacity; ++_size)
			_arr[_size] = elem;
	}

	DynArray(DynArray const& source) : DynArray(source._size)
	{
		for (int i = 0; i < _size; ++i)
			_arr[i] = source._arr[i];
	}

	~DynArray()
	{
		if (_capacity > 0)
			delete[] _arr;
	}

	void print() const
	{
		for (int i = 0; i < _size; ++i)
			std::cout << _arr[i] << " ";
		std::cout << std::endl;
	}

	int size() const
	{
		return _size;
	}

	int capacity() const
	{
		return _capacity;
	}

	int& getElem(int idx) const
	{
		if (idx < 0 || idx >= _size)
			throw "index out of bounds";

		return _arr[idx];
	}

	DynArray& push_back(int val)
	{
		if (_size < _capacity)
			_arr[_size++] = val;
		else
		{
			_capacity *= 2;
			int* tmp = new int[_capacity];
			for (int i = 0; i < _size; ++i)
				tmp[i] = _arr[i];
			delete[] _arr;
			_arr = tmp;
		}
		return *this;
	}
};

void print(DynArray& arrObj)
{
	for (int i = 0; i < arrObj.size(); ++i)
		std::cout << arrObj.getElem(i) << " ";
	std::cout << std::endl;
}

void print(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}
int main()
{
	DynArray arrObj(10);
	//arrObj.init(10);
	arrObj.print();

	const DynArray constArr(3, 0);
	constArr.getElem(1) = 2;
	std::cout << constArr.getElem(1) << std::endl;

	////WARNING!
	////Dirty hack to break private fields
	//DynArray arr1; //default constructor
	//int* hack = (int*) &arr1;
	//hack[2] = 55;
	//std::cout << arr1.capacity() << std::endl;

	DynArray copyArr = arrObj;
	
	system("pause");
	return 0;
}