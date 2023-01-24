#include <iostream>
#include <cstdlib>
#include "stack.h"

using namespace std;
//typedef string el_t;
//default constructor setting top to -1
Stack::Stack()
{
  top = -1;
}
/**********************************************
This function will check if the stack is empty.
If top is -1, then its empty and return true.
 *********************************************/
bool Stack::isEmpty() const 
{
  //  return (top < 0);
  if(top < 0)//top is -1, empty
    {
      return true;
    }
  else//not empty
    {
      return false;
    }
  
}
/*********************************************
This function will check if the stack is full.
Top is greater than or equal to its max size.
 *********************************************/
bool Stack::isFull() const
{
  //return (top >= (MAX-top)-2);
  if(top >= MAX-1)//top is greater than or equal to max
    {
      return true;
    }
  else//not greater than or equal to max, not full
    {
      return false;
    }
  
}
/********************************************
This function will be able to push a new element
into the stack, but will check if it's full first.
 *******************************************/
void Stack::push(el_t e)
{
  if(isFull())//check to see if full
    {
      stackError("stack overflow");//stack is full, call error function
    }
  else//stack is not full, push element and pre increment top 
    {
      // top++;
      el[++top] = e;
    }
}
/**********************************************
This function will be able to pop an element from
the stack if the stack is not empty. 
 **********************************************/
el_t Stack::pop()
{
  if(isEmpty())//if the stack is empty
    {
      stackError("stack underflow");//call show error function 
    }
  else//pop the element and post decrement top 
    {
      return el[top--];
    }
}
/**********************************************
This function will be able to show us the top 
element in the stack.
 **********************************************/
el_t Stack::topElem() const
{
  if(isEmpty())//check to see if the stack is empty
    {
      stackError("stack is empty");//stack was empty, call error function 
    }
  else//not empty, return the top element in the stack
    {
      return el[top];
    }
}
/**********************************************
This function will display all the element is the 
stack in the right order.
 *********************************************/
void Stack::displayAll() const
{
  if(isEmpty())//if the stack is empty
    {
      cout << "[empty]" << endl;
    }
  else
    {
      for(int i = top; i >= 0; i--)
        {
          cout << el[i] << endl;
        }

      /*
      for(int i = 0; i <= top; i++)
	{
	  cout << el[i] << " ";
	}
      */
    }
}
/**********************************************
This fucntion will clear the stack of all its elements.
 *********************************************/
void Stack::clearIt()
{
  while(!isEmpty())//while the stack is not empty
    {
      pop();//pop the elements
      //top--;//pop() already has top--
    }
}
/***********************************************
This function shows an error and it ends the program.
 **********************************************/
void Stack::stackError(string msg) const
{ 
  cout << msg << endl; //message
  exit(1);//end program 
}
