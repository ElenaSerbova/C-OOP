#pragma once
#include "Headers.h"


class Seller : public Employee
{
public:

	Seller()
	{
		cout << "Seller constructor " << endl;
	}
	
	Seller(
		string firstname,
		string lastname,
		double sallary,
		string phone = "undefined",
		string department = "undefined"
	);

	Seller(const Seller& source) : Employee(source)
	{
		cout << "Seller constructor copy " << endl;

		_department = source._department;
	}
	
	~Seller();

	void SetDepartment(string department);
	string GetDepartment() { return _department; }

	void Print();
	
private:
	string _department;
};

