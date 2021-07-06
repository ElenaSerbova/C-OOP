#pragma once
#include "LIstItem.h"
#include <iostream>
using namespace std;

template<typename TValue>
class List
{
public:
	List() = default;

	void AddItem(const TValue& value);
	void InsertItem(size_t index, const TValue& value);

	void Print() const;
	void ReversePrint() const;

	size_t GetSize() const { return _size; }
private:
	ListItem<TValue>* _head = nullptr;
	ListItem<TValue>* _tail = nullptr;
	size_t _size = 0;

	ListItem<TValue>* FindItemAt(size_t index);
};

template<typename TValue>
inline void List<TValue>::AddItem(const TValue& value)
{
	ListItem<TValue>* newItem = new ListItem<TValue>(value);

	if (_head == nullptr)
	{
		_head = newItem;		
	}
	else
	{
		_tail->next = newItem;
		newItem->prev = _tail;		
	}
	_tail = newItem;
	_size++;
}


template<typename TValue>
inline void List<TValue>::InsertItem(size_t index, const TValue& value)
{
	if (index > _size)
	{
		cerr << "Error: index out of range" << endl;
		return;
	}

	ListItem<TValue>* newItem = new ListItem<TValue>(value);

	ListItem<TValue>* prevItem = nullptr;
	ListItem<TValue>* nextItem = nullptr;

	if (_head == nullptr)
	{
		_head = newItem;
		_tail = newItem;
	}
	else if (index == _size)
	{
		/*
		prevItem = _tail;

		prevItem->next = newItem;
		newItem->prev = prevItem;*/

		_tail->next = newItem;
		newItem->prev = _tail;

		_tail = newItem;
	}
	else if (index == 0)
	{
		/*nextItem = _head;
		nextItem->prev = newItem;
		newItem->next = nextItem;*/

		_head->prev = newItem;
		newItem->next = _head;

		_head = newItem;
	}
	else
	{
		prevItem = FindItemAt(index - 1);
		nextItem = prevItem->next;

		prevItem->next = newItem;
		newItem->prev = prevItem;

		nextItem->prev = newItem;
		newItem->next = nextItem;
	}

	_size++;
}


/*
template<typename TValue>
inline void List<TValue>::InsertItem(size_t index, const TValue& value)
{
	if (index > _size)
	{
		cerr << "Error: index out of range" << endl;
		return;
	}

	ListItem<TValue>* newItem = new ListItem<TValue>(value);

	ListItem<TValue>* prevItem = index == 0 ? nullptr : FindItemAt(index - 1);
	ListItem<TValue>* nextItem = index == _size ? nullptr : FindItemAt(index);

	if (prevItem == nullptr)
	{
		_head = newItem;
	}
	else
	{
		prevItem->next = newItem;
		newItem->prev = prevItem;
	}

	if (nextItem == nullptr)
	{
		_tail = newItem;
	}
	else
	{
		nextItem->prev = newItem;
		newItem->next = nextItem;
	}

}
*/
template<typename TValue>
inline void List<TValue>::Print() const
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
inline void List<TValue>::ReversePrint() const
{
	ListItem<TValue>* cursor = _tail;
	while (cursor != nullptr)
	{
		cout << cursor->value << "\t";
		cursor = cursor->prev;
	}
	cout << endl;
}

template<typename TValue>
inline ListItem<TValue>* List<TValue>::FindItemAt(size_t index)
{
	ListItem<TValue>* cursor = _head;
	for (size_t i = 0; i < index; i++)
	{
		cursor = cursor->next;
	}

	return cursor;
}
