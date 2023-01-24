/****************************************************
Jared Falcon
Template written by Kazumi Slott
CS211
2/7/2021
selection sort lab

This program has 4 different selection sort functions.
2 functions will move the least or greatest item to 
the back of the array. 
The 2 other functions will move the least or greatest
item to the front of the array. 
*****************************************************/
#include <iostream>
#include <cstdlib>
#include "array.h"
using namespace std;
//??????? include your array.h
void test(int code);
void selectionSort1(int array[], int N);
void selectionSort2(int array[], int N);
void selectionSort3(int array[], int N);
void selectionSort4(int array[], int N);

int main()
{
  srand(time(0));//generates random numbers

  cout << "------ testing selectionSort1: Ascending moving largest to end  ------" << endl;
  test(1);

  cout << "\n------ testing selectionSort2: Descending moving smallest to end  ------" << endl;
  test(2);
  //??????

  cout << "\n------ testing selectionSort3: Ascending moving smallest to beginning  ------" << endl;
  test(3);
  //??????

  cout << "\n------ testing selectionSort4: Descending moving largest to beginning  ------" << endl;
  test(4);
  cout << endl;
  //??????

  return 0;
}

//This function fills the array with random numbers between 1 and 100
void fill(int ar[], int N)
{
  int num;//stores the random number 
  for(int i = 0; i < N; i++)//loop to go through array
    {
      num = rand()%100+1;//makes random number and store it in num 
      ar[i] = num;//stores random number in the array
    }
}



//code = 1 for selectionSort1
//       2 for selectionSort2
//       3 for selectionSort3
//       4 for selectionSort4
//This funtion will fill call the function fill to fill the array with random numbers.
//The print function will print the array before it is sorted.
//Using a switch statement and a code for each case of sorting will be called.
void test(int code)
{
  //make a constant SIZE set to 10
  const int SIZE = 10;
  //declare an integer array using SIZE  
  int Array[SIZE];
  //fill the array by calling fill()
  fill(Array, SIZE);
  //print the array by calling print() in array.h
  print(Array, SIZE);
  //create a switch statement here to call a different sort function depending on the code.
  // int code;
  cout << endl;
  // cout << "Enter a code: ";
  // cin >> code;
  switch(code)//4 different cases for sorting the array in different ways 
    {
    case 1: selectionSort1(Array, SIZE);
      break;
    case 2: selectionSort2(Array, SIZE);
      break;
    case 3: selectionSort3(Array, SIZE);
      break;
    case 4: selectionSort4(Array, SIZE);
      break;
    default: cout << "Invalid Choice" << endl;
    }
  print(Array, SIZE);
  //print the array - hopefully the numbers are sorted correctly
  
}



//this function sorts the numbers in ascending order by moving the largest to the end: smallest to largest
void selectionSort1(int array[], int N) 
{
  int lrgIndx; //the index of the largest value
  int temp; //temporary variable that holds the largest value

  //last is the last index in unsorted part
  for(int last = N-1; last >= 1; last--) 
    {
      lrgIndx = 0; //assume the first item is the largest
      //find the largest in unsorted part ([0..last])
      for(int i = 1; i <= last; i++) 
	{
	  if(array[i] > array[lrgIndx]) //The current item is larger 
	    lrgIndx = i;//stores index of higher number in lrgIndx
	}

      //swap the largest with the last item in the unsorted part
      temp = array[lrgIndx]; 
      array[lrgIndx] = array[last]; 
      array[last] = temp;
    } 
}



//Change this function so it sorts the numbers in descending order by moving the smallest to the end: largest to smallest                                                                    
//You can change the variable names to suit their purposes. 
//The structure of this code shouldn't change.
void selectionSort2(int array[], int N)
{
  int SmallIndx; //the index of the smallest value                                            
  int temp; //holds temporary variable with smallest value?????
  
  //last is the last index in unsorted part                                        
  for(int last = N-1; last >= 1; last--)
    {
      SmallIndx = 0; //the first item is the smallest                                                            
      
      //find the smallest value in the unsorted area                             
      for(int i = 1; i <= last; i++)
        {
          if(array[i] < array[SmallIndx]) //currenr index is smaller   //switch the > to <                                                                                                                          
            SmallIndx = i;//keep the smaller value in SmallIndx
        }
      
      //swap the smallest value to the end of the array                
      temp = array[SmallIndx];
      array[SmallIndx] = array[last];
      array[last] = temp;
    }
}




//Change this function so it sorts the numbers in ascending order by moving the smallest to the beginning: smallest to largest                                                                
//You can change the variable names to suit their purposes.                                                                                                                                   
//The structure of this code shouldn't change.
void selectionSort3(int array[], int N)
{
  int SmallIndx; //index of the smaller value
  int temp; //hold the temporary smallest value
  
  for(int first = 0; first < N-1; first++)//the loop will start at the beginning of the array  
    {
      
      SmallIndx = first;//the smallest index will always be the next index in the array after the smallest item is
      //moved to the beginning of the array and is saved, so it wont be checked every time  
      
      //the loop will check the whole array for the smallest item and will leave the smallest saved number after 
      //the first item is saved
      for(int i = first+1; i < N; i++)
        {
          if(array[i] < array[SmallIndx]) //checks the smaller value                         
            
	    SmallIndx = i;//saves the index for smallest value
        }                                                                                        
      //smallest value will moved to the beginning of the array
      temp = array[SmallIndx];
      array[SmallIndx] = array[first];
      array[first] = temp;
    }
}

//Change this function so it sorts the numbers in descending order by moving the largest to the beginning: largest to smallest                                                                
//You can change the variable names to suit their purposes.                                                                                                                                   
//The structure of this code shouldn't change.
void selectionSort4(int array[], int N)
{
  int lrgIndx; //index for the largest value                                                  
  int temp; //holds temp largest value                                                                        

  for(int first = 0; first < N-1; first++)//start at the beginning of the array and move an index over after the first largest value has been found and moved to the beginning and so on until the array is sorted 
    {

      lrgIndx = first;//largest index moves along with the size of the array, first index is largest as well, after the first largest value is moved to the start of the array, the index for the largest value is now 1 instead of 0
      //?????????
      for(int i = first+1; i < N; i++)//searches the whole array for the largest value
        {
          if(array[i] > array[lrgIndx]) //if the current index value is bigger

            lrgIndx = i;//save the current index to the largest index
        }
      
      //move the largest value to the start of the array 
      temp = array[lrgIndx];
      array[lrgIndx] = array[first];
      array[first] = temp;
    }

}












