#pragma once

#include "Headers.h"

template <typename T>
class List
{
public:

	List() = default;

	List(const List& list) {

		ListItem<T>* cursor = list._head;
		ListItem<T>* prevItem = nullptr;

		while (cursor != nullptr)
		{
			ListItem<T>* newItem = new ListItem<T>(cursor->_data);

			if (cursor == list._head) {
				_head = newItem;
			}
			else
			{
				prevItem->_next = newItem;
				newItem->_prev = prevItem;
			}

			prevItem = newItem;
			cursor = cursor->_next;
		}

		_tail = prevItem;
		_size = list._size;
	}
	List(List&& list) {
		
		_head = list._head;
		_tail = list._tail;
		_size = list._size;
		
		list._head = nullptr;		
		list._tail = nullptr;		
		list._size = 0;
	}

	void AddToFront(T data) {

		ListItem<T>* newItem = new ListItem<T>(data);

		if (_tail == nullptr) {			
			_tail = newItem;
		}
		else {
			newItem->_next = _head; //направл€ем новый элемент на первый в списке
			_head->_prev = newItem; //направл€ем первый элемент списка на новый			
		}

		_head = newItem; //головой списка становитс€ новый элемент
		_size++;
	}

	void AddToBack(T data) {
		ListItem<T>* newItem = new ListItem<T>(data);

		if (_head == nullptr) {
			_head = newItem;			
		}
		else {
			newItem->_prev = _tail;
			_tail->_next = newItem;			
		}
		
		_tail = newItem;
		_size++;
	}

	void RemoveByIndex(size_t index) {

		ListItem<T>* delItem = nullptr;

		if (_head == _tail && _head != nullptr) //единственный элемент в списке
		{
			delItem = _head;
			_head = nullptr;
			_tail = nullptr;			
		}
		else if (index == 0) //удал€ем из начала
		{
			delItem = _head;
			_head = _head->_next;
			_head->_prev = nullptr;
		}
		else if (index == _size - 1) //удал€ем с конца
		{
			delItem = _tail;
			_tail = _tail->_prev;
			_tail->_next = nullptr;
		}
		else
		{
			delItem = search(index);
			delItem->_prev->_next = delItem->_next;
			delItem->_prev->_next = delItem->_prev;
		}

		delete delItem;
		_size--;

	}

	size_t GetSize() const {
		return _size;
	}

	T GetFront() const {

		if (_head == nullptr) {
			throw exception("List is empty");
		}

		return _head->_data;
	}

	T GetBack() const {

		if (_tail == nullptr) {
			throw exception("List is empty");
		}

		return _tail->_data;
	}

	void Print() {
		ListItem<T>* cursor = _head;

		while (cursor != nullptr) {
			cout << cursor->_data << "\t";
			cursor = cursor->_next;
		}
		cout << endl;
	}

	void ReversePrint() {
		ListItem<T>* cursor = _tail;

		while (cursor != nullptr) {
			cout << cursor->_data << "\t";
			cursor = cursor->_prev;
		}
		cout << endl;
	}

private:
	ListItem<T>* _head = nullptr;
	ListItem<T>* _tail = nullptr;

	size_t _size = 0;

	ListItem<T>* search(size_t index) {

		if (index >= _size) {
			throw exception("Index out of range");
		}

		ListItem<T>* cursor = _head;

		for (size_t i = 0; i < index; i++){
			cursor = cursor->_next;
		}

		return cursor;
	}
};

