#ifndef QUEUE_H
#define QUEUE_H
#include <string>

using namespace std;
enum op {ADD, SUB, MULT, DIV};

struct expr
{
  int oprd1;
  op oprt;
  int oprd2;
};

const int MAX = 10;
typedef expr el_t;//match struct
class Queue
{
 private:
  el_t el[MAX];
  int count;
  int front;
  int rear;

  void queueError(string msg) const;

 public:
  // constructor 
  Queue(); 
  // returns true if queue is empty, otherwise false
  bool isEmpty() const;
  // returns true if queue is full, otherwise false
  bool isFull() const;
  // if full, calls an emergency exit routine
  // if not full, changes rear to the next slot and enters an element at rear 
  void add(el_t e);
  // if empty, calls an emergency exit routine
  // if not empty, remove(return)the front element and change front to the next slot
  el_t remove();
  // if empty, calls an emergency exit routine
  // if not empty, returnthe front element (but does not remove it)
  el_t getFront() const;
  //if empty, calls an emergency exit routine
  //if queue has just 1 element, does nothing
  //if queue has more than 1 element, moves the front one to the rear
  void goToBack();
  //returns the current size
  int getSize() const;
  void displayAll() const;






};
#endif
