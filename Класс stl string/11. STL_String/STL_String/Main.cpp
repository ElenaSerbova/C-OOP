#include <iostream>
#include <string>

using namespace std;

void constructors();
void capacity();
void elementAccess();
void modifiers();
void stringOperations();
void inputString();

void main()
{
	//constructors();
	//capacity();
	//elementAccess();
	//modifiers();
	//stringOperations();
	inputString();
}

void constructors()
{
	string str1;
	string str2 = "qwerty";
	string str3("asdfg");
	string str4("this is a string", 7); //this is
	string str5 = str2;
	string str6(str4, 5, 2); //is
	string str7(10, '*'); //**********
	string str8 = { 'q', 'w', 'e', 'r', 't', 'y' };	

	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	cout << "str3: " << str3 << endl;
	cout << "str4: " << str4 << endl;
	cout << "str5: " << str5 << endl;
	cout << "str6: " << str6 << endl;
	cout << "str7: " << str7 << endl;
	cout << "str8: " << str8 << endl;

	string str9 = move(str8);
	cout << "str8: " << str8 << endl;
	cout << "str9: " << str9 << endl;

}

void capacity()
{
	string str;
	//str.reserve(70);
	cout << "string: " << str << endl;
	cout << "size:     " << str.size() << endl;
	cout << "length:   " << str.length() << endl;
	cout << "capacity: " << str.capacity() << endl;
	cout << "max size: " << str.max_size() << endl;
	cout << endl;

	str = "Strings are objects";
	cout << "string: " << str << endl;
	cout << "length:   " << str.length() << endl;
	cout << "capacity: " << str.capacity() << endl;
	cout << endl;

	str += " that";
	cout << "string: " << str << endl;
	cout << "length:   " << str.length() << endl;
	cout << "capacity: " << str.capacity() << endl;
	cout << endl;

	str += " represent sequences";
	cout << "string: " << str << endl;
	cout << "length:   " << str.length() << endl;
	cout << "capacity: " << str.capacity() << endl;
	cout << endl;

	str += "  of characters.";
	cout << "string: " << str << endl;
	cout << "length:   " << str.length() << endl;
	cout << "capacity: " << str.capacity() << endl;
	cout << endl;

	str.resize(90, '.');
	cout << "string: " << str << endl;
	cout << "length:   " << str.length() << endl;
	cout << "capacity: " << str.capacity() << endl;
	cout << endl;

	str.resize(60);
	cout << "string: " << str << endl;
	cout << "length:   " << str.length() << endl;
	cout << "capacity: " << str.capacity() << endl;
	cout << endl;

	str.shrink_to_fit();	
	cout << "string: " << str << endl;
	cout << "length:   " << str.length() << endl;
	cout << "capacity: " << str.capacity() << endl;
	cout << endl;
}

void elementAccess()
{
	string str = "test string";	
	str.front() = 'T';
	
	str[5] = 'S';	
	str.at(5) = 's';
	
	try
	{		
		str.at(21) = 't';
	}
	catch (out_of_range& ex)
	{
		cout << ex.what() << endl;
	}	

	cout << str << endl;	
}

void modifiers()
{
	string str1 = "Extends";
	string str2 = "Extends the string by appending additional characters";
	
	str1.append(str2, 7, string::npos);
	str1.push_back('.');
	cout << str1 << endl;

	str1.erase(8, 3);
	str1.insert(8, "a");
	cout << str1 << endl;

	str1.replace(30, 10, "Yan");
	cout << str1 << endl;
}

void stringOperations()
{
	string str = "Searches the string for the first occurrence of the sequence specified by its arguments.";
	cout << str << endl;
	cout << "find 'the'" << endl;
	int pos = -1;
	do
	{
		pos = str.find("the", pos + 1);
		cout << "pos: " << pos << endl;
	} while (pos != string::npos);


	pos = str.find_first_of("!?:,.");
	cout << "pos: " << pos << endl;

	pos = str.find_first_not_of("!?:,.");
	cout << "pos: " << pos << endl;

}

void inputString()
{
	string str;

	cout << "Enter a string: ";
	//cin >> str;
	getline(cin, str);

	cout << "String: " << str << endl;
}

	