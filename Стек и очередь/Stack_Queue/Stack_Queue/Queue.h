#pragma once
#include "DynamicArray.h"

template <typename TValue>
class Queue
{
public:

	void Push(TValue value)
	{
		arr.AddElement(value);
	}

	TValue Pop()
	{
		TValue value = arr[0];
		arr.RemoveFirstElement();
		return value;
	}

	TValue GetFirstElement() const
	{
		return arr[0];
	}

	TValue GetLastElement() const
	{
		return arr[arr.GetSize() - 1];
	}

	size_t GetSize() const
	{
		return arr.GetSize();
	}

	bool IsEmpty() const
	{
		return arr.GetSize() == 0;
	}
private:
	DynamicArray<TValue> arr;
};

