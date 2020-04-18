#pragma once

template <typename Type>
class AvlTree
{
	enum class Direction {Left, Right};
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

		signed char balance()
		{
			size_t left_h = (left == nullptr) ? 0 : left->height();
			size_t right_h = (right == nullptr) ? 0 : right->height();
			return right_h - left_h;
		}
	};
	Node* _root;
	size_t _size;
	void rebalance(Node* sub_root);
	Node* rotate(Node* sub_root, Direction dir);
public:
	AvlTree() : _root(nullptr), _size(0) {}
	~AvlTree() { clear(); }
	void clear()
	{
		if (_root)
			delete _root;
		_root = nullptr;
	}
	void empty() { clear(); }
	size_t size() const { return _size; }
	size_t capacity() const { return -1; }
	size_t height() const { return _root == nullptr ? 0 : _root->height(); }
	
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
		
		rebalance(curr);
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

template<typename Type>
void AvlTree<Type>::rebalance(Node* sub_root)
{
	do
	{
		sub_root = sub_root->parent;
		switch (sub_root->balance())
		{
			//right disbalance
			case 2:
			{
				//right-left situation
				if (sub_root->right->balance() == -1)
					rotate(sub_root->right, Direction::Right);
				//right-right
				sub_root = rotate(sub_root, Direction::Left);
				break;
			}
			//left disbalance
			case -2:
			{
				//left-right situation
				if (sub_root->left->balance() == 1)
					rotate(sub_root->left, Direction::Left);
				//left-left
				sub_root = rotate(sub_root, Direction::Right);
				break;
			}
		}
		if (sub_root->parent == nullptr)
			_root = sub_root;
	} while (sub_root != _root && sub_root->balance() != 0);
}

template<typename Type>
typename AvlTree<Type>::Node* AvlTree<Type>::rotate(Node* sub_root, Direction dir)
{
	Node* child;
	if (dir == Direction::Right)
	{
		child = sub_root->left;
		sub_root->left = child->right;
		if (child->right != nullptr)
			child->right->parent = sub_root;
		child->right = sub_root;
	}
	else
	{
		child = sub_root->right;
		sub_root->right = child->left;
		if (child->left != nullptr)
			child->left->parent = sub_root;
		child->left = sub_root;
	}

	if (sub_root->parent != nullptr)
	{
		if (sub_root->parent->left == sub_root)
			sub_root->parent->left = child;
		else
			sub_root->parent->right = child;
	}

	Node* tmp = sub_root->parent;
	sub_root->parent = child;
	child->parent = tmp;

	return child;
}