#pragma once
#include "ListItem.h"
#include <iostream>
#include <iterator>
using namespace std;

template <typename TValue>
class List
{
public:
	List() = default;

	void AddItem(TValue value);
	void RemoveAt(size_t index);

	void Print() const;

	class iterator : public std::iterator<forward_iterator_tag, ListItem<TValue>>
	{
	public:
		iterator() = default;
		iterator(ListItem<TValue>* item);

		iterator& operator++()
		{
			_current = _current->next;
			return *this;
		}

		iterator operator++(int)
		{
			iterator old = *this;
			_current = _current->next;
			return old;
		}

		bool operator==(iterator it);
		bool operator!=(iterator it);

		TValue& operator*();
		TValue* operator->();

	private:
		ListItem<TValue>* _current = nullptr;
	};


	iterator begin()
	{
		return iterator(_head);
	}

	iterator end()
	{
		return iterator();
	}
private:
	ListItem<TValue>* _head = nullptr;
	size_t _size = 0;
};

template<typename TValue>
inline void List<TValue>::AddItem(TValue value)
{
	ListItem<TValue>* newItem = new ListItem<TValue>(value);

	if (_head == nullptr)
	{
		_head = newItem;
	}
	else
	{
		//search list item
		ListItem<TValue>* cursor = _head;

		while (cursor->next != nullptr)//пока есть следующий элемент
		{
			cursor = cursor->next;
		}

		//в последний элемент записать адрес нового элемента
		cursor->next = newItem; 
	}

	_size++;

}

template<typename TValue>
inline void List<TValue>::RemoveAt(size_t index)
{
	if (index >= _size)
	{
		cerr << "Error: index out of range" << endl;
		return;
	}

	ListItem<TValue>* delItem = nullptr;
	if (index == 0)
	{
		//если удаляемый элемент первый
		delItem = _head;
		//перенапрявляем голову на втрой элемент
		_head = delItem->next;
	}
	else
	{
		//поиск элемента перед удаляемым
		ListItem<TValue>* prevItem = _head;
		for (size_t i = 0; i < index - 1; i++)
		{
			prevItem = prevItem->next;
		}

		//сохраняем адрес удаляемого элемента
		delItem = prevItem->next;

		//перенаправляем указатель
		prevItem->next = delItem->next;
	}

	//удаляем элемент
	delete delItem;
	_size--;

}

template<typename TValue>
inline void List<TValue>::Print()const
{
	ListItem<TValue>* cursor = _head;
	while (cursor != nullptr)
	{
		cout << cursor->value << "\t";
		cursor = cursor->next;
	}
	cout << endl;
}



template<typename TValue>
inline List<TValue>::iterator::iterator(ListItem<TValue>* item)
{
	_current = item;
}
template<typename TValue>
inline bool List<TValue>::iterator::operator==(iterator it)
{
	return _current == it._current;
}

template<typename TValue>
inline bool List<TValue>::iterator::operator!=(iterator it)
{
	return _current != it._current;
}

template<typename TValue>
inline TValue& List<TValue>::iterator::operator*()
{
	if (_current == nullptr)
		throw exception("iterator out of range");

	return _current->value;
}

template<typename TValue>
inline TValue* List<TValue>::iterator::operator->()
{
	if (_current == nullptr)
		throw exception("iterator out of range");
	
	return &(_current->value);
}
