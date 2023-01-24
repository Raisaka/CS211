#include <iostream>
#include <cstdlib>
#include "DLL.h"

using namespace std;

/**************************************
msg is the message displayed

This function will output and error message
and exit the program.
 ************************************/
void DLL::queueError(string msg)
{
  cout << msg << endl;
  exit(1);
}
/***************************************
This is the default constructor that sets
front and rear to NULL and the count is 0
 **************************************/
DLL::DLL()
{
  front = NULL;
  rear = NULL;
  count = 0;
}
/***************************************
This is the destructor that will delete
anything that is left over once the object 
goes out of scope.
 **************************************/
DLL::~DLL()
{
  while(!isEmpty())//while not empty
    {
      deleteFront();//call delete, until empty
    }

}
/*
void queueError(string msg) const 
{
  cout << msg << endl;
  exit(1);
}
*/
/********************************************
el is the element we want to add to the rear

This fucntion will add a new element to the rear
of the linked list and if its the only element 
in the list. Both front and rear will point to it.
 ********************************************/
void DLL::addRear(el_t el) 
{
  node* temp = new node;//create new node
  temp->elem = el;//store element in new node
  
  if(isEmpty())//if queue is empty, both front and rear point to the same node
    {  //same as rear == NULL
      front = temp;
      rear = temp;
      front->prev = NULL;//set previous to NULL
      rear->next = NULL;//set next to NULL
      count = 1; //b/c theres only one node now
    }
  else//otherwise its just another node added to the list 
    {
      rear->next = temp;// add new node
      temp->prev = rear;//temp prev point to rear
      rear = rear->next; // rear points to new node
      rear->next = NULL; //the last node points to NULL
      count++;
    }
}

/*
void LQueue::addRear(el_t el)
{
  node* temp = new node;//create new node
  temp->elem = el;//store element into temp element cell
  if(isEmpty())//if queue is empty, both front and rear point to the same node
    {
      front = temp;
      rear = temp;
      count = 1;//only 1 element 
      return;
    }
  
  count++;//incremnt
  rear->next = temp;//add new node
  rear = rear->next;//rear now points to new node
  rear->next = NULL;//set last node to NULL
}
*/

/************************************************
 This fucntion will delete an element from the
front of the queue and return it. 
 ************************************************/
el_t DLL::deleteFront()
{
  if(rear == NULL)//check to see if its empty
    {
      queueError("Error: list is empty");
    }
  else
    {
      node* temp = front;//store front
      front = front->next;//move front to the next node
      //      temp->next->prev = NULL;
      if(front == NULL)//if deleting makes the queue empty
	{
	  //front = NULL;
	  rear = NULL;//set rear to NULL
	  //count = 0;//count to 0
	}
      count--;//decrement count 
      el_t now = temp->elem;//store the deleted element in now
      
      //front->prev = NULL;
      
      delete temp;//delete temp node 
      
      if(front != NULL)//more than one node, next node->prev = NULL;
	{
	  front->prev = NULL;
	}

      //front->prev = NULL;
      return now;//return the element to be deleted 
      //delete temp;//delete the node
      
    }
}
/***********************************************
This function will check if the queue is empty.
 ********************************************/
bool DLL::isEmpty() const 
{
  if(rear == NULL && front == NULL)//if rear and front are both NULL then its empty
    {
      return true;
    }
  else//not empty
    {
      return false;
    }
}
/*********************************************
el is the element to add to the front 

This fucntion will add a new element to the front 
of the linked list. If its only one, both front 
and rear will point to it.
 *********************************************/
void DLL::addFront(el_t el)
{
  node* temp = new node;//make a new temp node
  temp->elem = el;//add the element
 
  if(isEmpty())//if theres no other nodes
    {
      front = temp;//point to new node
      rear = temp;//also point tone new node
      front->prev = NULL;
      rear->next = NULL;
      count = 1;//count is 1
      return;
    }
  
  temp->next = front;//temp->next points to  
  temp->prev = NULL;//make temp(new node) prev point to NULL 
  if(front != NULL)//if front does not equal NULL
    {
      front->prev = temp;//make front prev point to temp
    } 
  //front points to new node
  // temp->prev = NULL; //the first node points to NULL
  front = temp;//make front point to temp
  count++;

}
/************************************************
This fucntion will erase the node at the end of 
the linked list. If its the only one, it will make
front and rear point to NULL.
 ***********************************************/
el_t DLL::deleteRear()
{
 
  if(isEmpty())//if empty, list error
    {
      queueError("Error: list is empty");
    }
  else//else delete the node
    {
      //node* temp = front;//test
      el_t L = rear->elem;//store the rear element 
 
      
      if(front->next == NULL)//if the next address is NULL, only one node
	{
	  delete rear;
	  front = NULL;//set front to NULL
	  rear = NULL;//rear to NUL
	  
	}
      else//otherwise delete
	{
	  node* p = rear->prev;
	  delete rear;
	  rear = p;
	  rear->next = NULL;
	 
	}
	  count--;//decrement count
	  return L;
    }
}
//not needed
/*
void LQueue::operator=(const LQueue& L)
{
  this->front = L.front;
  this->rear = L.rear;
  this->count = L.count;
}
*/
/*************************************************
source is the linked list we want to copy

This function will be able to copy a linked list 
without altering the new one.
***************************************************/
DLL::DLL(const DLL& source)
{
  this->front = this->rear = NULL;//this is the current or new list 
  this->count = 0;

  node* p;//make a pointer to go through the old(source) list
  p = source.front;//start at the front of the source list to copy

  while(p != NULL)//needs to go through all the nodes in source list
    {
      addRear(p->elem);//add the element to new list
      p = p->next;//go to the next node
    }

}
/*****************************************************
el is the element to delete

This function will delete a node with the specific element.
If the list is empty, it will do nothing.
 *****************************************************/
