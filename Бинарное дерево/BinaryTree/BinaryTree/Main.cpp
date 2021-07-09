#include "Tree.h"
#include <string>
using std::string;

int main()
{
	Tree<int, string> tree;

	tree.Add(8, "aaaa");
	tree.Add(3, "bbbb");
	tree.Add(10, "cccc");
	tree.Add(1, "dddd");
	tree.Add(6, "eeee");
	tree.Add(9, "ffff");
	tree.Add(14, "gggg");

	tree.Print();
/*
	tree[1] = "zzzz";

	int minKey = tree.MinKey();
	cout << "Min key: " << minKey << endl;
	cout << "Value for min key: " << tree[minKey] << endl;
	cout << "Value for key = 6: " << tree[6] << endl;	

	tree.Remove(1);
	tree.Print();
	
	tree.Remove(14);
	tree.Print();

	tree.Add(1, "qqqq");
	tree.Print();

	tree.Remove(10);
	tree.Print();

	tree.Remove(8);
	tree.Print();*/

}
