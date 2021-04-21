#include <iostream>
#include <limits.h>

using namespace std;

// --------------------------------- <NODE:beg> --------------------------------
class Node 
{
  public: 
    string name;
    int key;
};

// bool Node::operator < (Node const &p, Node const &q) { return p.key < q.key; }
// bool Node::operator == (Node const &p, Node const &q) { return p.key == q.key; }
// bool Node::operator > (Node const &p, Node const &q) { return p.key > q.key; }

// --------------------------------- <NODE:end> --------------------------------

// -------------------------------- <MaxHeap:beg> ------------------------------

class MaxHeap
{
  Node* heapArr;
  int capacity;
  int currentSize;

public:
  MaxHeap(int capacity, bool verbose);
  int parent(int index);
  int leftChild(int index);
  int rightChild(int index);

  Node getMax();
  void extractMax(bool verbose);

  void insertElement(int priority, string value, bool verbose); 
  void deleteElement(string value, bool verbose);
  void MaxHeapify(int index);
  void BuildMaxHeap();
  void print();
};

void swap(Node &a, Node &b)
{
  int k = a.key;
  string s = a.name;

  a.name = b.name;
  a.key = b.key;
  b.name = s;
  b.key = k;
}

MaxHeap::MaxHeap(int cap, bool verbose=true)
{
  currentSize = 0;
  capacity = cap;
  heapArr = new Node[capacity];

  if(verbose) {
    cout << "[INFO] Created MaxHeap object with capacity = " << capacity << endl;
  }
}

int MaxHeap::parent(int index) { return (index-1)/2; }
int MaxHeap::leftChild(int index) { return ((2*index) + 1); }
int MaxHeap::rightChild(int index) { return ((2*index) + 2); }
Node MaxHeap::getMax() { return heapArr[0]; }

void MaxHeap::MaxHeapify(int i)
{
  // assumes subtrees are MaxHeaps
  int l = leftChild(i);
  int r = rightChild(i);
  int largest = i;

  if(l < currentSize && heapArr[l].key > heapArr[i].key && (r >= currentSize || heapArr[l].key > heapArr[r].key)) {
    largest = l;
  }
  else if(r < currentSize && heapArr[r].key > heapArr[i].key) {
    largest = r;
  }

  if(largest != i) {
    swap(heapArr[i], heapArr[largest]);
    MaxHeapify(largest);
  }
}

void MaxHeap::insertElement(int priority, string value, bool verbose = true)
{
  if(currentSize == capacity)
  {
    cout << "[ERROR] Maximum heap size reached. Cannot insert anymore." << endl;
    return;
  }

  currentSize = currentSize + 1;
  int index = currentSize - 1;

  heapArr[index].name = value;
  heapArr[index].key = priority;

  while (index != 0 && heapArr[parent(index)].key < heapArr[index].key)
  {
      swap(heapArr[index], heapArr[parent(index)]);
      index = parent(index);
  }


  if(verbose) {
    cout << "[INFO] Inserted: " << value << " (priority = " << priority << ")" << endl;
  }

}

void MaxHeap::BuildMaxHeap()
{
  for(int i = currentSize/2 - 1; i >= 0; i--) {
    MaxHeapify(i);
  }
}

void MaxHeap::print()
{
  cout << "[INFO] Printing heapArr:" << endl;
  int iter = 0;
  while(iter < currentSize)
  {
    cout<< heapArr[iter].name << " (" << heapArr[iter].key << ") | ";
    iter = iter + 1;
  }
  cout << endl;
}

void MaxHeap::extractMax(bool verbose = true)
{
  if (currentSize <= 0) {
    if(verbose) {
      cout << "[ERROR] ExtractMax failed. Empty heap." << endl;
    }
    return;
  }

  if (currentSize == 1)
  {
      currentSize = currentSize - 1;
      return;
  }

  string stemp = heapArr[0].name;
  int itemp = heapArr[0].key;

  heapArr[0] = heapArr[currentSize - 1];
  currentSize = currentSize - 1;
  MaxHeapify(0);

  if(verbose) {
    cout << "[INFO] ExtractMax: " << stemp << " (priority = " << itemp << ")" << endl;
  }
}

void MaxHeap::deleteElement(string value, bool verbose = true)
{
  if (currentSize <= 0)
    return;

  // find the index for name == value
  int index = -1;
  for(int i = 0; i < currentSize; i++) {
    if(heapArr[i].name == value) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    cout << "[ERROR]: Object name == " << value << " not found." << endl;
    return;
  }

  heapArr[index].key = INT_MAX;

  while (index != 0 && heapArr[parent(index)].key < heapArr[index].key)
  {
      swap(heapArr[index], heapArr[parent(index)]);
      index = parent(index);
  }

  extractMax(false);

  cout << "[INFO] Deleted " << value << endl;
}

// -------------------------------- <MaxHeap:end> ------------------------------