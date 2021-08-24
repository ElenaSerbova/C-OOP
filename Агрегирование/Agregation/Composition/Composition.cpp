#include <iostream>
#include <string> 
using namespace std;

class Date {
public:
    int day;
    int month;
    int year;
};

class Group
{
public:

    string name;
    Date date;
};

class Department
{
public:

    Department()
    {
        group1 = new Group;
    }

    ~Department()
    {
        delete group1;
    }

    Group* group1 = nullptr;
};

int main()
{
    {
        Group group1{ "VPD-1", Date{12, 2, 2020 } };

        cout << "Group: " << group1.name << endl;
        cout << "Date: " << group1.date.day << "."
            << group1.date.month << "."
            << group1.date.year << endl;


        Department department1;
        department1.group1->name = "VPD-2";
        
    }

}
