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
    Node * head = new Node({10, nullptr});
    head->next = new Node({4, nullptr});
    head->next->next = new Node({13, nullptr});
    head->next->next->next = new Node({2, nullptr});
    head->next->next->next->next = new Node({22, nullptr});
    head->next->next->next->next->next = new Node({9, nullptr});

    // print the list
    printList(head);

    // check for list
    if (!head) {
        cout << "Empty List!" << endl;
        return 0;
    }

    // SIMPLE APPROACH
    // ===============

    Node* temp = head;

    while(head) 
    {
        temp = head;
        head = head->next;
        cout << "Deleting: " << temp->data << endl;
        delete temp;
    }

    cout << endl << "After Deleting the list" << endl;
    printList(head);


/*    
    // ALTERNATIVE APPROACH
    // ====================

    // setup pointers
    Node* prev = head;
    Node* curr = head->next;

    // traverse and delete
    while(curr != NULL) {
        cout << "Deleting: " << prev->data << endl;
        delete prev;
        prev = curr;
        curr = curr->next;
    }

    // delete last node
    cout << "Deleting: " << prev->data << endl;
    delete prev;

    // rewire head node
    head = NULL;

    // printing out changes
    cout << endl << "After Deleting the list" << endl;
    printList(head);
*/

    return 0;
}