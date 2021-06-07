#include "DynamicArray.h"

#include <iostream>
using namespace std;


void DynamicArray::AddElement(int value)
{
	int* tmp = new int[size_ + 1];

	for (size_t i = 0; i < size_; i++)
	{
		tmp[i] = pArr_[i];
	}

	tmp[size_] = value;

	delete[] pArr_;
	pArr_ = tmp;
	size_++;
}

void DynamicArray::RemoveElement(size_t index)
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
