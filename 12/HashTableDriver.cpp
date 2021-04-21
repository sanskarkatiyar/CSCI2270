#include <iostream>
#include "HashTable.hpp"

using namespace std;

int main()
{
    HashTable H(39);              // Create a new hash table with size 39
    H.loadData("Data.csv", 21);   // Load first 21 records from the given file
    H.display();                  // Display the constructed table
    H.search(121);                // Search for record 121, print value
    H.remove(121);                // Remove the record 121
    H.search(121);                // Search again to confirm successful removal
    H.display();                  // Display the updated table

    return 0;
}