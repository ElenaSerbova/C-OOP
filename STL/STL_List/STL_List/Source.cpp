#include <iostream>
#include <list>

using namespace std;

template <typename T>
void print(const list<T>& list)
{
	for (auto el : list)
		cout << el << "\t";
	cout << endl;
}

bool cmp(int el1, int el2)
{
	return el1 > el2;
}

bool isEven(int el)
{
	return el % 2 == 0;
}

int main()
{
	list<int> lst = { 1,2,3,4 };
	lst = { 1, 2, 3, 4, 5 };
	lst.push_back(6);
	lst.push_front(0);

	print(lst); //0 1 2 3 4 5 6

	auto it = lst.begin();
	advance(it, 3);

	lst.insert(it, 7); //0 1 2 7 3 4 5 6
	lst.insert(lst.begin(), 8); //8 0 1 2 7 3 4 5 6

	print(lst);

	lst.assign({ 3,1,5,2,4,7,6 });

	lst.sort(); // 1 2 3 4 5 6 7
	print(lst); 

	lst.sort(cmp); // 7 6 5 4 3 2 1
	print(lst);

	lst.remove_if(isEven); // 7 5 3 1
	print(lst);

	list<int> lst2 = { 1, 2, 3, 4, 1, 2, 3, 5 };
	auto it2 = lst2.begin();
	advance(it2, 4);
	lst.splice(lst.begin(), lst2, it2, lst2.end());
	//lst : 1 2 3 5 7 5 3 1
	//lst2: 1 2 3 4

	cout << "Splice: " << endl;
	print(lst);

	cout << "lst2: " << endl;
	print(lst2);

	lst.sort(); //1 1 2 3 3 5 5 7
	print(lst);

	lst.unique(); //1 2 3 5 7
	print(lst);


}