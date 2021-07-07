#pragma once

#include "Headers.h"

template <typename T>
class ListItem
{
	//friend class List<T>;

public:
	ListItem() = default;
	
	ListItem(T data) {
		_data = data;
	}

//private:
	ListItem* _next = nullptr;
	ListItem* _prev = nullptr;
	T _data;
};

