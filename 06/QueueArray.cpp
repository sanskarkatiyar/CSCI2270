#include <iostream>
#include "QueueArray.hpp"

using namespace std;

QueueArray::QueueArray()
{
    head = -1;
    tail = -1;
    array_size = 5;
    array = new int[array_size];
}

QueueArray::~QueueArray()
{
    delete array;
}

bool QueueArray::isEmpty()
{
    return (head == -1 && tail == -1);
}

bool QueueArray::isFull()
{
    return (tail + 1 == array_size);
}


void QueueArray::enqueue(int k)
{
    if (!isFull()) {
        array[tail + 1] = k;
        tail = tail + 1;

        if (head == -1) {
            head = head + 1;
        }
    }
    else {
        cout<< "Queue is full. Cannot enqueue." <<endl;
    }
}

void QueueArray::dequeue()
{
    if(!isEmpty())
    {
        if (head == tail) {
            head = -1;
            tail = -1;
        }
        else {
            head = head + 1;
        }
    }
    else
    {
        cout<< "Empty Queue. Cannot dequeue." <<endl;
    }
}

int QueueArray::peek()
{
    if(!isEmpty())
        return array[head];
    else{
        cout<< "Empty Queue. Cannot peek." <<endl;
        return -1;
    }
}
