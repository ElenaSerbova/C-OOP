#pragma once

#include "Student.h"

namespace Academy 
{
	namespace Views
	{
		using Entities::Student;

		class StudentView
		{
		public:
			static void Print(Student& student);
		};
	}
}


