#ifndef DLL_H
#define DLL_H
#include <string>

using namespace std;
typedef int el_t;

struct node
{
  el_t elem;
  node* next;
  node* prev;
};

class DLL
{
 private:
  node* front;
  node* rear;
  int count;
  void queueError(string msg);

 public:
  DLL();
  ~DLL();
  void addRear(el_t el);
  
  el_t deleteFront();
  bool isEmpty() const;
  void displayAll() const;
  void addFront(el_t el);
  el_t deleteRear();
  void operator=(const DLL& L);
  DLL(const DLL& source);
  void deleteNode(el_t el);
  void deleteNodes(el_t el);
  bool search(el_t el);
  void addInOrderAscend(el_t el);
  void addInOrderDescend(el_t el);
  void printAllReverseDLL() const;
  
};
#endif
