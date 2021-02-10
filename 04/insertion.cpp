#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void printList(Node* head)
{
    Node * tmp = head;
    while(tmp) {
        cout << tmp->data << " -> ";
        tmp = tmp -> next;
    }
    cout << "NULL"<<endl;
}

int main(int argc, char* argv[])
{
    // build the list
    // Node *head = NULL;
    Node * head = new Node({10, nullptr});
    head->next = new Node({4, nullptr});
    head->next->next = new Node({13, nullptr});
    head->next->next->next = new Node({2, nullptr});
    head->next->next->next->next = new Node({22, nullptr});
    head->next->next->next->next->next = new Node({9, nullptr});

    // print the list
    printList(head);

    // load the inputs
    if(argc != 3 || atoi(argv[2]) < 0) {
        cout << "Invalid key, pos (command line arguments)" << endl;
        return 0;
    }

    int key = atoi(argv[1]);
    int pos = atoi(argv[2]);
    int postemp = pos;

    // Create a new node
    Node* tmp = new Node({key, nullptr});

    if(!pos || !head) {
        // pos==0, or if list is empty
        // rewiring
        tmp->next = head;
        head = tmp;
    }
    else {
        Node* prev = head; // to hold previous node pointer

        // find the previous node pointer
        while(prev->next && --pos) {
            prev = prev->next;
        }

        // rewiring
        tmp->next = prev->next;
        prev->next = tmp;
    }

    // printing out changes
    cout << endl << "After Inserting " << key << " at pos " << postemp << endl;
    printList(head);

    return 0;
}