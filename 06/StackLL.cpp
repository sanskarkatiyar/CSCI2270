#include <iostream>
#include "StackLL.hpp"

using namespace std;

StackLL::StackLL()
{
    top = nullptr;
}

StackLL::~StackLL()
{
    while(!isEmpty())
        pop();
}

bool StackLL::isEmpty()
{
    return (top == nullptr);
}

void StackLL::push(int k)
{
    // dynamically create a new node
    Node* nn = new Node;
    nn->data = k;
    nn->next = nullptr;

    // modifying the top
    nn->next = top;
    top = nn;
}

void StackLL::pop()
{
    if(!isEmpty())
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    else
    {
        cout<< "Empty Stack. Cannot pop." <<endl;
    }
}

int StackLL::peek()
{
    if(!isEmpty())
        return top->data;
    else{
        cout<< "Empty Stack. Cannot peek." <<endl;
        return -1;
    }
}
