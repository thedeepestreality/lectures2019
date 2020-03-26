#pragma once

template <typename T, int size>
class ClassTemplate
{
public:
	static int n;
	void f();
};

template<typename T, int size>
int ClassTemplate<T, size>::n = 0;

template<typename T, int size>
void ClassTemplate<T, size>::f()
{
	T x;
	//This will cause error only if
	//instantiate template with type that
	//doesn't have method foo()
	x.foo();
}