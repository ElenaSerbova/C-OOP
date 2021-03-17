#include "vector.h"

using std::find;

struct Point {
	int x = 0;
	int y = 0;
};

int main()
{
	vector<int> v1{ 5 };
	vector<int> v = {1, 23, 3, 4, 5};
	
	for (size_t i = 0; i < v.getSize(); i++)
	{
		cout << v[i] << endl;
	}

	cout << endl;
	//vector<int>::iterator it ;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	cout << endl;

	for (auto el : v)
	{
		cout << el << endl;
	}

	cout << endl;

	auto it = find(v.begin(), v.end(), 3);
	cout << "find: " << *it << " in position: " <<std::distance(v.begin(), it) << endl;


	vector<Point> vPoint;
	vPoint.add(Point{ 12,13 });
	auto itPoint = vPoint.begin();

	itPoint->x = 10; //itPoint.operator->()->x

	cout << itPoint->x << ", " << itPoint->y << endl;
}

