// BinSearch DEMO

#include <iostream>

using namespace std;

int binSearch(int key, int arr[], int size)
{
    // initialize your tracker variables
    int first = 0, last = size - 1, mid;
    
    while (first <= last)
    {
        mid = (first + last) / 2;
        cout << "first: " << first << ", last: " << last << ", mid: " << mid << ", arr[mid]: " << arr[mid] << endl;
        
        // mid = first + (last - first) / 2;    // prevent overflow
            
        if (arr[mid] == key)
            return mid;
        else if (key > arr[mid])
            first = mid + 1;
        else
            last = mid - 1;
    }
    
    cout << "first: " << first << ", last: " << last << ", mid: " << mid << " - NOT FOUND! " << endl;
    return -1;    // not found!
}

int main()
{
    int arr[] = {7, 11, 18, 24, 37, 48, 66, 78, 85, 98};
    
    int index = binSearch(50, arr, 10);
    cout << "Index for key: " << index << endl;
    
    return 0;
}
