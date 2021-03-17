#include <iostream>
#include <array>
#include <forward_list>
#include <stack>
#include <queue>
#include <deque>
#include <set>

using namespace std;

void UsingArray();
void UsingForwardList();
void UsingStack();
void UsingQueue();
void UsingDeque();
void UsingPriorityQueue();
void UsingSet();

int main()
{
    //UsingArray();
    //UsingForwardList();
    //UsingStack();
    //UsingQueue();
    //UsingDeque();
    UsingPriorityQueue();
    //UsingSet();
}

void UsingArray()
{
    array<int, 10> arr = { 1,2,3,4,5,6,7,8,9,10 };

    arr[5] = 15;

    for (int el : arr)
    {
        cout << el << "\t";
    }
    cout << endl;

    /*int* p = arr.data();
    delete[] p;*/

    arr.fill(100);

    for (int el : arr)
    {
        cout << el << "\t";
    }
    cout << endl;
}

void UsingForwardList()
{
    forward_list<int> list = { 12, 15, 6, 7 };
    list.push_front(100);

    auto it = list.begin();
    advance(it, 3);
    list.insert_after(it, 200);

    for (auto el : list)
    {
        cout << el << "\t";
    }
    cout << endl;

    list.remove_if([](int el) { return el % 2 != 0; });
   
    for (auto el : list)
    {
        cout << el << "\t";
    }
    cout << endl;
}

void UsingStack()
{
    stack<int> st;
    st.push(12);
    st.push(18);
    st.push(11);
    st.push(56);  

    /*
    int size = st.size();

    for (size_t i = 0; i < size; i++)
    {
        cout << "Top element: " << st.top() << endl;
        st.pop();
    }
    */

    while (!st.empty())
    {
        cout << "Top element: " << st.top() << endl;
        st.pop();
    }
}

void UsingQueue()
{
    queue<int> q;

    q.push(12);
    q.push(15);
    q.push(7);
    q.push(23);
    q.push(54);
    q.push(32);

    while (!q.empty())
    {
        cout << "Element: " << q.front() << endl;
        q.pop();
    }
}

void UsingDeque()
{
    deque<int> deq;
    deq.push_back(10);
    deq.push_front(20);
    deq.insert(deq.begin() + 1, 30);

    for (int el : deq)
    {
        cout << el << "\t";
    }
    cout << endl;
}

void UsingPriorityQueue()
{
    priority_queue<int, vector<int>, greater<int> > mypq;

    mypq.push(30);
    mypq.push(100);
    mypq.push(25);
    mypq.push(40);

    cout << "Popping out elements..." << endl;
    while (!mypq.empty())
    {
        cout << mypq.top() << "\t";
        mypq.pop();
    }
    cout << '\n';
}

void UsingSet()
{
    multiset<int, greater<int>> s;
    s.insert(100);
    s.insert(23);
    s.insert(54);
    s.insert(23);
    s.insert(1);

    for (auto el : s)
    {
        cout << el << "\t";
    }
    cout << endl;
}
