#pragma once
#include "DynamicArray.h"

template <typename TValue>
class PriorityQueue
{
public:
	enum Priority{LOW, NORMAL, HIGH};

	void Push(TValue value, Priority priority = NORMAL)
	{
		QueueItem<TValue> item = { value, priority };
		arr.AddElement(item);
	}

	TValue Pop()
	{
		Priority maxPriority = arr[0].priority;
		int index = 0;

		for (size_t i = 1; i < arr.GetSize(); i++)
		{
			if (arr[i].priority > maxPriority)
			{
				maxPriority = arr[i].priority;
				index = i;
			}
		}

		TValue value = arr[index].value;
		arr.RamoveAt(index);
		return value;
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

	template <typename TValue>
	struct QueueItem
	{
		TValue value;
		Priority priority;
	};

	DynamicArray< QueueItem<TValue> > arr;
};

