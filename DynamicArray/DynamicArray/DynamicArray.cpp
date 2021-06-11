#include "DynamicArray.h"

#include <iostream>
using namespace std;


DynamicArray::DynamicArray(size_t size)
{
	cout << "DynamicArray(size_t)" << endl;
	
	pArr_ = new int[size];
	size_ = size;

	for (size_t i = 0; i < size; i++)
	{
		pArr_[i] = 0;
	}
}

DynamicArray::DynamicArray(const DynamicArray& array)
{
	size_ = array.size_;
	pArr_ = new int[size_];

	for (size_t i = 0; i < size_; i++)
	{
		pArr_[i] = array.pArr_[i];
	}
}

DynamicArray::~DynamicArray()
{
	cout << "~DynamicArray" << endl;
	Clear();
}

void DynamicArray::AddElement(int value)
{
	int* tmp = new int[size_ + 1];

	for (size_t i = 0; i < size_; i++)
	{
		tmp[i] = pArr_[i];
	}

	tmp[size_] = value;

	if (pArr_ != nullptr)
	{
		delete[] pArr_;
	}

	pArr_ = tmp;
	size_++;
}

void DynamicArray::RemoveElement(size_t index)
{
	if (pArr_ != nullptr)
	{
		int* tmp = new int[size_ - 1];

		for (size_t i = 0; i < size_; i++)
		{
			if (i < index)
			{
				tmp[i] = pArr_[i];
			}
			else if (i > index)
			{
				tmp[i - 1] = pArr_[i];
			}
		}

		delete[] pArr_;
		pArr_ = tmp;
		size_--;
	}
}

void DynamicArray::Clear()
{
	if (pArr_ != nullptr)
	{
		delete[] pArr_;
		pArr_ = nullptr;
		size_ = 0;
	}
}

int DynamicArray::GetElement(size_t index)
{
	if (index >= size_)
	{
		cout << "Index out of randge" << endl;
	}
	return pArr_[index];
}

int DynamicArray::GetSize()
{
	return size_;
}
