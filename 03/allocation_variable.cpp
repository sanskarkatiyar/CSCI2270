#include <iostream>

using namespace std;

int main()
{
    int *a = new int;             // allocate memory on heap using new keyword
    *a = 10;                      // assign value using de-referencing operator

    cout << "*a: " << *a << endl;
    cout << "&a: " << &a << endl; // address of pointer variable (stack)
    cout << "a : " << a << endl;  // address pointed-to by a

    delete a;                     // free memory on heap

    return 0;
}