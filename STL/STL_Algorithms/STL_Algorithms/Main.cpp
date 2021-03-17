#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <algorithm>
#include <time.h>
#include <iterator>

using namespace std;


#pragma region predicates

bool is_even(int i)
{
	return i % 2 == 0;
}

//функтор
class IsMultiple
{
	int _n;

public:

	IsMultiple(int n)
	{
		_n = n;
	}

	bool operator() (int i)
	{
		return i % _n == 0;
	}
};

template < typename T>
void print_element(T i)
{
	cout << i << "\t";
}

void increment(int& i)
{
	i++;
}

bool cmp_desc(int el1, int el2)
{
	return el1 > el2;
}

#pragma endregion

void using_find();
void using_count();
void using_find_if();
void using_foreach();
void using_copy();
void using_sort();

struct Book
{
	string name;
	string author;
	int yearPress;
};

bool cmp_books_by_year(Book b1, Book b2)
{
	return b1.yearPress < b2.yearPress;
}
bool cmp_books_by_name(Book b1, Book b2)
{
	return b1.name < b2.name;
}

void using_list_books();

int main()
{
	srand(time(0));
	//using_find();
	//using_count();
	//using_find_if();
	//using_foreach();
	//using_copy();
	//using_sort();
	using_list_books();
}

void using_find()
{
	vector<string> products = { "lemon", "plum", "grapes", "apple", "orange" };

	string searchValue = "grapes";

	vector<string>::iterator it = find(products.begin(), products.end(), searchValue);

	if (it != products.end())
	{
		cout << "position: " << it - products.begin() << endl;
		cout << "value: " << *it << endl;
	}


	vector<int> marks = { 12, 11, 10, 9, 12, 10, 8, 2, 5, 11 };

	auto itFirst = marks.begin() + 2;
	auto itLast = marks.end() - 2;

	auto itRes = find(itFirst, itLast, 2); //{., ., 10, 9, 12, 10, 8, 2, ., .}
	if (itRes != itLast)
	{
		cout << "position: " << itRes - marks.begin() << endl;
		cout << "value: " << *itRes << endl;
	}


	list<string> laguages = { "C++", "C#", "PHP", "JavaScript", "HTML" };
	
	auto itLang = find(laguages.begin(), laguages.end(), "PHP");
	if (itLang != laguages.end())
	{
		cout << "position: " << distance(itLang, laguages.begin()) << endl;
		cout << "value: " << *itLang << endl;
	}


	double prices[10] = { 123.4, 45.6, 100, 400.5, 35.0, 123.4, 45.6, 100, 400.5, 35.0 };
	double searchPrice = 100;

	cout << "find first element equal 100: " << endl;

	double* p = find(prices, prices + 10, searchPrice);
	if (p != prices + 10)
	{
		cout << "position: " << p - prices << endl;
		cout << "value: " << *p << endl;
	}

	cout << "find all elements equal 100: " << endl;

	double* pFirst = prices;
	double* pLast = prices + 10;

	do
	{
		p = find(pFirst, pLast, searchPrice);
		if (p != pLast)
		{
			cout << "position: " << p - prices << endl;
			cout << "value: " << *p << endl;
		}

		pFirst = p + 1;
	} while (p != pLast);

}

void using_count()
{
	double prices[10] = { 123.4, 45.6, 100, 400.5, 35.0, 123.4, 45.6, 100, 400.5, 35.0 };
	double searchPrice = 100;

	size_t res = count(prices, prices + 10, searchPrice);
	cout << "count of 100: " << res << endl;

	vector<string> products = { "lemon", "plum", "grapes", "apple", "orange" };
	string searchValue = "grapes";

	res = count(products.begin(), products.end(), searchValue);
	cout << "count of grapes: " << res << endl;
}

void using_find_if()
{
	vector<int> v;
	v.reserve(10);
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(rand() % 100);
		cout << v[i] << "\t";
	}
	cout << endl;

	auto it = find_if(v.begin(), v.end(), is_even);
	if (it != v.end())
		cout << "even element: " << *it << " position:" << it - v.begin() << endl;
	else
		cout << "even element not found" << endl;

	
	it = find_if_not(v.begin(), v.end(), is_even);
	if (it != v.end())
		cout << "even element: " << *it << " position:" << it - v.begin() << endl;
	else
		cout << "even element not found" << endl;

	cout << "find all even elements: ";

	it = v.begin();

	while(it != v.end())
	{
		it = find_if(it, v.end(), is_even);
		if (it != v.end())
		{
			cout << *it << "\t";
			it++;
		}
	}

	cout << endl;

	cout << "element multiple of five: ";
	it = find_if(v.begin(), v.end(), [](int el) {return el % 5 == 0; });
	if (it != v.end())
		cout << *it << " position:" << it - v.begin() << endl;
	else
		cout << "not found" << endl;

	
	IsMultiple times_three(3); //constructor
	times_three(123); //times_three.operator(123)

	it = find_if(v.begin(), v.end(), times_three);
	if (it != v.end())
		cout << "times three element: " << *it << " position:" << it - v.begin() << endl;
	else
		cout << "times three element not found" << endl;

	it = find_if(v.begin(), v.end(), IsMultiple(7));
	if (it != v.end())
		cout << "times seven element: " << *it << " position:" << it - v.begin() << endl;
	else
		cout << "times seven element not found" << endl;

	it = find_if(v.begin(), v.end(), [](int x){return x >= 0 && x < 10; });//lambda
	if (it != v.end())
		cout << "single digit element: " << *it << " position:" << it - v.begin() << endl;
	else
		cout << "single digit element not found" << endl;

}


