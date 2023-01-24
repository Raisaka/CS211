/************************************************************
Jared Falcon
cs 211
3/27/2021

This program will be able to encrypt a message using a vector 
with various different functions. The program will also be able
to decrypt the message. It will read a sentence from a txt file
and push_back every character into a vector. The program will
be able to delete non-digits/letters as well as white spaces.
A function will also be able to make a every character into 
lowercase with exceptions. Another fucntion will also insert 
a space every 5 characters into the vector.
 ***********************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "myVector.h"
#include "/cs/slott/cs211/checkInput.h"

using namespace std;
template <class T>
void file(myVector<T>& v);
template <class T>
void print(const myVector<T>& v);
bool isLetterDigit(char c);
template <class T>
void remove(myVector<T>& v);
char myToLower(char c);
template <class T>
void Lower(myVector<T>& v);
template <class T>
void cipher(myVector<T>& v);
template <class T>
void decipher(myVector<T>& v);
template <class T>
void space(myVector<T>& v);
bool isDigit(char c);

int main()
{
  myVector<char> v;//character vector to store characters
  char c;//nothing
  file(v);
  cout << "----sentence----" << endl;
  print(v);
  cout << endl;

  cout << "---after removing non-letter/digit---" << endl;
  remove(v);
  print(v);
  cout << endl;

  cout << "---after converting to lower case---" << endl;
  Lower(v);
  print(v);
  cout << endl;
  
  cipher(v);
  cout << "---after inserting a space after every 5 characters---" << endl;
  space(v);
  print(v);
  cout << endl;

  cout << "---after being decrypted---" << endl;
  decipher(v);
  print(v);
  cout << endl;


  return 0;
}
/*******************************************
v is the vector 

THis function will read a sentence from a file 
and push every character into our vector.
 *******************************************/
template <class T>
void file(myVector<T>& v)
{
  string filename;//file's name
  string sentence;//stores our sentence

  cout << "Enter the filename: ";
  cin >> filename;

  ifstream fin;//fin to open file
  fin.open(filename.c_str());//c string so we can enter the file name

  if(!fin)//check if file exists
    {
      cout << "FIle machine broke" << endl;
      exit(1);
    }
  else//exists
    {
      getline(fin, sentence);//get the whole sentence
      
      //      cout << sentence << endl;
      for(int i = 0; sentence[i] != '\0'; i++)//go through every character in the sentence
	{
	  v.push_back(sentence[i]);//push every character into the vector
	}
      fin.close();//close file
    }
}
/*********************************************
const v for our vector that wont change

This function will print the vector's content.
 *******************************************/
template <class T>
void print(const myVector<T>& v)
{
  for(int i = 0; i < v.size(); i++)//go through the vector
    cout << v[i];
  cout << endl;
}
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
v is the vector 

This function will help us remove all the 
non-digit or letter charcaters in the vector.
 ********************************************/
