#include <iostream>

int main() 
{
	//Обычная переменная типа double
	double x = 12345.6;
	std::cout << "         x = " << x << std::endl;
	std::cout << " sizeof(x) = " << sizeof(x) << std::endl;

	//Указатель на переменную типа double
	double* px;
	//Получаем адрес переменной x и записываем в указатель px
	px = &x;
	//Значение указателя = адрес 
	std::cout << "        px = " << px << std::endl;
	//Размер указателя: 4 байта на x32 системах,
	//8 байт на x64 системах
	std::cout << "sizeof(px) = " << sizeof(px) << std::endl;
	//Разыменование указателя: получаем значение по адресу
	std::cout << "       *px = " << *px << std::endl;

	//В указатель можно записать адрес другой переменной
	double y = 4.56;
	px = &y;
	std::cout << "        y = " << y << std::endl;
	std::cout << "        px = " << px << std::endl;
	//Теперь при разыменовании мы получаем значение переменной y
	std::cout << "       *px = " << *px << std::endl;
	//Через указатель можно также и менять значение переменной
	*px = 1.23;
	std::cout << "        y = " << y << std::endl;

	system("pause");
	return 0;
}