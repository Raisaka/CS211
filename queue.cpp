#include <iostream>
#include <cstdlib>
#include "queue.h"

using namespace std;

Queue::Queue()
{
  count = 0;//set count to 0
  front = 0;//front el is 0
  rear = -1;//-1 for no el
}
/******************************************
This fucntion will check if the queue is empty.
 *****************************************/
bool Queue::isEmpty() const
{
  if(count == 0)//if count = 0 then its empty
    {
      return true;
    }
  else//not empty
    {
      return false;
    }
}
/*****************************************
This fucntion will check if the queue is full
based on the max size.
******************************************/
bool Queue::isFull() const
{
  if(count >= MAX)//count is equal to max size or greater
    {
      return true;
    }
  else//not full
    {
      return false;
    }
}
/********************************************
el_t is the element type

This fucntion will add an element to the front 
of the queue and increment the rear.
 *******************************************/
void Queue::add(el_t e)//el_t 
{

  if(isFull())//check if its full
    {
      queueError("OVERFLOW");//bad error
    }
  else//not full
    {
     
      
      
      rear = (rear+1) % MAX;//will move rear in circles
      //      el[++rear] = e;//el[++rear] = e;
      el[rear] = e;//test
      //rear++;
      count++;
     
    }
}
/*********************************************
This fucntion will remove and return the element 
type and move front to the next element in line.
 *********************************************/
el_t Queue::remove()
{
  if(isEmpty())//check if empty
    {
      queueError("UNDERFLOW");//bad error
    }
  else//not empty
    {
      
      //cout << "Removing element: " << el[front] << endl;
      // count--;
      el_t temp;//store first element
      temp = el[front];//store the el
      front = (front +1) % MAX;//move front 
      count--;
      //      cout << el[front];
      //      front--;
      return temp;//return front element 
      // count--;
      
    }
}
/*******************************************
This function will return the element type 
to show whats in front of the queue.
******************************************/
el_t Queue::getFront() const
{
  if(isEmpty())//check if empty
    {
      queueError("Nothing is in queue");//bad error
    }
  else//not em,pty
    {
      return el[front];//return front element
    }
}
/********************************************
This function will make the first element in the queue
go to the back using remove() and add()
 ******************************************/
void Queue::goToBack()
{
  //char ch;
  if(isEmpty())//check if the queue is empty
    {
      queueError("Nothing is in queue");//bad error
    }
  else if(count > 1)//count is more than 1
    {
      // front = front -1;
      //      add(el[front]);//

      remove();//remove element
      // cout << ch;
      add(el[front-1]);//add removed element to the back 
    }
  //  add(remove());

}
/************************************************
os will return the output statement
n is the struct

This function will allow us to overload << to output a 
struct object
 ************************************************/
ostream& operator<<(ostream& os, const expr& n)
{
  os << n.oprd1 << " " << n.oprt << " " << n.oprd2 << endl;
  return os;

}
/***************************************************
This fucntion will be able to display the queue.
 **************************************************/
void Queue::displayAll() const
{
  //  int i;
  if(!isEmpty())
    {
      //cout << front << endl;
      // cout << rear << endl;
      int i;
      if(front <= rear)//front is less than rear, just diplay items linearly 
	{
	  for(i = front; i <= rear; i++)//goes through queue in order
	    {
	      cout << "[" << el[i] << "]" << " ";
	    }
	}
      else
	{
	  i = front;//makes it easier 
	  while(i < MAX)//this will print elements on the right, if front > rear
	    {
	      cout << "[" << el[i] << "]" << " ";
	      i++;
	    }
	  i = 0;//reset i to 0 so it reads the rest of the elements 
	  while(i <= rear)//i starts at 0 and moves through the Q until it hits the rear
	    {
	      cout << "[" << el[i] << "]" << " ";
	      i++;
	    }
	}
    }
  else//nothing in queue
    {
      cout << "[empty]" << endl;
    }
}
/**********************************
This function returns the size of the queue
 *********************************/
int Queue::getSize() const 
{
  return count;
}	    
/****************************************
This function display a bad error and exits program/
 ***************************************/
void Queue::queueError(string msg) const
{
  cout << msg << endl;
  exit(1);//quit program
}
