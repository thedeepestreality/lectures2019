#include <iostream>

//Шаблон функции
template <typename Type>
Type sqr(Type x)
{
	return x * x;
}

//Специализация шаблона
//Т.е. описание специального случая для конкретного типа
template<>
int sqr<int>(int x)
{
	return 2*x * x;
}

//Шаблон -- это не функция, это указание компилятору на то,
//как конструировать функции. Например, в примере ниже статическая
//переменная будет иметь разные значения у функций разных типов
template<typename Type>
int printCount(Type x)
{
	std::cout << x << std::endl;
	static int counter = 0;
	return ++counter;
}

//В шаблоны можно передавать несколько параметров
//А еще в шаблонах семантические ошибки можно отловить
//только в момент первого вызова шаблона с данными типами
template <typename T, typename R>
void printTwoParams(T param1, R param2)
{
	T var = 0;
	R vanina = 0;
	int x = var * vanina;
	std::cout << param1 << ' ' << param2 << std::endl;
}

int main()
{

	std::cout << sqr<double>(0.5) << std::endl;
	//Здесь вызовется специализация шаблона
	std::cout << sqr<int>(2) << std::endl;
	//Если по аргументам понятно, какой тип у шаблона,
	//то тип можно не указывать
	std::cout << sqr(5) << std::endl;

	//Пример со статической переменной в шаблоне функции
	std::cout << printCount(3) << std::endl;
	std::cout << printCount(2) << std::endl;
	//Другой тип -- статическая переменная будет заполняться отдельно
	std::cout << printCount(2.5) << std::endl;

	//Пример с двумя параметрами
	double x1 = 1, x2 = 2;
	printTwoParams(x1, x2);

	//А тут возникнет ошибка, потому что перемножать указатели нельзя
	//double *px1, *px2;
	//printTwoParams(px1, px2);

	system("pause");
	return 0;
}