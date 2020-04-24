#pragma once

template <typename Type>
class BinTree
{
	struct Node
	{
		Node* parent;
		Node* left;
		Node* right;
		Type data;
		Node(const Type& dat) : parent(nullptr),
								left(nullptr),
								right(nullptr),
								data(dat) {}
		~Node()
		{
			if (left) delete left;
			if (right) delete right;
			left = right = nullptr;
		}

		Node* minimum()
		{
			Node* curr = this;
			while (curr->left != nullptr) curr = curr->left;
			return curr;
		}

		Node* next()
		{
			if (right != nullptr) return right->minimum();
			Node* pCurr = parent;
			Node* curr = this;
			while (pCurr != nullptr)
			{
				if (curr == pCurr->left) break;
				curr = pCurr;
				pCurr = pCurr->parent;
			}
			return pCurr;
		}

		size_t height() const
		{
			size_t left_h = (left == nullptr) ? 0 : left->height();
			size_t right_h = (right == nullptr) ? 0 : right->height();
			return left_h < right_h ? right_h + 1 : left_h + 1;
		}
	};
	Node* _root;
	size_t _size;
public:
	BinTree() : _root(nullptr), _size(0) {}
	~BinTree() { clear(); }
	void clear()
	{
		if (_root)
			delete _root;
		_root = nullptr;
	}
	void empty() { clear(); }
	size_t size() const { return _size; }
	size_t capacity() const { return -1; }
	size_t height() const {	return _root == nullptr ? 0 : _root->height(); }
	void push_back(const Type& elem);

	class iterator
	{
		Node* _curr;
	public:
		iterator(Node* curr = nullptr) : _curr(curr) {}
		Type& operator*() const { return _curr->data; }
		bool operator==(const iterator& it) const { return _curr == it._curr; }
		bool operator!=(const iterator& it) const { return !(*this == it); }
		iterator& operator++()
		{
			if (!_curr) throw "iterator out of bounds";
			_curr = _curr->next();
			return *this;
		}
		iterator operator++(int)
		{
			Node* prev = _curr;
			if (!_curr) throw "iterator out of bounds";
			_curr = _curr->next();
			return iterator(prev);
		}

		friend class BinTree;
	};

	iterator begin() const
	{
		if (_root) return iterator(_root->minimum());
		return end();
	}
	iterator end() const { return iterator(nullptr); }

	iterator find(const Type& elem) const;

	iterator erase(iterator pos);
};

template<typename Type>
void BinTree<Type>::push_back(const Type& elem)
{
	++_size;
	if (!_root)
	{
		_root = new Node(elem);
		return;
	}

	Node* curr = _root;
	Node* pCurr;
	do
	{
		pCurr = curr;
		curr = elem < curr->data ? curr->left : curr->right;
	} while (curr);
	curr = new Node(elem);
	curr->parent = pCurr;
	(elem < pCurr->data) ? (pCurr->left = curr) : (pCurr->right = curr);
}

template<typename Type>
typename BinTree<Type>::iterator BinTree<Type>::find(const Type& elem) const
{
	Node* curr = _root;
	while (curr)
	{
		if (elem == curr->data) break;
		curr = elem < curr->data ? curr->left : curr->right;
	}
	return iterator(curr);
}

template<typename Type>
typename BinTree<Type>::iterator BinTree<Type>::erase(iterator pos)
{
	Node* to_erase = pos._node;
	if (to_erase == nullptr) return pos;

	Node* replace;
	if (to_erase->left == nullptr)
		replace = to_erase->right;
	else if (to_erase->right == nullptr)
		replace = to_erase->left;
	else
	{
		replace = to_erase->right->minimum();
		if (replace->parent != to_erase)
		{
			replace->parent->left = replace->right;
			if (replace->right) replace->right->parent = replace->parent;
			replace->right = to_erase->right;
			to_erase->right->parent = replace;
		}
		replace->left = to_erase->left;
		to_erase->left->parent = replace;
	}

	if (to_erase->parent == nullptr)
		_root = replace;
	else
	{
		if (to_erase->parent->left == to_erase)
			to_erase->parent->left = replace;
		else
			to_erase->parent->right = replace;
	}

	if (replace != nullptr) replace->parent = to_erase->parent;

	to_erase->right = to_erase->left = nullptr;
	delete to_erase;
	--_size;

	return iterator(replace);
}