#include <vector>
#include <iostream>
#include <time.h>
#include "Point.h"

//using namespace std;

using std::cout;
using std::endl;
using std::string;
using std::vector;

template<typename T>
void print(const vector<T>& v)
{
	/*for (auto it = v.begin(); it != v.end(); it++)
	{
		auto el = *it;
		cout << el << "\t";
	}*/

	for (auto el : v)
		cout << el << "\t";
	cout << endl;
}

void constructors()
{ 
	vector<int> v1;
	print(v1);

	vector<int> v2(10);
	print(v2);

	vector<int> v3(10, 123);
	print(v3);

	string str = "this is string";
	vector<char> v4(str.begin(), str.end());
	print(v4);

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> v5(arr, arr + 9);
	print(v5);

	vector<int> v6 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }; //initializer_list<int>
}


//template <typename InputIterator>
//vector(InputIterator first, InputIterator last)
//{
//	for (; first != last; first++)
//	{
//		push_back(*first);
//	}
//}


void modify()
{
	vector<int> v;

	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.capacity() << endl;

	for (size_t i = 0; i < 5; i++)
	{
		v.push_back(rand() % 100);
	
		cout << "Size: " << v.size() << endl;
		cout << "Capacity: " << v.capacity() << endl;

	}

	v.insert(v.begin(), 100);
	v.insert(v.end(), 100);
	v.insert(v.begin() + 4, 100);

	print(v);

	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.capacity() << endl;

	v.erase(v.begin() + 3);

	print(v);
	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.capacity() << endl;

	v.erase(v.begin(), v.begin() + 2);

	print(v);
	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.capacity() << endl;
	
	v.clear();

	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.capacity() << endl;

	v.assign(4, 23); //23 23 23 23
	v.assign({ 1,2,3,4,5 });

	v.shrink_to_fit();

	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.capacity() << endl;

	v = { 1,2,3,4,5,6,7,8,9 };

	print(v);
	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.capacity() << endl;

	v.resize(15);

	print(v);
	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.capacity() << endl;

	v.resize(20, 100);

	print(v);
	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.capacity() << endl;

	v.resize(5);

	print(v);
	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.capacity() << endl;

	for (size_t i = 0; i < 100; i++)
	{
		//v[i] = rand() % 100;

		try {
			v.at(i) = rand() % 100;
		}
		catch (out_of_range& ex) {
			break;
		}
		
	}

 }


void vectorOfPoint()
{
	vector<Point> v;
	
	Point p(1, 1);
	v.push_back(p);

	v.push_back(Point(2, 3));
	v.push_back({ 2, 3 });

	v.emplace_back(3, 4);

	v.emplace(v.begin(), 5, 6);

	print(v);
}

int main()
{
	srand(time(0));
	//constructors();
	modify();
	//vectorOfPoint();
}