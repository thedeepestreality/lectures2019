#pragma once

template <typename T>
class TemplateContainer
{
	T* vals;
	int size;
public:
	//...some code...
};

template <typename T = int,
	template<typename> typename V = TemplateContainer>
class Test
{
public:
	void foo()
	{
		V<T> z;
	}
};