template <class T>
void remove(myVector<T>& v)
{
  for(int i = 0; i < v.size(); i++)//go through vector
    {
      if(!isLetterDigit(v[i]))//call isLetterDigit to check character
	{
          v.erase(i);//if its not a letter or digit / delete
	  i=0;//reset to go again
	}
      
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
/***********************************************
v is for the vector

This function will make the uppercase letters into
lowercase and leave everything else.
 **********************************************/
template <class T>
void Lower(myVector<T>& v)
{
  char low;//store returned letter 
  for(int i = 0; i < v.size(); i++)
    {
      low = myToLower(v[i]);//call converted letter
      v[i] = low;//replace it
    }
}
/**********************************************
c is for the digit

This function will return true if the character
is a digit.
 ********************************************/
bool isDigit(char c)
{
  if(c >= '0' && c <= '9')//in range to be a digit 
    {
      return true;
    }
  else//not in range
    {
      return false;
    }

}
/***************************************************
v is for the vector

This function will be able to encrypt a sentence using the 
alphabet and the digits 0-9. It will reset if the the last 
letter or digit is '0' or 'z' so it can start at the 
beginning. It will reject bad inputs for the range 
1-26 will be the range the characters will shift. 
 **************************************************/
template <class T>
void cipher(myVector<T>& v)
{
  int data;//stores our range to shift
  cout << "Enter a secret number to cipher a sentence between 1 and 26: ";
  data = getData(1, 26, "Enter a valid option (1-26): ");
  char newChar;//will store shifted character
  int newC;//stores the added values for character and data
  for(int i = 0; i < v.size(); i++)//goes through the vector
    {
      
      if(isDigit(v[i]))//call is digit to determine if the character is a digit
	{
	  
	  newC = v[i] + data;//store added values into newC

	  
	  if(newC > 57)//if newC is greater than '9'
            {
          
	      while(!(newC < 57))//subtract 10 until its back in range of '0'-'9'
		{
		  newC = newC -10;//subtract and save new int
		}
	      
	      newChar = (char)(newC);//convert newC into char and store in newChar
	      v[i] = newChar;//replace with new digit
	    }
	  else//otherwise just return the newChar
            {
              newChar = (char)newC;//convert 
	      v[i] = newChar;//replace with new digit
	    }
	  
	}
      else if(v[i] >= 97 && v[i] <= 122)//else if the character is not a digit
        {	  
	
	  newC = v[i] + data;//make new integer value 
         
	  if(newC > 122)//if newC is out of range
            { 
	      newC = newC - 26;//newC will be reset to the start which is 'a'
	      newChar = (char)newC;//store new char 
	      v[i] = newChar;//replace new letter 
	    }
          else//its good as is
            {
              newChar = (char)newC;//convert
	      v[i] = newChar;//replace
	    }
	  
        }
     
    }
}
/******************************************************
v is the vector

This fucntion will decrypt the encrypted message.
 *****************************************************/
template <class T>
void decipher(myVector<T>& v)
{
  
  int data;//used to check range
  cout << "Enter a secret number to decipher a sentence between 1 and 26: ";
  data = getData(1, 26, "Enter a valid option (1-26): ");
  char newChar;//stores new character
  int newC;//stores added values of v[i] and data
  
  for(int i = 0; i < v.size(); i++)//goes through the array
    {
      //newChar = v[i];
      // newC = v[i] - data
      
      if(isDigit(v[i]))//check if its a digit
	{
	  newC = v[i] - data;//subtract 55('0')-26(data)
	  if(newC < 48)//if newC is less than our first digit '0' 29 < 48
	    {
	      
	      while(!(newC > 48))//keep adding 10(number of digits) until its in range
		{
		  newC = newC + 10;//29+10 = 39 // 39 +10 = 49 which is  '7' decrypted is '1' 
		}
	      newChar = (char)newC;//convert into char 
	      v[i] = newChar;//replace new char 
	    }
	  else//else just replace
	    {
	      newChar = (char)newC;//convert
	      v[i] = newChar;//replace
	    }
	}
      else if(v[i] >= 97 && v[i] <= 122)//else the character is in range of a letter 
        {
          newC = v[i] - data;//subtract to store new value
          if(newC < 97)//if newC is less than range
            {
              newC = newC + 26;//add 26 to be back in range
	      newChar = (char)newC;//convert
	      v[i] = newChar;
	    }
	  // v[i] = newChar;
	  else//else its just a conversion 
	    {
	      newChar = (char)newC;//convert
	      v[i] = newChar;//replace
	    }
	}
    }
  
}
/*******************************************
v is the vector

This fucntion will insert a space in the 
vector every 5 characters.
 *****************************************/
template <class T>
void space(myVector<T>& v)
{
  int count = 0;//count at 0
  for(int i = 0; i < v.size(); i++)//go though the vector
    {
      count++;//increment count after every loop 
      if(count == 6)//if count is 6 then the index is 5
	{
	  v.insert(i, ' ');//insert a space after every 5 characters 
	  count = 0;//reset count to keep counting 
	  //i = 0;
	}
      //      count = 0;
    }

}
