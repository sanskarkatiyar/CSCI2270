#ifndef STACKARRAY_HPP
#define STACKARRAY_HPP

class StackArray
{
  private:
    int *array;
    int array_size;
    int top;

  public:
    StackArray();      // constructor
    ~StackArray();     // destructor
  
    void push(int k);
    void pop();
    int peek();

    bool isEmpty();
    bool isFull();

};

#endif
