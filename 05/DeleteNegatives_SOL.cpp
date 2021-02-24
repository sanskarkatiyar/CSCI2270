#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void deleteNegatives(Node* &head);
void printList(Node* head);

int main(int argc, char* argv[])
{
    // ----------- //
    // TEST CASE 1 //
    // ----------- //
    Node* head1 = new Node({-10, nullptr});
    head1->next = new Node({11, nullptr});
    head1->next->next = new Node({-12, nullptr});
    head1->next->next->next = new Node({-13, nullptr});
    head1->next->next->next->next = new Node({14, nullptr});
    head1->next->next->next->next->next = new Node({-15, nullptr});

    cout << "INPUT : ";
    printList(head1);

    deleteNegatives(head1);

    cout << "OUTPUT: ";
    printList(head1);

    // ----------- //
    // TEST CASE 2 //
    // ----------- //
    Node* head2 = new Node({-10, nullptr});
    head2->next = new Node({-11, nullptr});
    head2->next->next = new Node({-12, nullptr});
    head2->next->next->next = new Node({13, nullptr});
    head2->next->next->next->next = new Node({14, nullptr});
    head2->next->next->next->next->next = new Node({-15, nullptr});
    
    cout << endl << "INPUT : ";
    printList(head2);

    deleteNegatives(head2);

    cout << "OUTPUT: ";
    printList(head2);

    // ----------- //
    // TEST CASE 3 //
    // ----------- //
    Node* head3 = new Node({-10, nullptr});
    head3->next = new Node({-11, nullptr});
    head3->next->next = new Node({-12, nullptr});
    head3->next->next->next = new Node({-13, nullptr});
    head3->next->next->next->next = new Node({-14, nullptr});
    head3->next->next->next->next->next = new Node({-15, nullptr});

    cout << endl << "INPUT : ";
    printList(head3);

    deleteNegatives(head3);

    cout << "OUTPUT: ";
    printList(head3);

    // ----------- //
    // TEST CASE 4 //
    // ----------- //
    Node* head4 = nullptr;
    cout << endl << "INPUT : ";
    printList(head4);

    deleteNegatives(head4);

    cout << "OUTPUT: ";
    printList(head4);

    // ----------- //
    // TEST CASE 5 //
    // ----------- //
    Node* head5 = new Node({-1, nullptr});
    cout << endl << "INPUT : ";
    printList(head5);

    deleteNegatives(head5);

    cout << "OUTPUT: ";
    printList(head5);

    return 0;
}

void deleteNegatives(Node* &head)
{
    // Set up for deleting a node
    Node* prev = nullptr;
    Node* curr = head;

    // Repeatedly process elements
    while (curr != nullptr)
    {
        // if the node contains negative value
        if (curr->data < 0)
        {
            if (prev == nullptr)
            {
                // deleting the head node
                head = head->next;
                delete curr;
                curr = head;
            }
            else
            {
                // delete an intermediate node
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        }
        else
        {
            // positive node, so move forward
            prev = curr;
            curr = curr->next;
        }
    }
}

void printList(Node* head)
{
    Node* curr = head;

    while (curr != NULL)
    {
        cout << curr->data << " -> ";
        curr = curr->next;
    }

    cout << "NULL" << endl;
}