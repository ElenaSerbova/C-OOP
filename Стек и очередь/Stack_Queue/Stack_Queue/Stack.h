#pragma once
#include "DynamicArray.h"

template <typename TValue>
class Stack
{
public:

	void Push(TValue value)
	{
		arr.AddElement(value);
	}

	TValue Pop()
	{
		TValue value = arr[arr.GetSize() - 1];
		arr.RemoveLastElement();
		return value;
	}

	TValue Peek() const
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

