#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int *p, *q;

    p = &a;
    q = &a;

    // Value stored in variable a
    cout << "a : " << a << endl;

    // Address of variable p
    cout << "&p: " << &p << endl;

    // Value stored in variable p
    cout << "p : " << p << endl;

    // Value stored in variable p, by deref.
    cout << "*p: " << *p << endl;

    cout << "&q: " << &q << endl;
    cout << "q : " << q << endl;
    cout << "*q: " << *q << endl;

    return 0;
}
