#include "StudentView.h"

#include <iostream>
using std::cout;
using std::endl;

namespace Academy {
	namespace Views
	{
		void StudentView::Print(Student& student)
		{
			cout << "Student: " << student.GetFullname() << endl;
		}
	}
}