void DLL::deleteNode(el_t el)
{
  node* pre;//previous pointer 
  node* del;//points to the node that will be deleted 
 
  if(isEmpty())//empty
    {
      ;//do nothing 
    }
  else
    {
     
      if(count == 1)//if theres only one node
	{
	  if(front->elem == el)//if front->elem is == to the element to find
	    {
	      deleteFront();//call deleteFront() and exit
	      return;
	    }
	  else//the only node does not have the element we are looking for
	    {
	      return;//exit
	    }
	}
      
      if(front->elem == el)//if the first node contains the element to be deleted 
	{
	  deleteFront();//call deleteFront
	  return;
	}
      
      for(pre = front, del = front->next; del != NULL && del->elem != el; pre = del, del = del->next)
	;  
      if(del == rear)//element was found at the end(rear)
	{
	  //delete del;
	  deleteRear();
	  /*
	  delete rear;
	  rear = pre;//make rear point to the previous node
	  rear->next = NULL;//make it point to NULL
	  count--;
	  */
	  return;
	}
      if(del == NULL)//el was not found in the list
	{
	  return;
	}
      else if(del != NULL)//del != NULL, el was found in the list 
	{
	  count--;
	  pre->next = del->next;//point to the node after delete
	  del->next->prev = pre;//point back to previous
	  delete del;
	}
	
    }
  
}
/*****************************************************
el is the element to delete

This function will delete all nodes with the specific element.
If the list is empty, it will do nothing.
*****************************************************/
void DLL::deleteNodes(el_t el)
{
  while(search(el))//search for the element 
    {
      deleteNode(el);//delete until there are no more nodes with that element 
    }
}
/***************************************************
el is the element to be inserted 

This function will add elements in ascending order in
the linked list.
****************************************************/
void DLL::addInOrderAscend(el_t el)
{
  node* p;
  node* temp = new node;//new node to be inserted
  temp->elem = el;//add el to temp node
  if(count == 0)//if there are no elements, just call addFront()
    {
      addFront(el);
      return;
    }
  else
    {
      if(el <= front->elem)//if the element is less than front->elem, call addFront()
	{
	  addFront(el);
	  return;
	}

      p = front;//start p at front
      while(p->next != NULL && p->next->elem < el)//goes through the nodes
	{
	  p = p->next;//advance p
	}
      if(p->next == NULL)//if p is at the last node, el is the biggest element, call addRear
	{
	  addRear(el);
	  return;
	}
      
      temp->next = p->next;//temp->next is now pointing to the same node as p->next
      p->next = temp;//p->next is now pointing to new node(temp)
      temp->next->prev = temp;//node after temp will point back to temp      
      temp->prev = p;//temp->prev will point back to p
      //temp->next->prev = p;

      count++;
    }
}
/***************************************************
el is the element to be inserted

This function will add elements in descending order in
the linked list.
****************************************************/
void DLL::addInOrderDescend(el_t el)
{
  node* p;
  node* temp = new node;//new node to be inserted
  temp->elem = el;//add el to temp node
  if(isEmpty())//if there are no elements, just call addFront()
    {
      addFront(el);
    }
  else
    {
      if(el >= front->elem)//if the element is greater or equal than front->elem, call addFront()
        {
          addFront(el);
          return;
        }

      p = front;//start p at front
      while(p->next != NULL && p->next->elem > el)//goes through the nodes
        {
          p = p->next;//advance p
        }
      if(p->next == NULL)//if p is at the last node, el is the smallest element, call addRear
        {
          addRear(el);
          return;
        }

      temp->next = p->next;//temp->next is now pointing to the same node as p->next
      p->next = temp;//p->next is now pointing to new node(temp)

      temp->next->prev = temp;//node after temp will point back to temp
      temp->prev = p;//temp->prev will point back to p

      //temp->prev = p;
      // temp->next->prev = p;
      count++;
    }
}

/**************************************************
el is the element we are looking for

This function will return true if the element was 
found in the list. If the list is empty or the element 
was not found, it will return false;
 *************************************************/
bool DLL::search(el_t el)
{
  node* temp = front;//make temp point to front
  if(isEmpty())//list is empty, return false
    {
      return false;
    }
  while(temp != NULL)//go through the list
    {
      if(temp->elem == el)//if the element is in the list, return true
	{
	  return true;
	}
      temp = temp->next;//move to the next node
    }
  return false;//if the element was not found in the list, return false

}
/***************************************************
This function will display all the elements in the 
linked list in reverse order. 
 **************************************************/
void DLL::printAllReverseDLL() const
{
  node* temp = rear;//start at the back of the list
  
  if(isEmpty())//check if the queue is empty
    {
      cout << "[ empty ]" << endl;
    }
  else//not empty
    {
      //node* temp = front;//store front
      while(temp != NULL)//while our temp is not = to NULL, display
        {
          cout << "[" << temp->elem << "]" << " ";//display elem
          temp = temp->prev;//temp points to the next node
        }
    }
}
/******************************************
This fucntion will display all the elemets 
in the list.
 *****************************************/
void DLL::displayAll() const
{
  node* temp = front;//start at front 

  if(isEmpty())//check if the queue is empty
    {
      cout << "[ empty ]" << endl;
    }
  else//not empty
    {
      //node* temp = front;//store front
      while(temp != NULL)//while our temp is not = to NULL, display
	{
	  cout << "[" << temp->elem << "]" << " ";//display elem
	  temp = temp->next;//temp points to the next node
	}
    }
}

