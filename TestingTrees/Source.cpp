#include <iostream>
#include "../Dictionary/BinTree.h"
#include "../Dictionary/AvlTree.h"

//typedef BinTree<int> Container;
typedef AvlTree<int> Container;

int main()
{
	Container tree;
	for (int i = 9; i >= 0; --i)
		tree.push_back(i);

	std::cout << "HEIGHT: " << tree.height() << std::endl;

	for (auto it = tree.begin(); it != tree.end(); ++it)
		std::cout << *it << std::endl;

	system("pause");
	return 0;
}