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
	for (int i = 9; i >= 0; --i)
		tree.push_back(i);

	//std::cout << "HEIGHT: " << tree.height() << std::endl;

	//for (auto it = tree.begin(); it != tree.end(); ++it)
	//	std::cout << *it << std::endl;

	tree.erase(5);
	tree.push_back(0);
	std::cout << "FOUND: " << tree.find(8) << std::endl;
	tree.print();

	system("pause");
	return 0;
}