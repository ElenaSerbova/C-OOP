#include "DynamicArray.h"
#include <iostream>
#include <algorithm>
using namespace std;


DynamicArray::DynamicArray(size_t size, int value)
{
	_size = size;
	_arr = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		_arr[i] = value;
	}
}

DynamicArray::~DynamicArray()
{
	/*cout << "Destructor" << endl;
	cout << "_arr: " << _arr << endl;*/
	Clear();
}

void DynamicArray::Copy(const DynamicArray& sourceObj)
{
	_arr = new int[sourceObj._size];

	for (size_t i = 0; i < sourceObj._size; i++)
	{
		_arr[i] = sourceObj._arr[i];
	}

	_size = sourceObj._size;

	//cout << "Copy" << endl;
	//cout << "_arr: " << _arr << endl;
 }

DynamicArray::DynamicArray(const DynamicArray& sourceObj)
{
	//cout << "Constructor copy" << endl;
	//cout << "Source _arr: " << sourceObj._arr << endl;

	Copy(sourceObj);
}

DynamicArray& DynamicArray::operator=(const DynamicArray& sourceObj)
{
	if (this != &sourceObj) //проверка на самоприсваивание
	{
		Clear();
		Copy(sourceObj);
	}

	return *this;
}

DynamicArray::DynamicArray(DynamicArray&& sourceObj)
{
	this->_arr = sourceObj._arr;
	sourceObj._arr = nullptr;

	this->_size = sourceObj._size;
	sourceObj._size = 0;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& sourceObj)
{
	if (this != &sourceObj) //проверка на самоприсваивание
	{
		Clear();
		
		this->_arr = sourceObj._arr;
		sourceObj._arr = nullptr;

		this->_size = sourceObj._size;
		sourceObj._size = 0;
	}

	return *this;
	
}

size_t DynamicArray::GetSize() const
{
	return _size;
}

int DynamicArray::GetElement(size_t index) const
{
	if (index < _size)
	{
		return _arr[index];
	}
	else
	{
		cout << "Error: index out of range" << endl;
		return 0;
	}
}

void DynamicArray::SetElement(size_t index, int value)
{
	if (index >= _size)
	{
		cout << "Error: index out of range" << endl;
		return;
	}

	_arr[index] = value;
}

int& DynamicArray::operator[](size_t index)
{
	if (index >= _size)
	{
		cout << "Error: index out of range" << endl;
		static int res = 0;
		return res;
	}

	return _arr[index];
}

int DynamicArray::operator[](size_t index) const
{
	if (index >= _size)
	{
		cout << "Error: index out of range" << endl;		
		return 0;
	}

	return _arr[index];
}

void DynamicArray::AddElement(int value)
{
	int* tmp = new int[_size + 1];
	
	if (tmp == nullptr)
	{
		cout << "Error: can`t allocate memory" << endl;
		return;
	}

	for (size_t i = 0; i < _size; i++)
	{
		tmp[i] = _arr[i];
	}

	tmp[_size] = value;

	delete[] _arr;
	_arr = tmp;
	_size++;
}

void DynamicArray::Clear()
{
	if (_arr != nullptr)
	{
		delete[] _arr;
		_arr = nullptr;
		_size = 0;
	}
}

void DynamicArray::Sort()
{
	std::sort(this->_arr, this->_arr + this->_size);
}

void DynamicArray::Sort(DynamicArray& array)
{
	std::sort(array._arr, array._arr + array._size);
}

ostream& operator<<(ostream& cout, const DynamicArray& array)
{
	for (size_t i = 0; i < array.GetSize(); i++)
	{
		cout << array[i] << "\t";
	}

	return cout;
}
