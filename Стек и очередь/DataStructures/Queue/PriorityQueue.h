#pragma once

enum class Priority{Low, Normal, High};

template<typename T>
struct QueueItem
{
	T value;
	Priority priority;
};

template<typename T>
class PriorityQueue
{
public:
	PriorityQueue() = default;

	void Push(const T& value, Priority priority = Priority::Normal)
	{
		int index = GetIndex(priority);

		QueueItem<T>* tmp = new QueueItem<T>[_size + 1];

		for (size_t i = 0; i < index; i++)
		{
			tmp[i] = _arr[i];
		}

		tmp[index].value = value;
		tmp[index].priority = priority;

		for (size_t i = index; i < _size; i++)
		{
			tmp[i + 1] = _arr[i];
		}

		delete[] _arr;
		_arr = tmp;
		_size++;
	}

	//remove element
	void Pop()
	{
		if (_size == 0)
			return;

		QueueItem<T>* tmp = new QueueItem<T>[_size - 1];

		for (size_t i = 1; i < _size; i++)
		{
			tmp[i - 1] = _arr[i];
		}

		delete[] _arr;
		_arr = tmp;
		_size--;
	}

	const QueueItem<T>& Top() const
	{
		if (_size == 0)
			abort();

		return _arr[0];
	}

	size_t GetSize() const
	{
		return _size;
	}


private:
	QueueItem<T>* _arr = nullptr;
	size_t _size = 0;

	int GetIndex(Priority priority)
	{
		if (_size == 0)
			return 0;

		for (int i = _size - 1; i >= 0; i--)
		{
			if (_arr[i].priority >= priority)
				return i+1;
		}

		return 0;
	}
};

