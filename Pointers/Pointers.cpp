#include <iostream>

int main() 
{
	//ќбычна¤ переменна¤ типа double
	double x = 12345.6;
	std::cout << "         x = " << x << std::endl;
	std::cout << " sizeof(x) = " << sizeof(x) << std::endl;

	//”казатель на переменную типа double
	double* px;
	//ѕолучаем адрес переменной x и записываем в указатель px
	px = &x;
	//«начение указател¤ = адрес 
	std::cout << "        px = " << px << std::endl;
	//–азмера указател¤: 4 байта на x32 системах,
	//8 байт на x64 системах
	std::cout << "sizeof(px) = " << sizeof(px) << std::endl;
	//–азыменование указател¤: получаем значение по адресу
	std::cout << "       *px = " << *px << std::endl;

	//¬ указатель можно записать адрес другой переменной
	double y = 4.56;
	px = &y;
	std::cout << "        y = " << y << std::endl;
	std::cout << "        px = " << px << std::endl;
	//“еперь при разыменовании мы получаем значение переменной y
	std::cout << "       *px = " << *px << std::endl;
	//„ерез указатель можно также и мен¤ть значение переменной
	*px = 1.23;
	std::cout << "        y = " << y << std::endl;

	system("pause");
	return 0;
}