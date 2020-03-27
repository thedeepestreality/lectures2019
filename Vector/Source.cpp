#include <iostream>
#include "Vector.h"

int main()
{
	Vector<int> vec(3);
	for (int i = 0; i < 15; ++i)
		vec.push_back(i);
	for (int i = 0; i < 15; ++i)
		//std::cout << *(&vec[0]+i) << std::endl;
		std::cout << vec[i] << std::endl;
	//Vector<int>::iterator it;
	for (auto it = vec.begin();it != vec.end();++it)
		std::cout << *it << std::endl;

	//x[i] == *(x + i);
	system("pause");
	return 0;
}