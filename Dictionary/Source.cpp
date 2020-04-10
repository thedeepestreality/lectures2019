#include <iostream>
#include "..\Vector\Vector.h"
#include "DictPair.h"
#include <fstream>
#include <time.h>

typedef Vector<DictPair> Container;

int main()
{
	setlocale(LC_ALL, "Rus");
	char fname[] = "dictionary-ru.txt";
	try 
	{
		std::ifstream inFile(fname);
		if (!inFile) throw "Can not open dictionary.";

		DictPair tmp;
		Container dictionary;
		clock_t tic = clock();
		while (inFile.peek() != EOF) {
			inFile >> tmp;
			dictionary.push_back(tmp);
		}
		inFile.close();
		std::cout << "Reading from file: " << (double)(clock() - tic)/CLOCKS_PER_SEC << " sec" << std::endl;
		std::cout << "Total: " << dictionary.size() << std::endl;

		char what[128];
		Container::iterator pos;

		//for (auto pos = dictionary.begin(); pos != dictionary.end(); ++pos)
		//	std::cout << *pos << std::endl;

		do {
			std::cout << "> "; 
			std::cin.getline(what, 128);
			if (strlen(what) < 1) 
				break;

			tic = clock();
			pos = dictionary.find(DictPair(what));
			std::cout << "Found at: " << (clock() - tic) / CLOCKS_PER_SEC << " sec" << std::endl;

			if (pos != dictionary.end())
				std::cout << *pos << std::endl;
			else
				std::cout << "There are no word '" << what << "' in dictionary" << std::endl;

		} while (1);
	}
	catch (const char* error) {
		std::cout << "Error: " << error << std::endl;
	}
	catch (...) {
		std::cout << "Unknown error" << std::endl;
	}
	system("pause");
	return 0;
}