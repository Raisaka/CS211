#ifndef MYSTRCHARFUNC_H
#define MYSTRCHARFUNC_H

#include <iostream>

using namespace std;

/********************************************
c is the character we are checking

This fucntion will return true if the charater
is a letter or a digit.
*******************************************/
bool isLetterDigit(char c)
{
  if(c >= 48 && c <= 57)//checking for digits
    {
      return true;
    }
  else if(c >= 65 && c <= 90)//checking for upper case
    {
      return true;
    }
  else if(c >= 97 && c <= 122)//checking for lowecase
    {
      return true;
    }
  else//not a letter or digit
    {
      return false;
    }
}
/*********************************************
c is for the character

This function will return the lowercase letter of
the character if its not already lowercase or a digit.
*********************************************/
char myToLower(char c)
{
  if(c >= 48 && c <= 57)//return lowercase
    {
      return c;
    }
  else if(c >= 65 && c <= 90)//uppercase
    {
      return (char)(c+32);//convert into lowercase
    }
  else if(c >= 97 && c <= 122)//digit
    {
      return c;//return digit
    }
  else//anything else return
    {
      return c;
    }
}
#endif
