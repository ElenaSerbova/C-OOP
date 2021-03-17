#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

void IterationArray();
void IterationString();
void IterationList();

void RandomAccessIterator();

void IteratorOperations();

//adapters
void BackwordIterators();
void InsertIterators();

//for-each(Range-based for Statement)
void foreach()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (int el : arr)
	{
		cout << el << "\t";
	}
	cout << endl;

	list<double> l = { 1.2, 2.3, 3.4, 4.5 };
	for (double& num : l)
	{			
		cout << num << "\t";
		num = 12;				
	}

	/*for (auto it = l.begin(); it != l.end(); it++)
	{
		double& num = *it;

		cout << num << "\t";
	}*/
	cout << endl;

	for (double num : l)
	{
		cout << num << "\t";		
	}
	cout << endl;

	/*
	for(variable : container)
	{
	}
	
	*/
}

int main()
{
	//IterationArray();
	//IterationString();	
	//IterationList();
	//RandomAccessIterator();
	//IteratorOperations();
	//BackwordIterators();
	//InsertIterators();
	foreach();
}

void IterationArray()
{
	int arr[5] = { 1, 2, 3, 4, 5 };

	for (int* p = arr; p != arr + 5; p++)
	{
		int el = *p;
		cout << el << "\t";
	}

	cout << endl;
}

void IterationString()
{
	string str = "Standard Template Library";

	string::iterator it;
	for (it = str.begin(); it != str.end(); it++)
	{
		cout << *it;
	}
	cout << endl;
}

void IterationList()
{
	list<int> l = { 1, 2, 3, 4, 5, 6 };
	
	//list<int>::iterator it
	
	for (auto it = l.begin(); it != l.end(); it++)
	{
		//*it = 0;
		cout << *it << "\t";
	}
	cout << endl;
}

void RandomAccessIterator()
{
	string str = "Standard Template Library";
	
	string::iterator it_5 = str.begin() + 5;
	str.erase(it_5);

	cout << str << endl;
}

void IteratorOperations()
{
	list<int> l = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	list<int>::iterator it = l.begin();	
	
	advance(it, 5);

	cout << "it + 5 : " << *it << endl;

	int n = distance(l.begin(), it);
	cout << "n = " << n << endl;
}

void BackwordIterators()
{
	string str = "This class reverses the direction";

	for (auto it = str.begin(); it != str.end(); it++)
	{
		cout << *it;
	}
	cout << endl;

	for (auto it = str.rbegin(); it != str.rend(); it++)
	{
		cout << *it;
	}
	cout << endl;
}

void InsertIterators()
{
	list<int> l(5);
	auto it = l.begin();
	*it = 10;

	list<int> list1 = { 12, 34, 56, 23, 78 };
	list<int> list2(3); //нужно заранее выделить память

	auto itStart = list1.begin();
	auto itEnd = list1.begin();
	advance(itEnd, 3);
	
	copy(itStart, itEnd, list2.begin());
	
	for (auto el : list2)
		cout << el << "\t";
	cout << endl;

	back_insert_iterator < list<int> > bii(list2);  //push_back
	copy(itStart, itEnd, bii);

	for (auto el : list2)
		cout << el << "\t";
	cout << endl;

	copy(itStart, itEnd, front_inserter(list2));
	
	for (auto el : list2)
		cout << el << "\t";
	cout << endl;
}