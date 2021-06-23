#include <iostream>
#include <string>
using namespace std;

class Group;

class Student {    
    friend class Group;
    friend void PrintStudent(const Student& student);

public:

    Student(string firstname, string lastname, int year)
        : _firstname(firstname), _lastname(lastname), _year(year)
    {
    }

private:
    string _firstname;
    string _lastname;
    int _year;
};

void PrintStudent(const Student& student) {
    cout << student._firstname << " " << student._lastname << endl;
}

class Group {
public:
    void AddStudent(Student obj)
    {
        cout << obj._firstname << " " << obj._lastname << endl;
    }

    void EditStudent(Student obj){}
};


int main()
{
    Student kolya( "Nikolay", "Sidorov", 2020);
    PrintStudent(kolya);
}



