#include <iostream>
#include "QueueCircular.hpp"

using namespace std;

int main() 
{
    QueueCircular queue = QueueCircular();
    int i = 1;
    // insert elements into the queue
    queue.enqueue(10);
    cout << "Enqueued = " << (10 * i++) << endl;
    cout << "Peek = " << queue.peek() << endl<< endl;

    queue.enqueue(20);
    cout << "Enqueued = " << (10 * i++) << endl;
    cout << "Peek = " << queue.peek() << endl<< endl;

    queue.enqueue(30);
    cout << "Enqueued = " << (10 * i++) << endl;
    cout << "Peek = " << queue.peek() << endl<< endl;

    queue.enqueue(40);
    cout << "Enqueued = " << (10 * i++) << endl;
    cout << "Peek = " << queue.peek() << endl<< endl;

    queue.enqueue(50);
    cout << "Enqueued = " << (10 * i++) << endl;
    cout << "Peek = " << queue.peek() << endl<< endl;

    cout << "Dequeue = " << queue.peek() << endl << endl;
    queue.dequeue();

    cout << "Dequeue = " << queue.peek() << endl << endl;
    queue.dequeue();

    queue.enqueue(60);
    cout << "Enqueued = " << (10 * i++) << endl;
    cout << "Peek = " << queue.peek() << endl<< endl;

    queue.enqueue(70);
    cout << "Enqueued = " << (10 * i++) << endl;
    cout << "Peek = " << queue.peek() << endl<< endl;

    queue.enqueue(80); // full error 


    // peek and dequeue until queue is empty
    cout << endl << "QUEUE: ";
    while (!queue.isEmpty()) {
        cout << queue.peek() << " ";
        queue.dequeue();
    }

    cout << endl;

    return 0;
}