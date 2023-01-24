/************************************************************
Jared Falcon
cs 211
4/21/2021

This program will be able to read a file with an essay in it,
and insert every word/letter into a linked list. The linked list will 
have only lowercase words/letters and no special characters/punctuation.
It will also be able to remove the bad words in the essay as well
as deleting duplicate words. The linked list will also be in 
alphabetical order. The program will be able to output all the
words into respective files in alphabetical order. It will
create 19 different files with all the words found in the essay.  
 ***********************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "utility.h"
#include "LL.h"

using namespace std;
void buildLL(LL& list);
void removeBadWords(LL& list);
void outputToFile(LL& list);

int main()
{
  LL L;//create linked list
  
  buildLL(L);
  L.displayAll();
  cout << endl << endl;
  removeBadWords(L);
  L.displayAll();
  outputToFile(L);  
  return 0;
}
/************************************************************
list is our linked list

This function will be able to output all the words in the 
linked list into appropriate files corresponding to their first
letter. It will create different files.
 ***********************************************************/
void outputToFile(LL& list)
{
  ofstream fout;
  string s;//will store our word in the linked list
  
  if(list.isEmpty())//check if empty
    {
      cout << "List is empty!" << endl;
    }
  else//get the first word
    {
      s = list.deleteFront();//store the deleted word in s
    }
  while(!list.isEmpty())//run the loop until the list is empty
    {
      string filename = "./dictionary/?.txt"; // .means the current directory.
      filename[13] = toMyUpper(s[0]);//the first letter in s will replace the ? in the txt file
      
      fout.open(filename.c_str());//open the correct file for the word
      
      while(fout.is_open())//file will stay open
	{
	  if(toMyUpper(s[0]) == filename[13])//if the letters match, output s into the file
	    {
	      fout << s << endl;//output
	    }
	  if(!list.isEmpty())//check if the list is empty
	    {
	      s = list.deleteFront();//get the next word from the list
	     
	      if(!(toMyUpper(s[0]) == filename[13]))//if the letters dont match, then close the file A != B
		{
		  fout.close();//close file
		}
	    }
	  else//list is empty, close the file
	    {
	      fout.close();
	    }  
	}
      // fout.close();
    }
}
/***********************************************************
list is our linked list

This fucntion will be able to read a file and remove the bad
words found in the bad.txt from our linked list.
 **********************************************************/
void removeBadWords(LL& list)
{
  ifstream fin;

  fin.open("bad.txt");//open file
  
  if(!fin)//file is not open
    {
      cout << "File machine broke" << endl;
    }
  else//start reading file
    {
      string bad;//stores bad word
      
      fin >> bad;//read first bad word
      while(fin)//reading from file
	{
	  while(list.search(bad) == true)//search for the bad words in the list
	    {
	      list.deleteNode(bad);//if true, delete it
	    }
	  fin >> bad;//read next bad word
	}
      fin.close();
    }
}
/***********************************************************
list is our linked list

This function will create a linked list. It will read a file
(essay.txt) and put every word/letter in our linked list.
While doing so, the words will be turned into lowercase and
punctuation/special characters will be removed. Lastly it will
add the word in ascending order with no duplicates in our list.
 **********************************************************/
void buildLL(LL& list)
{
  ifstream fin;

  fin.open("essay.txt");//open file

  if(!fin)//file cannot be opened
    {
      cout << "File machine broke" << endl;
    }
  else//open file
    {
      string sen;//stores word
      
      fin>>sen;//read the first word
      while(fin)//keep reading the file
	{
	  isWord(sen);//will make sure the word doesnt have any special charcaters or punctuation 
	  LowerALL(sen);//will nake the word lowercase
	  if(list.search(sen)== false)//will search if the word is already in the list, no duplicates 
	    {
	      list.addInOrderAscend(sen);//add word in ascending order
	    }
	  fin >> sen;//read the next word
	}
      fin.close();
    }	 
}
