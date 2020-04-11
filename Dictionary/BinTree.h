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
	void push_back(const Type& elem)
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
	};

	iterator begin() const
	{
		if (_root) return iterator(_root->minimum());
		return end();
	}
	iterator end() const { return iterator(nullptr); }

	iterator find(const Type& elem) const
	{
		Node* curr = _root;
		while (curr)
		{
			if (elem == curr->data) break;
			curr = elem < curr->data ? curr->left : curr->right;
		}
		return iterator(curr);
	}
};