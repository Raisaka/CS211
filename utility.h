#ifndef UTILITY_H
#define UTILITY_H

using namespace std;
/***************************************************
c is the char we are returning

This fucntion will be able to turn an uppercase letter
into lowercase.
 ***************************************************/
char myToLower(char c)
{
  if(c >= 'A' && c <= 'Z')//the range of uppercase
    {
      c = c + 32;//make into lower
      return c;//return new lower
    }
  return c;//was already lower
}
/***************************************************
c is the char we are returning

This fucntion will be able to turn an lowercase letter
into uppercase.
***************************************************/
char toMyUpper(char c)
{
  if(c >= 'a' && c <= 'z')//range of the lowercase
    {
      c = c - 32;//make into upper
      return c;//return upper
    }
  return c;//was already upper, return it
}
/***************************************************
c is the character we are checking 

This function will be able to determine if the given
character is a letter or not. Will return true if its
a letter and false if not.
****************************************************/
bool isLetter (char c) 
{
  if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))//our range to check if its a letter upper or lower
    return true;
  else//not a lower or uppercase letter 
    return false;
}
/******************************************************
s is the string we are passing

This function will check if the word we are passing is
a word, if not it will delete any special character.
 *****************************************************/
void isWord(string& s)
{
  for(int i = 0; i < s.size(); i++)//run loop for the size of the word
    { 
      if(!isLetter(s[i]))//check if each character is letter
	{
	  s.erase(i);//if its not, delete the character
	  i=0;//reset it
	}
    }
}
/*****************************************************
s is the string we are passing

This fucntion will make every letter in a sentence lowercase.
 ****************************************************/
void LowerALL(string& s) 
{
  for(int i=0; i<s.size(); i++)//run loop for the size of the word
    {  
      s[i] = myToLower(s[i]);//call myToLower() and replace letter with lowercase letter
    }
}
#endif
