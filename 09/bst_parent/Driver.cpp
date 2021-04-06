#include "BSTParent.hpp"
#include <iostream>

using namespace std;

int main()
{
    BST tree;

    // Build the tree
    tree.insert(10);
    tree.insert(9);
    tree.insert(15);
    tree.insert(8);
    tree.insert(44);
    tree.insert(22);
    tree.insert(33);
    tree.insert(18);

    tree.print(); cout << endl;

    cout << "SEARCH (23): " << tree.search(23) << endl;
    cout << "SEARCH (33): " << tree.search(33) << endl;

    cout << "MAXIMUM: " << tree.find_max() << endl;
    cout << "MINIMUM: " << tree.find_min() << endl;

    cout << "PREORDER: "; tree.traverse(1); cout << endl;
    cout << "INORDER: "; tree.traverse(2); cout << endl;
    cout << "POSTORDER: "; tree.traverse(3); cout << endl;

    cout << "REMOVING (22)" << endl; tree.remove(22);
    cout << "REMOVING (10)" << endl; tree.remove(10);

    tree.print(); cout << endl;
    
    return 0;
}