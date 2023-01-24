#ifndef STACK_H
#define STACK_H
#include <string>

using namespace std;
const int MAX = 30;
typedef char el_t;
class Stack
{
  //  typedef int el_t;
 private:
  //typedef string el_t;
  el_t el[MAX];
  int top;
  void stackError(string msg) const; 
 
 public:
  Stack();
  bool isEmpty() const;
  bool isFull() const;
  void push(el_t e);
  el_t pop();
  el_t topElem() const;
  void displayAll() const;
  void clearIt();
};
#endif
