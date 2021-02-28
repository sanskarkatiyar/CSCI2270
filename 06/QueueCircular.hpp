#ifndef QUEUECIRCULAR_HPP
#define QUEUECIRCULAR_HPP

class QueueCircular
{
  private:
    int *array;
    int array_size;
    int head;      // define head index var
    int tail;      // define tail index var

  public:
    QueueCircular();      // constructor
    ~QueueCircular();     // destructor
  
    void enqueue(int k);
    void dequeue();
    int peek();

    bool isEmpty(); // helper function
    bool isFull(); // helper function

};

#endif
