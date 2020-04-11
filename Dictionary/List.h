#pragma once

template <typename Type>
class List
{
	struct Node 
	{
		Type data;
		Node* next;
		Node(const Type& dat) : data(dat), next(nullptr) {}
	};
	Node* _first;
	Node* _last;
	size_t _size;
	void copy(const List& list)
	{
		clear();
		Node* curr_node = list._first;
		while (curr_node)
		{
			push_back(curr_node->data);
			curr_node = curr_node->next;
		}
	}
public:
	List() :_first(nullptr), _last(nullptr), _size(0) {}
	List(const List& list) : List()
	{
		copy(list);
	}
	void push_back(const Type& elem)
	{
		if (_size == 0)
		{
			_first = _last = new Node(elem);
		}
		else
		{
			_last->next = new Node(elem);
			_last = _last->next;
		}
		++_size;
	}
	void clear()
	{
		Node* curr_node;
		while (_first)
		{
			curr_node = _first;
			_first = _first->next;
			delete curr_node;
		}
		_size = 0;
		_last = nullptr;
	}
	void empty() { clear(); }
	~List() { clear(); }
	List& operator=(const List& list)
	{
		copy(list);
	}
	size_t size() const { return _size; }
	size_t capacity() const { return -1; }
	const Type& operator[](size_t idx) const
	{
		if (idx >= _size) throw "out of bounds";
		Node* curr_node = _first;
		for (size_t curr_idx = 0; curr_idx < idx; ++curr_idx)
			curr_node = curr_node->next;
		return curr_node->data;
	}

	class iterator
	{
		Node* _curr_node;
	public:
		iterator(Node* curr_node = nullptr) : _curr_node(curr_node) {}
		Type& operator*() const { return _curr_node->data; }
		bool operator==(const iterator& it) const { return _curr_node == it._curr_node; }
		bool operator!=(const iterator& it) const { return !(*this == it); }
		iterator& operator++()
		{
			if (!_curr_node) throw "iterator out of bounds";
			else _curr_node = _curr_node->next;
			return *this;
		}
		iterator operator++(int)
		{
			Node* curr = _curr_node;
			if (!_curr_node) throw "iterator out of bounds";
			else _curr_node = _curr_node->next;
			return iterator(curr);
		}
	};

	iterator begin() const { return iterator(_first); }
	iterator end() const { return iterator(); }

	iterator find(const Type& elem) const
	{
		Node* curr = _first;
		while (curr)
		{
			if (curr->data == elem)
				return iterator(curr);
			curr = curr->next;
		}
		return end();
	}
};

