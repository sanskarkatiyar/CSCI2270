#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int *p = &a;

    cout << p << ", " << &a << ", " << *p << endl;

    *p = *p + 2;

    cout << a << ", " << *p << endl;

    return 0;
}
