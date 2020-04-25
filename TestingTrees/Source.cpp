#include <iostream>
#include "../Dictionary/BinTree.h"
#include "../Dictionary/AvlTree.h"
#include "BstRecursive.h"

//typedef BinTree<int> Container;
//typedef AvlTree<int> Container;
typedef BstRecursive<int> Container;

int main()
{
	Container tree;
	/*for (int i = 9; i >= 0; --i)
		tree.push_back(i);*/
	tree.push_back(6);

	tree.push_back(3);
	tree.push_back(8);

	tree.push_back(1);
	tree.push_back(4);
	tree.push_back(7);
	tree.push_back(9);

	//std::cout << "HEIGHT: " << tree.height() << std::endl;

	//for (auto it = tree.begin(); it != tree.end(); ++it)
	//	std::cout << *it << std::endl;

	/*tree.erase(5);
	tree.push_back(-1);
	std::cout << "FOUND: " << tree.find(8) << std::endl;*/
	tree.print();
	std::cout << std::endl;
	tree.print_bf_rec();

	system("pause");
	return 0;
}