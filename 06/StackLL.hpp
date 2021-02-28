#ifndef STACKLL_HPP
#define STACKLL_HPP

class StackLL
{
  private:
    struct Node
    {
        int data;
        Node *next;
    };

    Node* top;      // define top pointer

  public:
    StackLL();      // constructor
    ~StackLL();     // destructor
  
    void push(int k);
    void pop();
    int peek();

    bool isEmpty(); // helper function
};

#endif
