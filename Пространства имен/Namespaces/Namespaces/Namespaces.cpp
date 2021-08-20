#include <iostream>
#include "Student.h"
#include "StudentView.h"

//using namespace std;
using namespace Academy::Entities;
using namespace Academy::Views;

namespace MyFunctions 
{
	using std::cout;
	using std::endl;

	double pow(double number, double power)
	{
		double result = 1;

		for (size_t i = 0; i < power; i++)
		{
			result *= number;
		}

		return result;
	}

	void foo()
	{
		double result = pow(2, 10);
		cout << result << endl;
	}

}


int main()
{
	using std::cout;
	using std::endl;

	cout << MyFunctions::pow(2, 3) << endl;

	//Academy::Entities::Student student1;

	Student student1;
	student1.SetFirstname("John");
	student1.SetLastname("Snow");

	//Academy::Views::StudentView::Print(student1);
	StudentView::Print(student1);
}