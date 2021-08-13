#pragma once

class DynamicArray
{
public:  

    DynamicArray();
    explicit DynamicArray(size_t size);
    ~DynamicArray();

    //Семантика копирования
    DynamicArray(const DynamicArray& obj);
    DynamicArray operator=(const DynamicArray& obj);

    //Семантика переноса
    DynamicArray(DynamicArray&& obj) noexcept;
    DynamicArray operator=(DynamicArray&& obj) noexcept;

    void Add(int value);
    void RemoveAt(int index);
    void Print() const;

    size_t GetSize() const { return _size; }
    
    //операция индексации
    int& operator[] (int index);
    int operator[] (int index) const;

private:
    int* _array;
    size_t _size;
};
