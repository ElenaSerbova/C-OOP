#include <iostream>
#include <string>
#include <map>
#include <functional>

using namespace std;

void usingMap();
void usingMultimap();
void usingCompare();

int main()
{
	//usingMap();
	//usingMultimap();
	usingCompare();
}	

void usingMap()
{

	map<string, double> products = {
		{"apple", 23.5},
		{"lemon", 27.9}
	};

	pair<string, double> p("orange", 56.7);
	products.insert(p);

	pair<string, double> p2 { "grapes", 80.9 };
	products.insert(p2);

	products.insert(pair<string, double>("plum", 45.6));

	products.insert({ "meat", 90.5 });

	products.emplace("watermelon", 12.5);

	products["milk"] = 20.0; //insert
	products["apple"] = 15.9;//replace value

	for (auto pair : products)
	{
		cout << pair.first << ": " << pair.second << endl;
	}

	cout << "===============" << endl;
	
	for (auto it = products.begin(); it != products.end(); it++)
	{
		//cout << (*it).first << endl
		cout << it->first << ": " << it->second << endl;
	}
	
	cout << endl;
	
	auto it_milk = products.find("milk");
	if (it_milk != products.end())
		cout << "found: " << it_milk->first << ": " << it_milk->second << endl;

}

void usingMultimap()
{
	multimap<string, double> products = {
		{ "apple", 12.3 },
		{ "lemon", 23.4 }
	};

	products.insert({ "apple", 25.6 });
	products.insert({ "plum", 45.6 });
	products.insert({ "apple", 25.6 });
	products.insert({ "plum", 89.5 });
	products.insert({ "sweets", 56.2 });
	products.insert({ "plum", 12.5 });
	products.insert({ "plum", 47.0});
	products.insert({ "plum", 65.3 });

	for (auto p : products)
	{
		cout << p.first << ": " << p.second << endl;
	}

	cout << endl;
	auto it_milk = products.find("plum");
	if (it_milk != products.end())
		cout << "found: " << it_milk->first << ": " << it_milk->second << endl;

	
	auto l_it = products.lower_bound("plum");
	auto u_it = products.upper_bound("plum");

	cout << endl;
	cout << "lower_bound(plum)" << l_it->first << ": " << l_it->second << endl;
	cout << "upper_bound(plum)" << u_it->first << ": " << u_it->second << endl;

	cout << endl;
	for (; l_it != u_it; l_it++)
	{
		cout << l_it->first << ": " << l_it->second << endl;
	}

	auto pair_it = products.equal_range("apple");

	cout << endl;
	for (auto it = pair_it.first; it != pair_it.second; it++)
		cout << it->first << ": " << it->second << endl;
}

void usingCompare()
{
	less<int> isLess;
	bool b = isLess(12, 24); //isLess.operator(12, 24)

	multimap<string, double, greater<string> > products = {
		{ "apple", 12.3 },
		{ "lemon", 23.4 }
	};

	products.insert({ "apple", 25.6 });
	products.insert({ "plum", 45.6 });
	products.insert({ "apple", 25.6 });
	products.insert({ "plum", 89.5 });
	products.insert({ "sweets", 56.2 });
	products.insert({ "plum", 12.5 });
	products.insert({ "plum", 47.0 });
	products.insert({ "plum", 65.3 });

	for (auto p : products)
	{
		cout << p.first << ": " << p.second << endl;
	}
}
