/******************************************************************
Jared Falcon
cs 211
2/25/21

This program will evaluate a postfix expression using the Stack class.
It will convert characters that look like integers into actual integers.
It will perform operations +, -, *, /, using two popped integers from the 
stack. Certain errors for different error scenarios will stop the loop
from running. 
 ****************************************************************/
#include <iostream>
#include "stack.h"

using namespace std;

bool isOperator(char ch);
bool isOperand(char ch);
int charToInt(char ch);
int doMath(int opr1, char opt, int opr2);

int main()
{
  //  const int SIZE = 5;
  Stack myStack;//make a stack
  string exp;//our expression an array of characters 
  int num;//will store our converted char into int
  int ans;//will store the right hand side operand
  int ans2;//will store the left hadn side operand 
  int ans3;//will store the product of ans and ans2, ans3 will be pushed into the stack
  bool full = false;//will help us enter and exit loops 

  cout << "Enter expression: " << endl;//enter expression
  cin >> exp;
  
  //the for loop has two condtions on how to exit, it reads the whole string and full = true
  for(int i = 0; !full && i < exp.length(); i++)//for loop to acess every single character in the string 
    {
      // cout << exp[i] << " ";//shows characters on the left of the screen
      full = false;//full = false
      // num = (int)exp[i] - '0';//convert char into integer, might need to put in the somewhere else
      // cout << num << endl;
      if(isOperator(exp[i]))//if the character is an operator 
	{
	  //cout <<  "This is the second number" << myStack.topElem();//was a test
	  //cout << endl;
	  ans2 = myStack.topElem();//store top integer into ans2, before we pop it
	  if(!myStack.isEmpty())//check to see if stack is not empty before we pop
	    {
	      myStack.pop();//pop top number
	    }
	  else//wont pop or trigger exit(1)
	    {
	      cout << "Cant pop" << endl;
	    }
	  //cout << "This is the first number" << myStack.topElem();
	  //ans = myStack.topElem();
	  // myStack.pop();
	  if(!myStack.isEmpty())//checks to see if there are more integers in the stack to operate
	    {
	      //cout << "This is the first number" << myStack.topElem();
	      ans = myStack.topElem();//stores left hand operand

	      myStack.pop();//pop it to operate
	      ans3 = doMath(ans, exp[i], ans2);//call doMath and operate
	      myStack.push(ans3);//push new integer into stack

	    }
	  else//if stack is empty, there are not enough operands
	    {
	      cout << endl;
	      cout << "Error: Not enough operands" << endl;
	      full = true;//exit condition met
	      cout << endl;
	    }

	  //	  cout << endl;
	  
	  //cout << "Here!" << endl;
	}
      else if(isOperand(exp[i]))
	{
	  // num = (int)exp[i] - '0';
	  num = charToInt(exp[i]);//calls function to convert char into integer
	  //cout << "Its converted! " << num << endl;
	  
	  //	  myStack.push(num);//testing
	   
	  if(myStack.isFull())//check if the stack is full, if expression is too long
	    {
	      cout << endl;
	      cout << "Error: Expression is too long!" << endl;
	      full = true;//exit trigger
	      cout << endl;
	    }
	  else//not full
	    {
	      //cout << "Stack is not full" << endl;
	      myStack.push(num);//push the integer
	      full = false;//dont exit loop
	  
	    }
	  
	    // myStack.displayAll();
	}
      else//if the character is not and operator or integer
	{
	  cout << endl;
	  cout <<"Error: Invalid item was found " << exp[i] << endl;
	  full = true;//exit loop
	  cout << endl;
	}
      //myStack.displayAll();
    }
  //  cout << endl;
  
  while(full == false)//while loop used if we dont have any errors yet, we can enter the loop
    {
      int answer;//will store our answer 
      answer = myStack.topElem();//store top element into answer
      if(!myStack.isEmpty())//check if the stack is not empty before we pop
	{
	  myStack.pop();//pop
	}
      else//stack is empty
	{
	  cout << "Cant pop" << endl;
	}
      if(!myStack.isEmpty())//if the stack is not empty at this point, there are too many operands
	{
	  cout << endl;
	  cout << "Error: Too many operands" << endl;
	  full = true;//exit the while loop
	  cout << endl;
	}
      else //we already popped our answer and stored it, now just display it and the stack is empty
	{
	  cout << "= " << answer << endl;
	  cout << endl;
	  full = true;//exit loop
	}
    }

  //    cout << "This is the current stack" << endl;
  //  myStack.displayAll();




  return 0;
}
/**********************************************************
ch will be our operator will return true, if not false

This function will return true if the character ch is 
an operator and false if not.
***********************************************************/
bool isOperator(char ch)
{
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/')//if ch is these operators return true
    {
      return true;
    }
  else//not these operators return false
    {
      return false;
    }
}
/*********************************************************
ch wil be our operand

This function will return true if our character is range of
'0' and '9' ascii value wise.
 ********************************************************/
bool isOperand(char ch)
{
  if(ch >= '0' && ch <= '9')//if ch is in the range of these characters values, return true
    return true;
  else//not, return false
    return false;

}
/***********************************************************
ch will be our character that will be an integer

This function will return the converted character into an integer.
Only if its an integer or characters '0' to '9'
 **********************************************************/
int charToInt(char ch)
{
  int num;//stores converted character
  num = (int)ch - '0';//convert the character into and integer
  return num;//return the integer
}
/***********************************************************
opr1 is the left operand
opr2 is the right operand
opt is the operator 

This function will return the product of the operands with the
respective operator involved
 **********************************************************/
int doMath(int opr1, char opt, int opr2)
{
  switch(opt)//switch for each different operator and return the product
    {
    case '+':
      return opr1 + opr2;
      break;
    case '-':
      return opr1 - opr2;
      break;
    case '*':
      return opr1 * opr2;
      break;
    case '/':
      return opr1 / opr2;
      break;
    default: cout << "Invalid " << endl;

    }
}
