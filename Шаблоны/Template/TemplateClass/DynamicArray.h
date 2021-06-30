#pragma once

#include <initializer_list>
using namespace std;

template<typename T>
class DynamicArray
{
public:
	DynamicArray() = default;
	DynamicArray(const DynamicArray& array);

	DynamicArray(const initializer_list<T>& list);

	void Add(T value);

	T operator[] (int index) const;
	T& operator[] (int index);

	size_t GetSize() const;

private:
	T* _arr = nullptr;
	size_t _size = 0;
};

template<typename T>
inline DynamicArray<T>::DynamicArray(const DynamicArray<T>& array)
{
	_arr = new T[array._size];
	_size = array._size;

	for (size_t i = 0; i < _size; i++)
	{
		_arr[i] = array._arr[i];
	}
}

template<typename T>
inline DynamicArray<T>::DynamicArray(const initializer_list<T>& list)
{
	_size = list.size();
	_arr = new T[_size];
	
	int i = 0;
	for (auto it = list.begin(); it != list.end(); it++)
	{
		_arr[i] = *it;
		i++;
	}	
}

template<typename T>
inline void DynamicArray<T>::Add(T value)
{	
	T* tmp = new T[_size + 1];

	for (size_t i = 0; i < _size; i++)
	{
		tmp[i] = _arr[i];
	}

	tmp[_size] = value;

	delete[] _arr;
	_arr = tmp;
	_size++;

}

template<typename T>
inline T DynamicArray<T>::operator[](int index) const
{
	return _arr[index];
}

template<typename T>
inline T& DynamicArray<T>::operator[](int index)
{
	return _arr[index];
}

template<typename T>
inline size_t DynamicArray<T>::GetSize() const
{
	return _size;
}
