#pragma once

#include <string>
using std::string;

namespace Academy
{
	namespace Entities
	{
		class Student
		{
		public:
			void SetFirstname(string firstname);
			void SetLastname(string lastname);

			string GetFullname();
		private:
			string _firstname;
			string _lastname;
		};
	}

}

