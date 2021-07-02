#include <iostream>
using namespace std;

#include "Stack.h"

int main()
{
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    int size = stack.GetSize();

    for (size_t i = 0; i < size; i++)
    {
        cout << stack.Top() << endl;
        stack.Pop();
    }  


    Stack<int> stack1 = stack;
    stack1 = move(stack);


}

