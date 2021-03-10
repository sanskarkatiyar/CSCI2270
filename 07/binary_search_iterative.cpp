// Binary Search (Ascending order, Iterative)
#include <iostream>

using namespace std;

int binSearch(int key, int arr[], int size)
{
    // initialize your tracker variables
    int first = 0, last = size - 1, mid;
    
    while (first <= last)            // while a valid search space is available
    {
        mid = (first + last) / 2;    // find the mid point

        if (arr[mid] == key)         // if it is what we were looking for
            return mid;
        else if (key > arr[mid])     // if it is smaller than what we were looking for
            first = mid + 1;
        else
            last = mid - 1;          // if it is greater than what we were looking for
    }
    
    return -1;                       // not found!
}

int main()
{
    int arr[] = {7, 11, 18, 24, 37, 48, 66, 78, 85, 98};
    
    cout << "Index for 66: " << binSearch(66, arr, 10) << endl;
    cout << "Index for 50: " << binSearch(50, arr, 10) << endl;
    
    return 0;
}
