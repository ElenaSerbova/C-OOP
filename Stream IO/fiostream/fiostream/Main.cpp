#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class A
{
public:
	
	int f1;
	double f2;	
};

ostream& operator<<(ostream& stream, const A& a) {

	stream << "{ f1 = " << a.f1 << ", f2 = " << a.f2 << " }";
	return stream;
}

void ReadWriteText()
{
	//write to file
	ofstream fout;
	fout.open("test.txt", ios::app);
	if (fout.is_open())
	{

		fout << "Hello, world" << endl;

		int a = 123;
		fout << "a = " << a << endl;

		string str;
		cout << "Enter text:";
		getline(cin, str);


		fout << str << endl;

		A obj{ 12, 12.3 };

		fout << obj << endl;

		fout.close();
	}

	//read from file
	ifstream fin("test.txt");
	if (fin.is_open())
	{
		char str[255];
		while (!fin.eof())
		{
			fin.getline(str, 255);
			cout << str << endl;
		}
		fin.close();
	}
}

void ReadWriteBinary()
{
	ofstream fout("test.bin", ios_base::binary | ios_base::out);
	if (!fout.is_open())
	{
		cout << "file not opened for write." << endl;
		return;
	}

	int a = 123;
	fout.write((char*)&a, sizeof(int));

	A obj{ 12, 23.4 };
	fout.write((char*)&obj, sizeof(A));

	int arr[5] = { 1,2,3,4,5 };
	fout.write((char*)arr, sizeof(int) * 5);

	string str = "Hello";
	
	//fout.write((char*)&str, sizeof(string));

	int size = str.size() + 1;
	
	fout.write((char*)&size, sizeof(int));
	fout.write(str.c_str(), size);

	fout.close();

	ifstream fin("test.bin", ios_base::binary | ios_base::in);
	if (!fin.is_open())
	{
		cout << "file not opened for read." << endl;
		return;
	}

	int b;

	fin.read((char*)&b, sizeof(int));
	cout << "b = " << b << endl;

	A obj2;
	fin.read((char*)&obj2, sizeof(A));
	cout << obj2 << endl;

	int brr[5];
	fin.read((char*)brr, sizeof(int) * 5);

	for (size_t i = 0; i < 5; i++)
	{
		cout << brr[i] << endl;
	}
	
	//string s2;
	/*fin.read((char*)&s2, sizeof(string));

	cout << s2 << endl;*/
	
	int size2;
	fin.read((char*)&size2, sizeof(int));

	char* str2 = new char[size2];
	fin.read(str2, size2);

	cout << str2 << endl;

	delete[] str2;

	fin.close();

}

void TellSeek()
{
	fstream stream("test2.txt", ios_base::out | ios_base::trunc | ios_base::in);
	if (!stream.is_open())
	{
		cout << "file not opened." << endl;
		return;
	}

	cout << "tell: " << stream.tellp() << endl;

	stream << "aaaa bbbb cccc" << endl;
	cout << "tell: " << stream.tellp() << endl;
	
	stream.seekp(0, ios_base::beg);
	
	cout << "tell: " << stream.tellp() << endl;
	
	stream << "dddd";
	
	cout << "tell: " << stream.tellp() << endl;

 	stream.seekp(0, ios_base::beg);

	cout << "tell: " << stream.tellp() << endl;

	char str[255];
	while (!stream.eof())
	{
		stream.getline(str, 255);
		cout << str;
	}

	stream.close();
}

int main()
{

	//ReadWriteText();
	ReadWriteBinary();
	//TellSeek();	
}