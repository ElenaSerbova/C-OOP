#include "Header.h"

int main()
{
	cout << "Count: " << Student::GetCount() << endl;

	Student student("Oleg", "Sidorov");
	student.SetFirstname("11111111");

	cout << "Student: " << student.GetFirstname()
		<< " " << student.GetLastname() << endl;

	cout << "Count: " << Student::GetCount() << endl;

	{
		Student student2("Olga", "Sidorova");

		cout << "Student: " << student2.GetFirstname()
			<< " " << student2.GetLastname() << endl;

		cout << "Count: " << Student::GetCount() << endl;
	}

	cout << "Count: " << Student::GetCount() << endl;
}
