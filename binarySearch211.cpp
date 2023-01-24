/***************************************************************************
CS211
Template created by Kazumi Slott
Implement binary search that works on an ascending and descending ordered list.
Your program will abort if the function doesn't return the correct value. 

Your name:Jared Falcon
*****************************************************************************/
#include <iostream>
#include <assert.h>
using namespace std;

void reverseArray(int a[], int s);
int binarySearchAscend(const int a[], int s, int key);
int binarySearchDescend(const int a[], int s, int key);

int main()
{
  const int SIZE = 10;
  int ar[SIZE] = {1, 10, 20, 30, 40, 50, 60, 70, 80, 90};
  
  //test binarySearchAscend()
  for(int i = 0; i < SIZE; i++)
    assert(binarySearchAscend(ar, SIZE, ar[i]) == i);  //assert() terminates the program if the condition is false.
  
  assert(binarySearchAscend(ar, SIZE, 100) == -1); 


  //call reverseArray() to reverse the elements in ar 
  reverseArray(ar, SIZE);
  for(int i = 0; i < SIZE; i++)
    {
      cout << ar[i] << " ";
    }
  cout << endl;
  
  //test binarySearchDescend() - mimic how you tested binarySearchAscend()
  for(int i = 0; i < SIZE; i++)
    assert(binarySearchDescend(ar, SIZE, ar[i]) == i);
 
  return 0;
}



/****************************************************************************
This functioon reverse the contents of the array. Don't make a second array.
e.g. If ar is [5, 1, 3, 8, 2], this function changes the array to [2, 8, 3, 1, 5]
a is an integer array of any size.
s is the size of the array.
****************************************************************************/
void reverseArray(int ar[], int s)
{
  int temp;//helps us switch elements 
  for(int i = 0; i < s; i++, s--)//loop for the array, decrease size
    {
      //will switch elements first and last 
      temp = ar[i];
      ar[i] = ar[s-1];
      ar[s-1] = temp;
    }
 //???????
}


/****************************************************************************
This function returns the index where key is found or -1 if key is not found.
a is an integer array of any size sorted in ascending order.
s is the size of the array.
key is the number being searched for.
****************************************************************************/
int binarySearchAscend(const int a[], int s, int key)
{
  int l = 0; //left boudary starts at first index
  int r = s-1; //right boundary starts at last index
  int m; //middle point between left and right.

  //When l and r cross over, search ends. --> key was not found. 
  while(l <= r)
    {
      //calculate the middle point between l and r
      m = (l + r)/ 2;

      if(a[m] == key) //key was found
	return m;
      else if(key < a[m])//key is to the left of m
	r = m-1;//remap r 
      else if(a[m] < key)//key is to the right of m
	l = m + 1;//remap l
    }
  
  return -1; //key wasn't found
}

/****************************************************************************                                                             
This function returns the index where key is found or -1 if key is not found.                                                             
a is an integer array of any size sorted in descending order.                                                                                                     
s is the size of the array.                                                                                                               
key is the number being searched for.                                                                                                     
****************************************************************************/
int binarySearchDescend(const int a[], int s, int key)
{
  int l = 0; //left boudary starts at first index                                                                                      
  int r = s-1; //right boundary starts at last index                                                                                     
  int m; //middle point between left and right.                                                                                           

  //When l and r cross over, search ends. --> key was not found.                                                                          
  while(l <= r)
    {
      //calculate the middle point between l and r 
      m = (l + r) / 2;

      if(a[m] == key) //key was found           
        return m;
      else if(a[m] > key)//key is found to the right of m 
        l = m + 1;//remap left
      else if(a[m] < key)//key is found to the left of m
        r = m - 1;//remap right
    }

  return -1; //key wasn't found                                                                                                      
}
