#include "Student.h"

namespace Academy {

	namespace Entities {

		void Student::SetFirstname(string firstname)
		{
			_firstname = firstname;
		}

		void Student::SetLastname(string lastname)
		{
			_lastname = lastname;
		}

		string Student::GetFullname()
		{
			string fullname(_firstname);
			fullname.append(" ");
			fullname.append(_lastname);

			return fullname;
		}

	}

}
