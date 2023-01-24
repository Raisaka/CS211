#ifndef ARRAY_H
#define ARRAY_H
/*****************************************************
Template prepared by Kazumi Slott
CS211
lab on template functions
This header file provides useful operations on an array
of any data type.

Your name: Jared Falcon
*****************************************************/

#include <iostream>
using namespace std;

/********************************************
This function fills the array with data entered from the keyboard.

ar is an array of any data type
n is the number of items entered into ar
********************************************/
template<class T> 
void fill(T ar[], int n)
{
  for(int i = 0; i < n; i++)
    {
      cout << "Enter an item: ";
      cin >> ar[i];
    }

}

/********************************************
This function prints the array.

ar is an array of any data type
n is the number of items in ar
********************************************/
template<class T>
void print(const T ar[], int n)
{
  for(int i = 0; i < n; i++)
    {
      cout << ar[i] << " ";
    }
}

/*******************************************
This function returns the index of the highest value.

ar is an array of any data type.
n is the number of items in ar
*******************************************/
template<class T>
int getHighest(const T ar[], int n)
{
  int high = 0;
  for(int i = 1; i < n; i++)
    {
      if(ar[i] > ar[high])
	{
	  high = i;
	}
    }
  return high;
}

/*******************************************
This function returns the index of the lowest value.

ar is an array of any data type.
n is the number of items in array
****************************************/
template<class T>
int getLowest(const T ar[], int n)
{
  int low = 0;
  for(int i = 1; i < n; i++)
    {
      if(ar[i] < ar[low])
        {
          low = i;
        }
    }
  return low;
}
/********************************************
This function returns the average.

ar is an array of any data type.
n is the number of items in ar
********************************************/
template<class T>
double getAvg(const T ar[], int n)
{
  double average = 0.0;
  for(int i = 0; i < n; i++)
    {
      average = average + ar[i];
    }
  return average/(double)n;
}



/*******************************************
This function stores unique items into an array
and returns the number of the unique items.
  e.g.  If ar contains  9 3 5 3 9 1 9
        uniqAr gets 9 3 5 1
        The function returns 4  
       
ar is the original array of any data type
uniqAr is the array that will have only unique items
n is the number of items in ar and uniqAr
*******************************************/
template<class T>
int unique(T ar[], T uniqAr[], int n)
{
  
  int count = 0;
  for (int i=0; i<n; i++)//goes through the array 
    { 
      
      int j; 
      for (j=0; j<i; j++)//compares values 
	{
	  if (ar[i] == ar[j]) //if same value
	    {
	      break; //break out
	    }
	}
      if (i == j) //if same index
	{
	  uniqAr[count] = ar[i];//store item in new array
	  count++;
	  
	}
    } 
  
  return count;
//uniqAr in the caller will be filled with only unique numbers

}

/***********************************************
This function sorts the items in ascending order: smallest to largest

array is an array of any data type
N is the number of items in the array
**********************************************/                                                

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The following function sorts an integer array in ascending order 
//using the selection sort algorithm.
//You need to change this code so it works with an array of any data type.
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template <class T>
void sort(T array[], int N)
{
  int lrgIndx; //the index of the largest value                                                                                               
  T temp; //temporary variable that holds the largest value                                                                                  

  //last is the last index in unsorted portion                                                                                                 
  for(int last = N-1; last >= 1; last--)
    {
      lrgIndx = 0; //assume the first item is the largest                                                                                      
      //find the largest in unsorted portion ([0..last])                                                                                       
      for(int i = 1; i <= last; i++)
        {
          if(array[i] > array[lrgIndx]) //The current item is larger                                                                           
            lrgIndx = i;
        }

      //swap the largest with the last item in the unsorted portion                                                                            
      temp = array[lrgIndx];
      array[lrgIndx] = array[last];
      array[last] = temp;
    }
}
/********************************************************************
template function to be used with any data type

T array[] for any type of array

This function will sort the array using bubble sort. The idea is that the 
items in the array will bubble around until they are sorted. In this case
the array wil be sorted in descending order. The largest item in the front,
and the smallest in the back of the array. 
 *******************************************************************/
template<class T>
void bubbleSort(T array[], int N)
{
  bool done = false;//set our flag to false
  T temp;//stores temp large value

  while(!done)//while loop with the condition to stop if the flag is true
    {
      done = true;//will change to true if there is no more sorting to do 
      for(int i = 0; i < N-1; i++)//loop to go through the array and decrease in size when a value is saved
	{
	  if(array[i] < array[i +1])//if the next value is larger
	    {
	      //swap the current value with the next value 
	      temp = array[i];
	      array[i] = array[i +1];
	      array[i +1] = temp;
	      done = false;//flag stays down until there is no more sorting to do
	    }
	}
      N--;
      //decrease the size of the array to store the already saved values
    }

}


template <class T1, class T2>
int find(const T1 ar[], int size, const T2& key)
{
  //  cout << "Enter key: ";
  // cin >> key;
  for(int i = 0; i < size; i++)
    {
      if(ar[i] == key)//if key is equal to an item in the array
	{
	  return i;//return the index
	}
    }
  return -1;//if not found return -1
}


template<class T1, class T2>
bool remove(T1 ar[], int size, const T2& out)
{
  int found;
  found = find(ar, size, out);
  if(found == -1)//not found
    {
      return false;
    }
  else
    {
      
      for(int i = found; i < size-1; i++)//make size smaller
	{
	  ar[i] = ar[i+1];
	  
	}
      return true;
    }

}

/*******************************************
This function prints the array.out is either ostream (cout) or fstream 
(fout)
ar is an array of anydata type
n is the number of items in ar
********************************************/
template<class T, class O>
void printOUT(O& out, const T ar[], int n)
{
for(int i= 0; i < n; i++)
  out << ar[i] << " ";
}
#endif
