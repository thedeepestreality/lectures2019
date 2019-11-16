#include <iostream>
#include <fstream>

int main()
{
	std::fstream file;
	
	file.open("out.txt", 
		std::ios::binary | std::ios_base::out);
	int x = 257;
	
	char d0 = x;
	char d1 = x >> 8;
	char d2 = x >> 16;
	char d3 = x >> 24;
	char buf[4] = { d0, d1, d2, d3};
	file.write((char*)&x, 4);
	file.close();

	file.open("out.txt",
		std::ios::binary | std::ios_base::in);
	file.read(buf, 4);
	x = *((int*)buf);
	std::cout << x << std::endl;
	file.close();

	//Example of reading file size
	file.open("out.txt",
		std::ios::binary | std::ios_base::in);
	file.seekg(0, std::ios_base::end);
	int n = file.tellg();
	file.seekg(0, std::ios_base::beg);
	//std::ios_base::cur
	std::cout << n << std::endl;
	file.close();

	system("pause");
	return 0;
}