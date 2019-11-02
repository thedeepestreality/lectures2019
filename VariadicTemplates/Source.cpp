#include <iostream>

//База рекурсии -- шаблон функции с единственным параметром
template <typename Type>
Type sum(Type arg)
{
	return arg;
}

//Рекурсивное разворачивание шаблона с переменным
//числом аргументов
template <typename Type, typename ... Args>
double sum(Type arg1, Args... args)
{
	return arg1 + sum(args...);
}

//Возведение в квадрат
template <typename Type>
Type square(Type arg)
{
	return arg*arg;
}

//Сумма квадратов (используем уже написанный шаблон функции sum)
template <typename Type, typename... Args>
double squaresSum(Type arg, Args... args)
{
	return square(arg) + sum(square(args)...);
}

int main()
{
	std::cout << sum(4, 4.5, -1, true) << std::endl;
	std::cout << squaresSum(0.5, 2, -8, false) << std::endl;
	system("pause");
	return 0;
}