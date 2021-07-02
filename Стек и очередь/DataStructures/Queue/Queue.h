#pragma once

template<typename T>
class Queue
{
public:
	Queue() = default;

	Queue(const Queue& queue)
	{
		Copy(queue);
	}

	Queue(Queue&& queue)
	{
		Move(queue);
	}

	Queue& operator=(const Queue& queue)
	{
		if (this != &queue)
		{
			Clear();
			Copy(queue);
		}

		return *this;
	}

	Queue& operator=(Queue&& queue)
	{
		if (this != &queue)
		{
			Clear();
			Move(queue);
		}

		return *this;
	}

	~Queue()
	{
		Clear();
	}

	//add new element to end
	void Push(const T& value)
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

	//remove element
	void Pop()
	{
		if (_size == 0)
			return;

		T* tmp = new T[_size - 1];

		for (size_t i = 1; i < _size; i++)
		{
			tmp[i - 1] = _arr[i];
		}

		delete[] _arr;
		_arr = tmp;
		_size--;
	}

	//peek top element
	const T& Top() const
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
	T* _arr = nullptr;
	size_t _size = 0;

	void Copy(const Queue& queue)
	{
		_arr = new T[queue._size];

		for (size_t i = 0; i < queue._size; i++)
		{
			_arr[i] = queue._arr[i];
		}

		_size = queue._size;
	}
	void Move(Queue& queue)
	{
		_arr = queue._arr;
		_size = queue._size;

		queue._arr = nullptr;
		queue._size = 0;
	}
	void Clear()
	{
		if (_arr != nullptr)
		{
			delete[] _arr;
			_arr = nullptr;
			_size = 0;
		}
	}
};

