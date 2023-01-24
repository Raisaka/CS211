#ifndef LL_H
#define LL_H
#include <string>

using namespace std;
typedef string el_t;

struct node
{
  el_t elem;
  node* next;

};

class LL
{
 private:
  node* front;
  node* rear;
  int count;
  void queueError(string msg);

 public:
  LL();
  ~LL();
  void addRear(el_t el);
  el_t deleteFront();
  bool isEmpty() const;
  void displayAll() const;
  void addFront(el_t el);
  el_t deleteRear();
  void operator=(const LL& L);
  LL(const LL& source);
  void deleteNode(el_t el);
  bool search(el_t el);
  void addInOrderAscend(el_t el);
  void addInOrderDescend(el_t el);

};
#endif
