#pragma once

template <typename TValue >
struct ListItem
{	
	ListItem() = default;

	ListItem(const TValue& value) {
		
		this->value = value;
	}

	ListItem* next = nullptr;
	TValue value;	
};

