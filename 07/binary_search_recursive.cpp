// Binary Search (Ascending order, Recursive)
#include <iostream>

using namespace std;

int binSearch(int key, int arr[], int first, int last)
{
    int mid = (first + last) / 2;          // find the mid point
    
    if (first > last)                      // if a valid search space is not available, item DNE
        return -1;
    else if (arr[mid] == key)              // if it is what we were looking for
        return mid;
    else if (key > arr[mid])               // if it is smaller than what we were looking for
        return binSearch(key, arr, mid + 1, last);
    else                                   // if it is greater than what we were looking for
        return binSearch(key, arr, first, mid - 1);
}

int main()
{
    int arr[] = {7, 11, 18, 24, 37, 48, 66, 78, 85, 98};
    
    cout << "Index for 66: " << binSearch(66, arr, 0, 9) << endl;
    cout << "Index for 50: " << binSearch(50, arr, 0, 9) << endl;
    
    return 0;
}
