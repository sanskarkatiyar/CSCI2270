#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* KthFromLast(Node* head, int k);
void printList(Node* head);
Node* constructList(vector<int> v);

int main(int argc, char* argv[])
{
    // use command-line args to get value of k
    int k = argc == 2 ? atoi(argv[1]) : 1;

    // construct the list
    Node* head1 = new Node({-10, nullptr});
    head1->next = new Node({11, nullptr});
    head1->next->next = new Node({-12, nullptr});
    head1->next->next->next = new Node({-13, nullptr});
    head1->next->next->next->next = new Node({14, nullptr});
    head1->next->next->next->next->next = new Node({-15, nullptr});

    // process and print
    cout << "INPUT : k = " << k << ", ";
    printList(head1);

    Node* result = KthFromLast(head1, k);

    cout << "OUTPUT: " << result->data << endl;

    return 0;
}

Node* KthFromLast(Node* head, int k)
{
    // TODO: Complete this section
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

