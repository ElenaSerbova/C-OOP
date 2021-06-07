#pragma once

class DynamicArray
{
public:
	void AddElement(int value);
	void RemoveElement(size_t index);

	int GetElement(size_t index);
	int GetSize();

private:

	int* pArr_ = nullptr;
	size_t size_ = 0;
};

