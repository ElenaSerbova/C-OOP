#pragma once

template<typename TValue>
struct ListItem
{
	ListItem* next = nullptr;
	ListItem* prev = nullptr;
	TValue value;

	ListItem() = default;
	ListItem(const TValue& value)
	{
		this->value = value;
	}
};