void using_foreach()
{
	vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(rand() % 100);
	}

	for_each(v.begin(), v.end(), print_element<int>);
	cout << endl;

	for_each(v.begin(), v.end(), increment);

	for (int el : v)
	{
		cout << el << "\t";
	}
	cout << endl;

	for each (int el in v)
	{
		cout << el << "\t";
	}
	cout << endl;
}

void using_copy()
{
	vector<int> myVector;
	for (size_t i = 0; i < 10; i++)
	{
		myVector.push_back(rand() % 100);
	}

	list<int> myList(5);
	//copy(vector.begin(), vector.begin() + 5, list.begin());
	copy_n(myVector.begin(), 5, myList.begin());
	for (int el : myList)
	{
		cout << el << "\t";
	}
	cout << endl;
	
	size_t count_even = count_if(myVector.begin(), myVector.end(), is_even);
	list<int> l_even(count_even);
	copy_if(myVector.begin(), myVector.end(), l_even.begin(), is_even);
	
	for(int el : l_even)
	{
		cout << el << "\t";
	}
	cout << endl;
	

	list<int> list_odd;
	back_insert_iterator< list<int> > insertIt(list_odd);
	copy_if(myVector.begin(), myVector.end(), insertIt, [](int el) {return el % 2 != 0; });

	for (int el : list_odd)
	{
		cout << el << "\t";
	}
	cout << endl;


	set<int> set_even;
	copy_if(myVector.begin(), myVector.end(), inserter(set_even, set_even.begin()), is_even);

	for (int el : set_even)
	{
		cout << el << "\t";
	}
	cout << endl;
}

void using_sort()
{
	vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(rand() % 100);
		cout << v[i] << "\t";
	}
	cout << endl;

	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), print_element<int>);
	cout << endl;

	sort(v.begin(), v.end(), cmp_desc);
	for_each(v.begin(), v.end(), print_element<int>);
	cout << endl;

	/*
	cout << "\nStable sort: " << endl;

	vector<double> vd = { 2.34, 1.32, 2.46, 6.78, 1.23, 5.7 , 1.54};
	for_each(vd.begin(), vd.end(), print_element<double>);
	cout << endl;
	
	sort(vd.begin(), vd.end(), [](double el1, double el2){ return (int)el1 < (int)el2; });
	for_each(vd.begin(), vd.end(), print_element<double>);
	cout << endl;

	vd = { 2.34, 1.32, 2.46, 6.78, 1.23, 5.7, 1.54 };
	stable_sort(vd.begin(), vd.end(), [](double el1, double el2){ return (int)el1 < (int)el2; });
	for_each(vd.begin(), vd.end(), print_element<double>);
	cout << endl;

	vd = { 2.34, 1.32, 2.46, 6.78, 1.23, 5.7, 1.54 };
	partial_sort(vd.begin(), vd.begin() + 2, vd.end());
	for_each(vd.begin(), vd.end(), print_element<double>);
	cout << endl;
	*/
}

void using_list_books()
{
	vector<Book> books;
	books.push_back({ "C++", "Prata", 2010 });
	books.push_back({ "C#", "Richter", 2012 });
	books.push_back({ "C#", "Troelsen", 2009 });
	books.push_back({ "C++", "Straustrup", 2006 });
	books.push_back({ "WPF", "McDonald", 2013 });

	auto it_old = min_element(books.begin(), books.end(), cmp_books_by_year);
	if (it_old != books.end())
		cout << "The oldest book: " << (*it_old).name << " " << it_old->author << endl;

	sort(books.begin(), books.end(), cmp_books_by_name);
	for (Book book : books)
	{
		cout << "Name: " << book.name << endl;
		cout << "Author: " << book.author << endl;
		cout << "Year press: " << book.yearPress << endl;
		cout << endl;
	}
}