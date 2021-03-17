#pragma once

template <typename TValue >
class ListItem
{	
public:
	ListItem() = default;

	ListItem(TValue value) {
		this->value = value;
	}

	ListItem* next = nullptr;
	TValue value;	
};

