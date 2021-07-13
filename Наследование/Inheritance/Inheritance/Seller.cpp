#include "Headers.h"


Seller::Seller(string firstname, string lastname, double sallary, string phone, string department)
	: Employee(firstname, lastname, sallary, phone)
{
	cout << "Seller constructor with params" << endl;
	
	SetDepartment(department);

}

Seller::~Seller()
{
	cout << "Seller destructor" << endl;
}

void Seller::SetDepartment(string department)
{
	_department = department;
}

void Seller::Print()
{
	cout << "Seller: " << endl;

	cout << "Fullname:\t" << GetFirstname() << " " << GetLastname() << endl;
	cout << "Phone:\t\t" << GetPhone() << endl;
	cout << "Sallary:\t" << GetSalary() << endl;

	cout << "Department:\t" << _department << endl << endl;
}
