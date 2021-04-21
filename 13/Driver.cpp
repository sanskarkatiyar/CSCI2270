#include <iostream>
#include "MaxHeap.hpp"

using namespace std;

int main()
{
  MaxHeap h(11);
  h.insertElement(3, "a");
  h.insertElement(23, "b");
  h.insertElement(1, "c");
  h.insertElement(15, "d");
  h.insertElement(5, "e");
  h.insertElement(43, "f");
  h.insertElement(45, "g");
  h.print();
  h.extractMax();
  h.deleteElement("e");
  h.print();


  return 0;
}