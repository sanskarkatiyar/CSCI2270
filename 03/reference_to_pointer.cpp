#include <iostream>
using namespace std;

void printArray(int * a, int n);
void swap_array_1(int * a, int * b);
void swap_array_2(int * &a, int * &b);

// Q. Try passing args by reference in swap_array_1.
// What do you expect to happen, and does that happen?

int main()
{
    int a[5] = {0, 1, 2, 3, 4};
    int b[5] = {5, 6, 7, 8, 9};

    cout << "Before swap_array_1: " << endl;
    printArray(a, 5);
    printArray(b, 5);

    swap_array_1(a, b);

    cout << "After  swap_array_1: " << endl;
    printArray(a, 5);
    printArray(b, 5);

    cout << "----------" << endl;

    int* arr = new int[5];
    for (int i = 0; i < 5; i++) arr[i] = 10 + i;

    int* brr = new int[5];
    for (int i = 0; i < 5; i++) brr[i] = 20 + i;

    cout << "Before swap_array_2: " << endl;
    printArray(arr, 5);
    printArray(brr, 5);

    swap_array_2(arr, brr);

    cout << "After  swap_array_2: " << endl;
    printArray(arr, 5);
    printArray(brr, 5);

    return 0;
}

void printArray(int * a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}

void swap_array_1(int * a, int * b)
{
    int * tmp = a;
    a = b;
    b = tmp;

    cout << "Inside swap_array_1: " << endl;
    printArray(a, 5);
    printArray(b, 5);
}

void swap_array_2(int * &a, int * &b)
{
    int * tmp = a;
    a = b;
    b = tmp;

    cout << "Inside swap_array_2: " << endl;
    printArray(a, 5);
    printArray(b, 5);
}

