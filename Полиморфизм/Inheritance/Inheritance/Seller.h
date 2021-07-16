#pragma once
#include "Headers.h"


class Seller : public Employee
{
public:

	Seller()
	{
		//cout << "Seller constructor " << endl;
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
#ifdef DEBUG	
		cout << "Seller constructor copy " << endl;
#endif
	

		_department = source._department;
	}
	
	~Seller();

	void SetDepartment(string department);
	string GetDepartment() { return _department; }

	virtual void Print() override;
	
private:
	string _department;
};

