#include "Headers.h"


Seller::Seller(string firstname, string lastname, double sallary, string phone, string department)
	: Employee(firstname, lastname, sallary, phone), _department(department)
{
#ifdef DEBUG
	cout << "Seller constructor with params" << endl;
#endif
	
}

Seller::~Seller()
{
#ifdef DEBUG
	cout << "Seller destructor" << endl;
#endif	
}

void Seller::SetDepartment(string department)
{
	_department = department;
}

void Seller::Print()
{
	cout << "Seller: " << endl;
	Employee::Print();
	cout << "Department:\t" << _department << endl << endl;
}
