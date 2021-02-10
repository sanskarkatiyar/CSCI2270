#include <iostream>

using namespace std;

// pass-by-value
void add_val(int num)
{
    num = num + 2;
    cout << num << endl;
}

// pass-by-reference
void add_ref(int &num)
{
    num = num + 2;
    cout << num << endl;
}

// pass-by-pointer
void add_ptr(int *num)
{
    *num = *num + 2;
    cout << *num << endl;
}


int main()
{
    int a = 10;

    cout << "Pass-by-value\n--------------\n";
    add_val(a);
    cout << a << endl;

    cout << "Pass-by-reference\n--------------\n";
    add_ref(a);
    cout << a << endl;

    cout << "Pass-by-pointer\n--------------\n";
    add_ptr(&a);
    cout << a << endl;

    return 0;
}