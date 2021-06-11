#pragma once

class DynamicArray
{
public:

	DynamicArray() = default; //указание чтобы компилятор предоставил конструктор
	DynamicArray(size_t size);

	//конструктор копирования
	DynamicArray(const DynamicArray& array);

	//деструктор
	~DynamicArray();

	void AddElement(int value);
	void RemoveElement(size_t index);
	void Clear();

	int GetElement(size_t index);
	int GetSize();

private:

	int* pArr_ = nullptr;
	size_t size_ = 0;
};

