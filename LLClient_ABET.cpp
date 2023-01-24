/************************************************************
Jared Falcon
cs 211
4/21/2020

This client will be used to test various cases for the function
addInOrderAscend(). It should be able to add integers in 
ascending order 1 2 3. 
 ***********************************************************/
#include <iostream>
using namespace std;
#include "LL.h"

int main()
{
  LL L;
  
  L.addInOrderAscend(7);//if its empty, just add the node
  L.displayAll();
  cout << endl;

  L.addInOrderAscend(5);//add node before the first node
  L.displayAll();
  cout << endl;

  L.addInOrderAscend(4);//add node to be inserted before the first node
  L.displayAll();
  cout << endl;

  L.addInOrderAscend(8);//add node to be inserted at the end of the list
  L.displayAll();
  cout << endl;

  L.addInOrderAscend(6);//add new node to be inserted in the middle of the list
  L.displayAll();
  cout << endl;

  L.addInOrderAscend(8);//add new node with a previous number (8) but at the end
  L.displayAll();
  cout << endl;

  L.addInOrderAscend(4);//add the front of the list again, with the same number (4)
  L.displayAll();
  cout << endl;
  
  return 0;
}
