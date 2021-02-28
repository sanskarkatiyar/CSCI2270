#include <iostream>
#include "StackArray.hpp"

using namespace std;

StackArray::StackArray()
{
    top = -1;
    array_size = 1000;
    array = new int[array_size];
}

StackArray::~StackArray()
{
    delete [] array;
    array = nullptr;
}

bool StackArray::isEmpty()
{
    return (top == -1);
}

bool StackArray::isFull()
{
    return (top + 1 == array_size);
}


void StackArray::push(int k)
{
    if (!isFull()) {
        array[top + 1] = k;
        top = top + 1;
    }
    else {
        cout<< "Stack is full. Cannot push." <<endl;
    }
}

void StackArray::pop()
{
    if(!isEmpty())
    {
        top = top - 1;
    }
    else
    {
        cout << "Empty Stack. Cannot pop." <<endl;
    }
}

int StackArray::peek()
{
    if(!isEmpty())
        return array[top];
    else{
        cout<< "Empty Stack. Cannot peek." <<endl;
        return -1;
    }
}
