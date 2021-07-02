#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"
using namespace std;

int main()
{
   /* DynamicArray<int> arrayInt;
    arrayInt.AddElement(123);

    DynamicArray<double> arrayDouble;
    arrayDouble.AddElement(12.3);*/
    
   
    cout << "--- Stack ---" << endl;
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);  
    
    size_t size = stack.GetSize();
    for (size_t i = 0; i < size; i++)
    {
        cout << stack.Pop() << endl;
    }

    
    cout << "--- Queue ---" << endl;
    Queue<int> queue;
    queue.Push(1);
    queue.Push(2);
    queue.Push(3);

    size = queue.GetSize();
    for (size_t i = 0; i < size; i++)
    {
        cout << queue.Pop() << endl;
    }
    

    /*cout << "--- Priority Queue --- " << endl;

    PriorityQueue<int> pqueue;
    pqueue.Push(1);
    pqueue.Push(2, PriorityQueue<int>::HIGH);
    pqueue.Push(3, PriorityQueue<int>::LOW);
    pqueue.Push(4, PriorityQueue<int>::HIGH);

    size_t size = pqueue.GetSize();
    for (size_t i = 0; i < size; i++)
    {
        cout << pqueue.Pop() << endl;
    }
    */

}
