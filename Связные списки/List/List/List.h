#pragma once
#include "ListItem.h"
#include <iostream>
using namespace std;

template <typename TValue>
class List
{
public:
	List() = default;
	~List();

	void AddToBack(const TValue& value); //добавление в конец списка
	void AddToFront(const TValue& value);
	void RemoveAt(size_t index);
	void Clear();

	TValue& operator[](size_t index);
	const TValue& operator[](size_t index) const;

	void Print() const;

	size_t GetSize() const
	{
		return _size;
	}
private:
	ListItem<TValue>* _head = nullptr;
	size_t _size = 0;
};

template<typename TValue>
inline List<TValue>::~List()
{
	Clear();
}

template<typename TValue>
inline void List<TValue>::AddToBack(const TValue& value)
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
inline void List<TValue>::AddToFront(const TValue& value)
{
	ListItem<TValue>* newItem = new ListItem<TValue>(value);

	if (_head != nullptr)
	{
		newItem->next = _head;
	}

	_head = newItem;
	_size++;
}

template<typename TValue>
inline void List<TValue>::RemoveAt(size_t index)
{
	if (index >= _size)
	{
		throw exception("Index out of range");
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
inline void List<TValue>::Clear()
{
	ListItem<TValue>* delItem = nullptr;

	while (_head != nullptr)
	{
		delItem = _head;
		_head = delItem->next;
		delete delItem;
	}

	_size = 0;
}

template<typename TValue>
inline TValue& List<TValue>::operator[](size_t index)
{
	if (index >= _size)
	{
		throw exception("Index out of range");
	}

	ListItem<TValue>* cursor = _head;
	for (size_t i = 0; i < index; i++)
	{
		cursor = cursor->next;
	}

	return cursor->value;
}

template<typename TValue>
inline const TValue& List<TValue>::operator[](size_t index) const
{
	if (index >= _size)
	{
		throw exception("Index out of range");
	}

	ListItem<TValue>* cursor = _head;
	for (size_t i = 0; i < index; i++)
	{
		cursor = cursor->next;
	}

	return cursor->value;
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
