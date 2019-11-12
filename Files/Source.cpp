#include <iostream>
#include <fstream>

void copyFile(const char* in, const char* out)
{
	std::ofstream fout;
	std::ifstream fin;
	fout.open(out);
	if (!fout.is_open())
		throw "Failed to open out file";
	fin.open(in);
	if (!fin.is_open())
		throw "Failed to open in file";

	char c = fin.get();
	while (!fin.eof())
	{
		fout << c;
		c = fin.get();
	}

	fout.close();
	fin.close();
}

int main()
{
	std::ofstream fout;
	std::ifstream fin;
	//Открыть файл в режиме дописывания в конец
	//fout.open("out.txt",std::ios::app);
	fout.open("out.txt");
	if (!fout.is_open())
	{
		std::cout << "Output file error" << std::endl;
		system("pause");
		return 0;
	}

	//Ввод-вывод работает аналогично std::cout и std::cin
	//fout << "Hello file!" << std::endl;
	//fout << 22 << ' ' << 3.1415 << "=pi" << true << std::endl;

	fin.open("test.txt");
	if (!fin.is_open())
	{
		std::cout << "Input file error" << std::endl;
		system("pause");
		return 0;
	}

	char str[64];
	//Считывает слово до первого пробела/перехода на новую строчку
	//fin >> x;

	//Считает либо 64 символа, либо меньше, если наткнется
	//на переход на новую строчку
	fin.get(str, 64);
	std::cout << str << std::endl;
	//При этом символ перехода не удалит,
	//так что читаем вручную один символ -- этот как раз символ перехода
	fin.get();
	//Теперь будет нормальная строка
	fin.get(str, 64);
	std::cout << str << std::endl;

	//getline делает то же самое, только удаляет переход на новую строку
	//fin.getline(str, 64);
	//std::cout << str << std::endl;
	//так что этот вызов даст сразу вторую строку из файла
	//fin.getline(str, 64);
	//std::cout << str << std::endl;

	fin.close();
	fout.close();

	try 
	{
		copyFile("in.txt", "out.txt");
	}
	catch(const char* errorMsg)
	{
		std::cout << errorMsg << std::endl;
	}

	system("pause");
	return 0;
}