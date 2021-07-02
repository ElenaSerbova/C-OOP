#include <iostream>
#include <string>
using namespace std;

#include "Queue.h"
#include "PriorityQueue.h"

void TestQueue()
{
    Queue<int> queue;

    queue.Push(1);
    queue.Push(2);
    queue.Push(3);

    while (queue.GetSize() != 0)
    {
        cout << queue.Top() << endl;
        queue.Pop();
    }

    Queue<int> queue1 = queue;
    queue1 = queue;

    Queue<int> queue2 = move(queue1);
    queue1 = move(queue2);
}
void TestPriorityQueue()
{
    PriorityQueue<string> queue;

    queue.Push("document1");
    queue.Push("document2");
    queue.Push("document3", Priority::High);
    queue.Push("document4", Priority::Low);

    while (queue.GetSize() != 0)
    {
        QueueItem<string> element = queue.Top();

        switch (element.priority)
        {
        case Priority::High:
            cout << "High => ";
            break;
        case Priority::Normal:
            cout << "Normal => ";
            break;
        case Priority::Low:
            cout << "Low => ";    
            break;
        }
        cout << element.value << endl;
        queue.Pop();
    }
}

int main()
{   
    //size_t a = 0; //0 - 4294967295
    //a--;
    //cout << a << endl;

    //TestQueue();
    TestPriorityQueue();
}
