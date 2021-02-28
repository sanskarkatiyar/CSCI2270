#include <iostream>
#include "QueueCircular.hpp"

using namespace std;

QueueCircular::QueueCircular()
{
    head = -1;
    tail = -1;
    array_size = 5;
    array = new int[array_size];
}

QueueCircular::~QueueCircular()
{
    delete [] array;
}

bool QueueCircular::isEmpty()
{
    return (head == -1 && tail == -1);
}

bool QueueCircular::isFull()
{
    return (head == (tail + 1) % array_size);
}

void QueueCircular::enqueue(int k)
{
    if (!isFull()) {
        tail = (tail + 1) % array_size;
        array[tail] = k;

        if (head == -1) {
            head = head + 1;
        }
    }
    else {
        cout<< "Queue is full. Cannot enqueue." <<endl;
    }


}

void QueueCircular::dequeue()
{
    if(!isEmpty())
    {
        if (head == tail) {
            head = -1;
            tail = -1;
        }
        else {
            head = (head + 1) % array_size;
        }
    }
    else
    {
        cout<< "Empty Queue. Cannot dequeue." <<endl;
    }
}

int QueueCircular::peek()
{
    if(!isEmpty())
        return array[head];
    else{
        cout<< "Empty Queue. Cannot peek." <<endl;
        return -1;
    }
}
