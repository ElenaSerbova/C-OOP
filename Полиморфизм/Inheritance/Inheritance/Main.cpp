#include "Headers.h"

void UsingPointerToBaseClass();

double GetTotalSallary(Employee** list, size_t size);
void PrintEmployees(Employee** list, size_t size);

int main()
{	
	UsingPointerToBaseClass();
}

void UsingPointerToBaseClass()
{
	Employee* pEmployee = new Seller("Ivan", "Sidorov", 12000);
	pEmployee->SetPhone("122334");
	pEmployee->Print();

	Seller seller("Ivan", "Sidorov", 12000);
	Employee& rEmployee = seller;
	rEmployee.SetPhone("1223344");
	rEmployee.Print();

	Employee** list = new Employee* [4];

	list[0] = new Seller("Irina", "Popova", 10000);
	list[1] = new Сashier("Oleg", "Petrov", 11000);
	list[2] = new Seller("Mariya", "Ivanova", 10000);
	list[3] = new Сashier("Petr", "Sidorov", 11000);

	PrintEmployees(list, 4);

	cout << "Total sallary: " << GetTotalSallary(list, 4) << endl;
}

double GetTotalSallary(Employee** list, size_t size)
{
	double total = 0;

	for (size_t i = 0; i < size; i++)
	{
		total += list[i]->GetSallary();
	}

	return total;
}

void PrintEmployees(Employee** list, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "------------------" << endl;
		list[i]->Print();
		cout << endl;
	}
}


