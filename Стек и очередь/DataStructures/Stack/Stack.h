#pragma once

template<typename T>
class Stack
{
public:

	Stack() = default;

	Stack(const Stack& stack)
	{
		Copy(stack);
	}
	Stack(Stack&& stack)
	{
		_arr = stack._arr;
		_size = stack._size;

		stack._arr = nullptr;
		stack._size = 0;
	}

	Stack& operator=(const Stack& stack)
	{
		if (this != &stack)
		{
			Clear();
			Copy(stack);
		}

		return *this;
	}
	Stack& operator=(Stack&& stack)
	{
		if (this != &stack)
		{
			Clear();

			_arr = stack._arr;
			_size = stack._size;

			stack._arr = nullptr;
			stack._size = 0;

		}

		return *this;
	}

	~Stack()
	{
		Clear();
	}

	//add new element
	void Push(const T& value)
	{
		T* tmp = new T[_size + 1];

		for (size_t i = 0; i < _size; i++)
		{
			tmp[i + 1] = _arr[i];
		}

		tmp[0] = value;

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

	void Copy(const Stack& stack)
	{
		_arr = new T[stack._size];

		for (size_t i = 0; i < stack._size; i++)
		{
			_arr[i] = stack._arr[i];
		}

		_size = stack._size;
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

