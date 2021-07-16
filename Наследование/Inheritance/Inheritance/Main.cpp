#include "Headers.h"

void UsingSellerCashier()
{
	Seller seller("Olga", "Popova", 6000, "12-23-34", "Milk");
	seller.SetDepartment("Meat");
	seller.SetSalary(7000);

	seller.Print();

	Сashier cashier;
	cashier.SetFirstname("Valentina");
	cashier.SetLastname("Popova");
	cashier.SetPhone("56-89-76");
	cashier.SetSalary(7000);
	cashier.SetAuthInfo("popova", "qwerty");

	cashier.Print(0);
	cashier.Employee::Print();
}

void UsingConstructors()
{
	Seller seller;

	seller.SetFirstname("Olga");
	seller.SetLastname("Popova");
	seller.SetDepartment("Meat");
	seller.SetSalary(7000);

	cout << endl << "Seller: " << seller.GetFirstname() << " " << seller.GetLastname() << endl;

	Seller seller1("Victoriya", "Popova", 6000, "12-23-34", "Milk");
	seller1.SetDepartment("Meat");
	seller1.SetSalary(7000);

	cout << endl <<  "Seller: " << seller1.GetFirstname() << " " << seller1.GetLastname() << endl;

	Seller seller2 = seller1;

	cout << endl << "Seller copy: " << seller2.GetFirstname() << " " << seller2.GetLastname() << endl;

}


int main()
{
	//UsingSellerCashier();
	UsingConstructors();	
}

