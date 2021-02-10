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
    cout << "NULL"<< endl;
}

int main(int argc, char* argv[])
{
    // build the list
    Node * head = new Node({10, nullptr});
    head->next = new Node({4, nullptr});
    head->next->next = new Node({13, nullptr});
    head->next->next->next = new Node({2, nullptr});
    head->next->next->next->next = new Node({22, nullptr});
    head->next->next->next->next->next = new Node({9, nullptr});

    // print the list
    printList(head);

    if(argc != 2) {
        cout << "Invalid key (command line argument)" << endl;
        return 0;
    } 
    else if (!head) {
        cout << "Empty List!" << endl;
        return 0;
    }

    // searching!
    int key = atoi(argv[1]); // data we are looking for (arg)
    int pos = 0;             // keep track of node's position
    Node* tmp = head;        // temp pointer to traverse the list

    // loop through the list
    while(tmp != nullptr) {
        // check if the item is found
        if(tmp->data == key) {
            cout << "Found key at offset: " << pos << endl;
            return 0;
        }
        // move to next node
        tmp = tmp->next;
        pos++;
    }

    cout << "Did not find key in the list. " << endl;

    return 0;
}