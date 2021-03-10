#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

void preorder(Node* root)
{
    if(root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root)
{
    if(root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(Node* root)
{
    if(root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void print2DUtil(Node *root, int num_nodes, int space);

int main()
{
    // create the tree
    Node *root         = new Node(1);
    root->left         = new Node(2);
    root->right        = new Node(3);
    root->left->left   = new Node(4);
    root->left->right  = new Node(5);

    // print the tree 
    print2DUtil(root, 5, 0);
    cout << endl;

    // preorder traversal
    cout << "PREORDER : ";
    preorder(root);
    cout << endl;

    // inorder traversal
    cout << "INORDER  : ";
    inorder(root);
    cout << endl;

    // postorder traversal
    cout << "POSTORDER: ";
    postorder(root);
    cout << endl;

    return 0;
}

// helper function to print the tree
void print2DUtil(Node *root, int num_nodes, int space)
{
    if (root == NULL)
        return;

    space += num_nodes;
    print2DUtil(root->right, num_nodes, space);
    printf("\n");

    for (int i = num_nodes; i < space; i++)
        printf(" ");

    printf("%d\n", root->data);
    print2DUtil(root->left, num_nodes, space);
}