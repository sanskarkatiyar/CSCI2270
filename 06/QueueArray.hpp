#ifndef QUEUEARRAY_HPP
#define QUEUEARRAY_HPP

class QueueArray
{
  private:
    int *array;
    int array_size;
    int head;      // define head index var
    int tail;      // define tail index var

  public:
    QueueArray();      // constructor
    ~QueueArray();     // destructor
  
    void enqueue(int k);
    void dequeue();
    int peek();

    bool isEmpty(); // helper function
    bool isFull(); // helper function

};

#endif
