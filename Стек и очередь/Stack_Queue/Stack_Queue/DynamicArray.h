#pragma once
#include <iostream>
using std::cerr;
using std::endl;
using std::initializer_list;

template <typename TValue>
class DynamicArray
{
public:

	DynamicArray(initializer_list<TValue> list)
	{
		_size = list.size();
		_arr = new TValue[_size];

		auto pEl = list.begin();

		for (size_t i = 0; i < _size; i++)
		{
			_arr[i] = *pEl;
			pEl++;
		}
	}

	DynamicArray()
	{
		_arr = nullptr;
		_size = 0;
	}

	DynamicArray(size_t size)
	{
		_arr = new TValue[size]{};
		_size = size;
	}

	~DynamicArray()
	{
		if (_arr != nullptr)
		{
			delete[] _arr;
			_size = 0;
			_arr = nullptr;
		}
	}

	DynamicArray(const DynamicArray& obj)
	{
		Copy(obj);
	}

	DynamicArray& operator= (const DynamicArray& obj)
	{
		if (this == &obj)
			return *this;

		this->~DynamicArray();

		Copy(obj);
	}

	TValue& operator[](size_t index)
	{
		if (index >= _size)
		{
			cerr << "Error: index out of range." << endl;
			return _arr[0];
		}

		return _arr[index];
	}

	TValue operator[](size_t index) const
	{
		if (index >= _size)
		{
			cerr << "Error: index out of range." << endl;
			return _arr[0];
		}

		return _arr[index];
	}

	void AddElement(TValue value)
	{
		TValue* tmp = new TValue[_size + 1];
		
		for (size_t i = 0; i < _size; i++)
		{
			tmp[i] = _arr[i];
		}
		
		tmp[_size] = value;

		delete[] _arr;
		_arr = tmp;
		_size++;
	}

	void RemoveLastElement()
	{
		TValue* tmp = new TValue[_size - 1];

		for (size_t i = 0; i < _size - 1; i++)
		{
			tmp[i] = _arr[i];
		}

		delete[] _arr;
		_arr = tmp;
		_size--;

	}

	void RemoveFirstElement()
	{
		TValue* tmp = new TValue[_size - 1];

		for (size_t i = 0; i < _size - 1; i++)
		{
			tmp[i] = _arr[i + 1];
		}

		delete[] _arr;
		_arr = tmp;
		_size--;

	}

	void RamoveAt(size_t index)
	{
		TValue* tmp = new TValue[_size - 1];

		for (size_t i = 0; i < _size - 1; i++)
		{
			if (i < index)
			{
				tmp[i] = _arr[i];
			}
			else
			{
				tmp[i] = _arr[i + 1];
			}
		}

		delete[] _arr;
		_arr = tmp;
		_size--;
	}

	size_t GetSize() const
	{
		return _size;
	}

private:
	TValue* _arr;
	size_t  _size;

	void Copy(const DynamicArray& obj)
	{
		_arr = new TValue[obj._size];
		_size = obj._size;

		for (size_t i = 0; i < obj._size; i++)
		{
			_arr[i] = obj._arr[i];
		}
	}
};


