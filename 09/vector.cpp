#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> a)
{
	cout << "SIZE: " << (int) a.size() << " CAPACITY: " << (int) a.capacity() << endl << "ITEMS: ";
	for(int i = 0; i < a.size(); i++) {
		cout << a.at(i) << " " ;
	}
	cout << endl << endl;
}

void print_vector_alternative(vector<int> a)
{
	cout << "SIZE: " << (int) a.size() << " CAPACITY: " << (int) a.capacity() << endl << "ITEMS: ";
	for(vector<int>::iterator i = a.begin(); i < a.end(); i = i + 2) {
		cout << *i << " " ;
	}
	cout << endl << endl;
}

int main() {
	vector<int> a = {0, 1, 2, 3, 4 ,5, 6, 7, 8, 9, 10, 11, 12, 13};
	
	// Print the items of original vector
	print_vector(a);
	
	// Erasing the item on index 3
	cout << "Erase the item on index 3." << endl;
	a.erase(a.begin() + 3);
	
	// Print the items after erasing 
	print_vector(a);
	
	// pop an item at back
	cout << "Delete an item at the back." << endl;
	a.pop_back();
	print_vector(a);
	
	// append an item at back
	cout << "Append an item at the back." << endl;
	a.push_back(100);
	print_vector(a);

	// iterator printing
	cout << "Print alternative elements using iterator" << endl;
	print_vector_alternative(a);

	// risize the capacity of vector
	a.resize(20, -1);
	print_vector(a);
	
	a.resize(5);
	print_vector(a);

	return 0;
}