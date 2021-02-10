#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int i = 0;
    int NUM = argc == 2 ? atoi(argv[1]) : 10; // ternary assignment

    // allocate memory for array on heap
    int *A = new int[NUM]; 

    // write elements into the array
    for(int i = 0; i < NUM; i++) {
        A[i] = i * 3;
    }

    // print all elements of the array
    for(i = 0; i < NUM; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // free entire array's memory on heap
    delete [] A;

    return 0;
}