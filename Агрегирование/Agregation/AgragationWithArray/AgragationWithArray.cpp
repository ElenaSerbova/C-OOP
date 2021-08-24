#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Student {
public:
    string firstname;
    string lastname;
};

class Group
{
public:
    void AddStudent(Student* student);
    
    Student* operator[] (int index);

    ~Group();
    //семантика копирования и переноса
private:

   // DynamicArray<Student*> _student;

    Student** _students = nullptr;
    size_t _size;
};

int main()
{

    Student* student1 = new Student{ "John", "Snow" };
    Student* student2 = new Student{ "Aria", "Stark" };
    
    Group group1;
    group1.AddStudent(student1);
    group1.AddStudent(student2);

}

void Group::AddStudent(Student* student)
{
    Student** tmp = new Student * [_size + 1];

    for (size_t i = 0; i < _size; i++)
    {
        tmp[i] = _students[i];
    }

    tmp[_size] = student;

    delete[] _students;
    _students = tmp;
    _size++;
}

Student* Group::operator[](int index)
{
    if (index >= _size)
        throw out_of_range("Index out of range");

    return _students[index];
}

Group::~Group()
{
    delete[] _students;
    _students = nullptr;
    _size = 0;
}
