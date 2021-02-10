#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

/*
class Node
{
    public:
        int data;
        Node* next;
};
*/

int main()
{
    // build the list
    Node * head = new Node({10, nullptr});
    head->next = new Node({4, nullptr});
    head->next->next = new Node({13, nullptr});
    head->next->next->next = new Node({2, nullptr});

    // print the list
    Node * tmp = head;
    while(tmp) {
        cout << tmp->data << " -> ";
        tmp = tmp -> next;
    }
    cout << "NULL" << endl;

    return 0;
}