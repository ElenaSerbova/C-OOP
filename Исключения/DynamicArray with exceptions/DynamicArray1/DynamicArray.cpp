#include "DynamicArray.h"
#include <iostream>
#include <Windows.h>
#include "IndexOutOfRange.h"
#include "MemoryAllocateException.h"
using namespace std;

DynamicArray::DynamicArray()
{
    // cout << "Constructor" << endl;
    _array = nullptr;
    _size = 0;
}

DynamicArray::DynamicArray(size_t size)
{
    _array = new int[size];    
    
    _size = size;

    for (size_t i = 0; i < _size; i++)
    {
        _array[i] = rand() % 100;
    }
}

DynamicArray::~DynamicArray()
{
    //cout << "Destructor" << endl;
    if(_array != nullptr)
        delete[] _array;
}

//Конструктор копирования
DynamicArray::DynamicArray(const DynamicArray& obj)
{
    _array = new int[obj._size];
    _size = obj._size;

    for (size_t i = 0; i < _size; i++)
    {
        _array[i] = obj._array[i];
    }
}
//оператор присваивания всегда перегружается как метод класса
DynamicArray DynamicArray::operator=(const DynamicArray& obj)
{
    if (this == &obj) //проверка на самоприсваивание
        return *this;

    if (_array != nullptr)
        delete[] _array; //удаление старых данных, если они были

    _array = new int[obj._size];
    _size = obj._size;

    for (size_t i = 0; i < _size; i++)
    {
        _array[i] = obj._array[i];
    }

    return *this;
}


DynamicArray::DynamicArray(DynamicArray&& obj) noexcept
{
    _array = obj._array;
    _size = obj._size;

    obj._array = nullptr;
    obj._size = 0;
}

DynamicArray DynamicArray::operator=(DynamicArray&& obj) noexcept
{
    if (this == &obj)
        return *this;

    if (_array != nullptr)
        delete[] _array;

    _array = obj._array;
    _size = obj._size;

    obj._array = nullptr;
    obj._size = 0;
}

void DynamicArray::Add(int value)
{
    int* tmp = new int[_size + 1];

    for (size_t i = 0; i < _size; i++)
    {
        tmp[i] = _array[i];
    }

    tmp[_size] = value;

    delete[] _array;
    _array = tmp;
    _size++;
}

void DynamicArray::RemoveAt(int index)
{
    if (index < 0 || index >= _size)
    {
        throw index_out_of_range();
    }

    int* tmp = new int[_size - 1];

    for (size_t i = 0; i < index; i++)
    {
        tmp[i] = _array[i];
    }

    for (size_t i = index; i < _size - 1; i++)
    {
        tmp[i] = _array[i + 1];
    }

    delete[] _array;
    _array = tmp;
    _size--;
}

void DynamicArray::Print() const
{
    for (size_t i = 0; i < _size; i++)
    {
        cout << _array[i] << "\t";
    }
    cout << "\n";
}

int& DynamicArray::operator[](int index)
{
    if (index < 0 || index >= _size)
    {
        throw index_out_of_range();
    }

    return _array[index];   
}

int DynamicArray::operator[](int index) const
{
    if (index < 0 || index >= _size)
    {
        throw index_out_of_range();
    }

    return _array[index];
}
