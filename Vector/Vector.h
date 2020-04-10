#pragma once

template <typename Type>
class Vector
{
private:
	size_t _size;
	size_t _capacity;
	Type* _data;
	bool _is_sorted;
	void quick_sort(Type*, size_t);
public:
	Vector(size_t capacity = 0);
	Vector(const Vector& vec);
	~Vector() { clear(); }

	size_t size() const { return _size; }
	size_t capacity() const { return _capacity; }

	void clear();
	void empty();
	void sort();
	
	Vector& operator=(const Vector& vec);
	Type& operator[](size_t idx) const;
	Vector& push_back(const Type& elem);
	Vector& resize(size_t new_size);

	class iterator
	{
	private:
		Type* _element;
	public:
		iterator(Type* elem = nullptr) : _element(elem) {}
		Type& operator*() { return *_element; }
		Type& operator*() const { return *_element; }
		bool operator==(const iterator& it) const 
		{ return _element == it._element; }
		bool operator!=(const iterator& it) const
		{ return !(*this == it);}
		iterator& operator++()
		{
			++_element;
			return *this;
		}
		iterator operator++(int)
		{
			Type* tmp = _element;
			++_element;
			return iterator(tmp);
		}
	};
	
	iterator begin() const { return iterator(_data); }
	iterator end() const { return iterator(_data + _size); }

	class reverse_iterator {};
	iterator rbegin() const {}
	iterator rend() const {};

	iterator find(const Type& val) const;
};

template <typename Type>
Vector<Type>::Vector(size_t capacity) : _size(0),
									_capacity(capacity),
									_data(nullptr)
{
	if (capacity > 0)
	{
		_data = new Type[capacity];
		if (!_data) throw "Out of memory";
	}
}

template <typename Type>
Vector<Type>::Vector(const Vector& vec) : _size(0),
							_capacity(capacity),
							_data(nullptr)
{
	if (capacity > 0)
	{
		_data = new Type[capacity];
		if (!_data) throw "Out of memory";
	}
}

template <typename Type>
void Vector<Type>::clear()
{
	if (_data) delete[] _data;
	_data = nullptr;
	_size = _capacity = 0;
}

template <typename Type>
void Vector<Type>::empty()
{
	_size = 0;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator=(const Vector& vec)
{
	if (this != &vec)
	{
		_size = vec._size;
		_capacity = vec._capacity;
		if (_data) delete[] _data;
		_data = new Type[_capacity];
		if (!_data) throw "Out of memory";
		for (int i = 0; i < _size; ++i)
			_data[i] = vec._data[i];
	}
	return *this;
}

template<typename Type>
Type& Vector<Type>::operator[](size_t idx) const
{
	if (idx >= _size) throw "Out of bounds";
	return _data[idx];
}

template<typename Type>
Vector<Type>& Vector<Type>::push_back(const Type& elem)
{
	if (_size == _capacity)
	{
		if (_capacity < 10)
			resize(_capacity + 10);
		else
			resize(_capacity*1.5);
		//resize(_capacity < 10 ? _capacity + 10 : 1.5*_capacity);
	}
	_data[_size++] = elem;
	return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::resize(size_t new_size)
{
	_capacity = new_size;
	_size = _capacity < _size ? _capacity : _size;
	Type* tmp = new Type[_capacity];
	if (!tmp) throw "Out of memory";
	for (int i = 0; i < _size; ++i)
		tmp[i] = _data[i];
	if (!_data)
		delete[] _data;
	_data = tmp;
}

template <typename Type>
typename Vector<Type>::iterator Vector<Type>::find(const Type& val) const 
{
	for (unsigned int i = 0; i < _size; ++i)
		if (_data[i] == val) return iterator(_data + i);
	return end();
}

//------------------------------------

template <>
class Vector<bool>
{
private:
	typedef unsigned char byte;
	size_t _size;
	size_t _capacity;
	size_t _byte_size;
	byte* _data;
public:
	Vector(size_t capacity = 0) : _size(0),
							_capacity(capacity),
							_byte_size(0),
							_data(nullptr)
	{
		if (capacity > 0)
		{
			_data = new byte[capacity/8 + (capacity%8 != 0)];
			if (!_data) throw "Out of memory";
		}
	}

	class VecProxy
	{
		size_t _idx;
		byte* _vec_ptr;
	public:

		VecProxy(size_t idx, unsigned char* vecPtr) : _idx(idx), _vec_ptr(vecPtr) {}
		VecProxy& operator=(bool val)
		{
			size_t char_idx = _idx / 8;
			size_t bit_idx = _idx % 8;
			if (val)
				_vec_ptr[char_idx] |= 1 << bit_idx;
			else
				_vec_ptr[char_idx] &= ~(1 << bit_idx);
			return *this;
		}

		operator bool()
		{
			size_t char_idx = _idx / 8;
			size_t bit_idx = _idx % 8;
			return (_vec_ptr[char_idx] >> char_idx) & 0x01;
		}
	};

	VecProxy operator[](size_t idx)
	{
		if (idx >= _size) throw "Out of bounds";
		return VecProxy(idx, _data);
	}

	Vector& resize(size_t new_size)
	{
		_capacity = new_size;
		_size = _capacity < _size ? _capacity : _size;
		_byte_size = _size / 8 + (_size % 8 != 0);
		byte* tmp = new byte[_capacity / 8 + (_capacity % 8 != 0)];
		if (!tmp) throw "Out of memory";
		for (size_t i = 0; i < _byte_size; ++i)
			tmp[i] = _data[i];
		if (!_data)
			delete[] _data;
		_data = tmp;
	}

	Vector& push_back(bool val)
	{
		if (_size == _capacity)
		{
			if (_capacity < 10)
				resize(_capacity + 10);
			else
				resize(_capacity * 1.5);
		}
		VecProxy(_size++, _data) = val;
		return *this;
	}
};
