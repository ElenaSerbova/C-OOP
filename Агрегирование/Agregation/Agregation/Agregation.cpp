#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
public:
    string firstname;
    string lastname;
};

class Group {
public:
    Group(Student& student) : student1(student) {

    }

    Student& student1;
};

class Class
{
public:
    Class(Student* student)
    {
        student1 = student;
    }

    Student* student1 = nullptr;
};

int main()
{
    Student student1{ "Ivan", "Ivanov" };

    {
        Group group1(student1);
        cout << group1.student1.firstname << " " << group1.student1.lastname << endl;

        Class class1(&student1);
        cout << class1.student1->firstname << " " << class1.student1->lastname << endl;
    }

    cout << student1.firstname << " " << student1.lastname << endl;
}