#include <iostream>
#include "Student.h"
#include "StudentView.h"

using namespace std;
//using namespace Academy::Entities;
//using namespace Academy::Views;

//namespace MyFunctions 
//{
//	using std::cout;
//	using std::endl;

template <typename T1, typename T2>
	T1 pow(T1 number, T2 power)
	{
		T1 result = 1;

		for (size_t i = 0; i < power; i++)
		{
			result *= number;
		}

		return result;
	}

//	void foo()
//	{
//		double result = pow(2, 10);
//		cout << result << endl;
//	}
//
//}


int main()
{
	using std::cout;
	using std::endl;

	cout << pow(2.3, 3.0) << endl;

	/*Student student1;
	student1.SetFirstname("John");
	student1.SetLastname("Snow");

	StudentView::Print(student1);*/
}

