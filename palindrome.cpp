/****************************************************************
Jared Falcon
CS 211
4/11/2021

This program will use a linked list in order to determine if the 
given sentence/word is a palindrome. It will clear any spaces in the
sentence as well as convert any uppercase letter to lowercase. 
*****************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "LL.h"
#include "myStrCharFunc.h"

using namespace std;
void createLL(LL& list, string p);
bool palindrome(LL& list);
void file(LL& list);

int main()
{
  LL L;//linked list 
  bool yay;//stores true or false for palindrome
  string pal;//our sentence for palidrome
  cout << "Enter a palindrome: ";
  getline(cin, pal);//get the whole sentence 
  
  createLL(L, pal);//construct linked list 
  yay = palindrome(L);//store result
  if(yay)//if true, its palindrome
    {
      cout <<  "\"" << pal  << "\"" <<  " is a palindrome" << endl;
    }
  else//else not palindrome 
    {
      cout <<  "\"" << pal  << "\"" << " is NOT a palindrome" << endl;
    }
  cout << endl;
  while(!L.isEmpty())//clear the linked list 
    {
      L.deleteFront();
    }


  file(L);//read contents from file 
 
  return 0;
}
/*************************************************
list is our linked list
This function will read words and sentences from a
file and it will determine if they are a palidrome.
 *************************************************/
void file(LL& list)
{
  string sentence;//stores our sentence from file 
  //bool aya;//stores true or false for palindrome 
  ifstream fin;//we can open file
  fin.open("palindrome.dat");//open the file 

  if(!fin)//if file doesnt open
    {
      cout << "File machine broke" << endl;
      exit(1);//exit program
    }
  else//otherwise open file
    {
  
      getline(fin, sentence);//get the first sentence from file
      while(fin)//while in the file reading 
	{
	  createLL(list, sentence);//call create for list and sentence

	  if(palindrome(list))//check if the sentence is palindrome or not
	    {
	      cout <<  "\"" << sentence  << "\"" <<  " is a palindrome" << endl;
	    }
	  else
	    {
	      cout <<  "\"" << sentence  << "\"" <<  " is NOT a palindrome" << endl;
	    }
	  
	  while(!list.isEmpty())//clear the linked list of leftovers 
	    {
	      list.deleteFront();//call delete
	    }
	  
	  getline(fin, sentence);//read the next sentence
	  //cout << sentence << endl;
	}
      fin.close();//close the file 
    }
  


}
/************************************************
list is our linked list 
p is the string we want to pass into our linked list 

This function will create a linked list with the
string that we are passing.
*************************************************/
void createLL(LL& list, string p)
{
  for(int i = 0; i < p.size(); i++)//go through every character in the sentence 
    {
      
      if(isLetterDigit(p[i]))//only pass letters into the list
	{
	  char low = (char)myToLower(p[i]);//convert to lowercase
	  list.addFront(low);//add to the list 
	  
	}
    }
} 
/***********************************************
list is our LL we are using 

This function will determine if the sentence in the 
linked list is a palindrome or not. It will check
the front and rear elements of the list and compare
them to each other.
 **********************************************/
bool palindrome(LL& list)
{
  char front;//stores  front popped char
  char rear;//stores rear popped char 
  //  bool ahaha = true;

  front = list.deleteFront();//store front
  rear = list.deleteRear();//store rear

  // cout << front << endl;
  // cout << rear << endl;
    
  if(front != rear)//check to see if they are the same char 
    {
      return false;//if they are not the same its not palindrome, return false
    }
  while(!list.isEmpty())//otherwise enter the while loop if the list is not empty
    {
      if(!list.isEmpty())//check if the list is not empty
	front = list.deleteFront();//pop the front char
      if(list.isEmpty())//if the list is empty, front popped the last char(middle char) making it a palindrome
	{
	  return true;//return true
	}
      else//otherwise keep popping, pop rear 
	{
	  rear = list.deleteRear();//store rear
	}
      if(front != rear)//check if front and rear are not the same
	{
	  //cout << front << endl;
	  // cout << rear << endl;
	  return false;//return false
	}
      
	  
    }
  return true;

}
