#include <iostream>
#include <vector>

//auto_ptr
//unique_ptr
template <typename Type>
class UniquePtr
{
	Type* _ptr;
public:
	UniquePtr(Type* ptr) : _ptr(ptr) {}
	~UniquePtr() { delete _ptr; }
	UniquePtr(const UniquePtr&) = delete;
	UniquePtr& operator=(const UniquePtr&) = delete;
	UniquePtr(UniquePtr&& ptr)
	{
		_ptr = ptr._ptr;
		ptr._ptr = nullptr;
	}

	UniquePtr& operator=(UniquePtr&& ptr)
	{
		if (_ptr != nullptr) delete _ptr;
		_ptr = ptr._ptr;
		ptr._ptr = nullptr;
	}
};

class Dummy
{

};

class Test
{
	std::weak_ptr<Dummy> ptr;
public:
	void test()
	{
		if (!ptr.expired())
			auto shared_ptr = ptr.lock();
		std::weak_ptr<int> tt = std::make_shared<int>();
		//...
	}
};

//std::shared_ptr
template <typename Type>
class SharedPtr
{
	Type* _ptr;
	size_t* _ptr_count;
public:
	SharedPtr(Type* ptr)
	{
		_ptr = ptr;
		_ptr_count = new int(1);
	}
	SharedPtr(const SharedPtr& sp)
	{
		_ptr = sp._ptr;
		_ptr_count = sp._ptr_count;
		++(*_ptr_count);
	}
	~SharedPtr()
	{
		--(*_ptr_count);
		if ((*_ptr_count) == 0)
		{
			delete _ptr;
			delete _ptr_count;
		}
	}

};

//std::weak_ptr

template <typename Type>
UniquePtr<Type> make_unique() 
{
	return UniquePtr<Type>(new Type());
}

//almost canonical make_shared realization
template <typename Type, typename... Args>
SharedPtr<Type> make_shared(Args&& ...args)
{
	return SharedPtr<Type>(new Type(std::forward<Args>(args)));
}

void bar(int x, std::unique_ptr<Dummy> d)
{

}

int get_int()
{
	//possible throwing code
	return 1;
}

void foo()
{
	/*
		//possible memory leak
		Dummy* ptr = new Dummy();
		bar();
		delete ptr;
	*/
	UniquePtr<Dummy> a_ptr(new Dummy());
	UniquePtr<Dummy> ptr2 = std::move(a_ptr);
	std::shared_ptr<Dummy> up = std::make_shared<Dummy>();
	std::weak_ptr<Dummy> wp = up;

	//still possible memory leak
	//bar(get_int(), UniquePtr<Dummy>(new Dummy()));
	bar(get_int(), std::make_unique<Dummy>());
}

int main()
{
	std::vector<int> vec = { 1, 2, 3 };
	//iterating by value
	for (int val : vec)
		val = 1;
	//iterating by reference
	for (int& val : vec)
		val = 1;
	//iterating by const ref
	for (const int& val : vec)
		std::cout << val << std::endl;

	for (auto val : vec)
		std::cout << val << std::endl;

	std::weak_ptr<Dummy> wp;
	{
		auto sp = std::make_shared<Dummy>();
		wp = sp;
	}
	std::cout << (wp.lock() == nullptr) << std::endl;


	//how to make smart ptr to dynamic array?
	//1) unique_ptr -- easy since c++14
	int sz = 10;
	auto dyn_unique = std::make_unique<int[]>(sz);
	dyn_unique[0] = 2;
	dyn_unique[1] = 3;

	//2) shared_ptr -- will do the same since c++20
	//for now we co use custom deleter:
	std::shared_ptr<int[]> dyn_shared(new int[sz],[](int* p){delete[] p;});
	dyn_shared[0] = -2;
	dyn_shared[1] = 4;

	//3) alternatively -- create shared ptr from unique
	std::shared_ptr<int[]> shared_from_unique = std::make_unique<int[]>(sz);
	//or
	std::shared_ptr<int[]> shared_capture = std::move(dyn_unique);

	system("pause");
	return 0;
}