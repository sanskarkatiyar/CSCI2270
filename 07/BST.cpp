#include "BST.hpp"

using namespace std;

Node* recursive_insert(Node* n, int key)
{
    if (n == nullptr) {
        // cout << "Inserting " << key << endl;
        Node* tmp = new Node(key);
        return tmp;
    }
    else if (key > n->key) {
        n->right = recursive_insert(n->right, key);
    }
    else {
        n->left = recursive_insert(n->left, key);
    }

    return n;
}

Node* recursive_search(Node* n, int key)
{
    if (!n) {
        return nullptr;
    }

    if (key == n->key) {
        return n;
    }
    else if (key > n->key) {
        return recursive_search(n->right, key);
    }
    else {
        return recursive_search(n->left, key);
    }
}

void recursive_preorder(Node* n)
{
    if (n) {
        cout << n->key << " ";
        recursive_preorder(n->left);
        recursive_preorder(n->right);
    }
}

void recursive_inorder(Node* n)
{
    if (n) {
        recursive_inorder(n->left);
        cout << n->key << " ";
        recursive_inorder(n->right);
    }
}

void recursive_postorder(Node* n)
{
    if (n) {
        recursive_postorder(n->left);
        recursive_postorder(n->right);
        cout << n->key << " ";
    }
}

// ================= //
//      HELPERS      //
// ================= //
void print2DUtil(Node *n, int space = 0, int COUNT = 10)  
{  
    if (n == NULL)  
        return;  
  
    space += COUNT;  
    
    print2DUtil(n->right, space);  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<n->key<<"\n";  
  
    print2DUtil(n->left, space);  
}  

// ================= //
//   CLASS METHODS   //
// ================= //
BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    // TODO: Try this on your own! Currently, it causes a mem-leak.
    //       Which order will be the best?

    root = nullptr;
}

int BST::search(int key)
{
    Node* temp = recursive_search(root, key);
    if (temp) return temp->key;
    return -1;
}

void BST::insert(int key)
{
    if (root == nullptr) {
        root = new Node(key);
    }
    else {
        root = recursive_insert(root, key);
    }
}

void BST::traverse(int order)
{
    switch(order)
    {
        case 1: recursive_preorder(root); break;
        case 2: recursive_inorder(root); break;
        case 3: recursive_postorder(root); break;
        default: cout << "arg order is incorrect" << endl;
    }
}

void BST::print()
{
    print2DUtil(root);
}