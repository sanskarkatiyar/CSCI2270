#include <iostream>
#include "StackArray.hpp"

using namespace std;

int main() 
{
    StackArray stack = StackArray();

    // insert elements into the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    // peek and pop until stack is empty
    while (!stack.isEmpty()) {
        cout << stack.peek() << " ";
        stack.pop();
    }

    cout << endl;

    return 0;
}