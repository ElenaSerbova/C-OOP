#pragma once
#ifndef DYNAMIC_ARRAY 
#define DYNAMIC_ARRAY 


class DynamicArray
{
private:
	int* _arr = nullptr;
	size_t _size = 0;

	void Copy(const DynamicArray& sourceObj);
public:

	DynamicArray() = default;
	explicit DynamicArray(size_t size, int value = 0);

	~DynamicArray();

	//constructor copy
	DynamicArray(const DynamicArray& sourceObj);
	//operator copy
	DynamicArray& operator=(const DynamicArray& sourceObj);

	//constructor move
	DynamicArray(DynamicArray&& sourceObj);
	//operator move
	DynamicArray& operator=(DynamicArray&& sourceObj);


	size_t GetSize() const;
	int GetElement(size_t index) const;
	void SetElement(size_t index, int value);

	int& operator[](size_t index);
	int operator[](size_t index) const;

	void AddElement(int value = 0);
	void Clear();

	void Sort();
	static void Sort(DynamicArray& array);
};

#endif // !DYNAMIC_ARRAY 
