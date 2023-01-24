/***************************************************************************
CS211
Template prepared by Kazumi Slott 
Your name: Jared Falcon

Program description:
This program will be able to convert decimal numbers( base 10) into different number 
systems (binary, octal, hexadecimal) bases 2, 8, 16. The program will able to
convert using recursion and a stack.
***************************************************************************/
#include <iostream>
#include "stack.h"
using namespace std;
#include "/cs/slott/cs211/checkInput.h"

int getBase();
char convertToChar(int n);
void convertRec(int n, int b);
void convertStack(int n, int b);

int main()
{
  int dec;
  int base;

  cout << "Enter a number in base 10: ";
 
  //get a decimal number by calling getData in checkInput.h. Accept a numer 
  //between 1 and 999999.
  dec = getData(1, 999999, "Enter a number between 1 and 999999. Enter again: ");
  base = getBase();
  //get a base (2, 8 or 16) by calling getBase
  // cout << convertToChar(10) << endl;

  //  convertRec(dec, base);

  cout << "----------- Using recursion ---------------" << endl;
  //call convertRec to show the number in the base number system of the user’s choice
  
  convertRec(dec, base);

  cout << endl;

  cout << "----------- Using a stack ---------------" << endl;
  //Call convertStack to show the number in the base number system of the user’s choice
  convertStack(dec, base);

  cout << endl;
  return 0;
}

/****************************************************************************
This function asks for a number system to which a decimal number is converted, either 2, 8 or 16.
It rejects bad inputs other than 2, 8 or 16.
It returns either 2, 8 or 16
****************************************************************************/
int getBase()
{
  int b;
  cout << "Enter a base to convert the base 10 number to: ";
  cin >> b;
  while(b != 2 && b != 8 && b != 16)//while these are not enetered 
    {
      cout << b << " is invalid. Enter 2, 8, or 16 only: ";//keep displaying and enter response
      cin >> b;
    }
  return b;//return base
}

/****************************************************************************
This function receives an integer between 0 and 15 and returns the character.
If n = 0 .. 9, it returns '0' .. '9'
If n = 10 .. 15, returns 'A' .. 'F'

n is an integer between 0 and 15
****************************************************************************/
char convertToChar(int n)
{
  char ch;
  if(n >= 0 && n < 10)//convert to char if 0-9
    {
      ch = (char)(n+48);//conversion to char 
      return ch;//return it
    }
  else if(n >= 10 && n <= 15)//these will be the letters 
    {
      ch = (char)(n+55);//convert
      return ch;//return letter 
    }
}

/***************************************************************************
This is a <<recursive>> function to convert a decimal number to a different number system and print it.

n is a decimal number
b is a number system to which n is converted, either 2, 8 or 16
***************************************************************************/
void convertRec(int n, int b)
{
  
  if(n == 0)//if n is 0 we are done 
    {
      return; //go back and display
    }
  else//otherwise divide n
    {
      convertRec(n / b, b);//keep dividing n until its 0
      cout << convertToChar(n % b);//output the remainder
    }
  
}

/**************************************************************************
This function uses a stack to convert a decimal number to a different number system and prints it.
This is not a recursive function.

n is a decimal number
b is a number system to which n is converted, either 2, 8 or 16
**************************************************************************/
void convertStack(int n, int b)
{
  Stack myStack;//make a stack
  int con;//stores the remaninder
  char ch;//stores returned converted char 
  while(n != 0)//while n is not 0
    {
      
      con =  n % b;//store remainder
      
      ch = convertToChar(con);//pass remainder to function and store returned char
      if(!myStack.isFull())//check stack
	{
	  //cout << "here" << endl;

	  myStack.push(ch);//push the converted char
	  //	  myStack.topElem();
	}
      else//stack is full
	{
	  cout << "Stack is full" << endl;
	}
      n = n / b;//integer division to decrease n

    }
  while(!myStack.isEmpty())//displays the characters 
    {
      cout << myStack.pop();
    }
  // myStack.displayAll();
   
  

}


