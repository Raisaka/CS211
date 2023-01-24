#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

using namespace std;

template <class T>
class myVector
{
private:
  T* ar;//pointer to an array
  int num; //the number of elements in the array pointed to by ar
public:
  myVector();~myVector();
  void push_back(const T& e);
  int size() const;
  T operator[](int index) const;
  void erase(int index);
  void insert(int index, const T& el); //the new element, e, will sit at index
  T& operator[] (int index); 
};
template <class T>
myVector<T>::myVector()
{
  ar = NULL;
  num = 0;//there are no elements in the array
}
/*************************************************
This is the destructor function that deletes the 
array if it goes out of scope
 ************************************************/
template <class T>
myVector<T>::~myVector()
{
  //The destructor is called automatically when an object of the class goes out of scope
  //The destructor cannot be called by the programmer.
  //Don’t forget to delete the array in heap!
  if(ar != NULL)
    delete [] ar;//if ar points to an array, delete it}
}
/************************************************
e is the new element we want to add 

This function will add a new element to the back 
of the dynamic array. It will create a new dynanic array
and copy all the elements from the previous array. 
 ***********************************************/
template <class T>
void myVector<T>::push_back(const T& e)
{

  T* temp = new T[num + 1];//make new dynamic array

  for(int i = 0; i < num; i++)//copy elements 
    {
      // temp[i] = ar[i];
      *(temp + i) = *(ar + i);
    }

  *(temp + num) = e;//put new element into last slot

  num++;//increment number of students

  delete [] ar;//delete the old array

  ar = temp;//make ar point to the new array
  temp = NULL;//temp now points to NULL

}
/***************************************************
index for the index we want to erase

This function will take an index value so it can erase
the value in that index. It will create a new dynamic array
and copy all the values from the previous array, except 
the erased index.
 ***************************************************/
template <class T>
void myVector<T>::erase(int index)
{
  
  if(index >= num)//if the index if num or greater its illegal 
    {
      cout << "Illegal index" << endl;
    }
  else//else make new array and copy
    {
      
      T* temp = new T[num - 1];//make new array with 1 less spot
      //cout << index << endl;
      
     for(int i = 0; i < index; i++)//copy elements up to the element we want to erase
	{
	  *(temp + i) = *(ar + i);
	  //  cout << "HEre" << endl;
	}
     num--;//decrement number of students
     
     for(int i = index; i < num; i++)
	{
	  *(temp + i) = *(ar + (i+1));//make the old array skip an element 
	  //*(temp + i) = *(ar + i);

	}
     
     // num--;
     
     delete [] ar;//delete the old array
  
     ar = temp;//make ar point to the new array
     temp = NULL;//temp now points to NULL
    }
}
/*************************************************
index is the index to be used
el is the element inserted 

This function will take an index and a value to be 
inserted at the given index. It will create a new
dynamic array with one more spot and copy all the 
elements as well as inserting the new element into 
the specific index. 
 ************************************************/
template <class T>
void myVector<T>::insert(int index, const T& el)
{
  

  if(index == num)//if index is == num use push_back
    {
      push_back(el);
    }
  else if(index > num)//else if index if bigger than num, illegal index
    {
      cout << "illegal index" << endl;
      //ar[index] = el;
    }
  else//else create new array
    {
      T* temp = new T[num+1];//new array with one more slot
  
      for(int i = 0; i < index; i++)//go through array and copy elements
	{
	  *(temp + i) = *(ar + i);
	}
  
      *(temp + index) = el;//it stopped at the desired index and will insert a new element 
      
      for(int i = index; i < num; i++)//keep copying elements 
        {
          *(temp + i+1) = *(ar + i);//our new array skips an index because it is taken already
        }

      num++;//increase num 

      delete [] ar;//delete old array

      ar = temp;//ar now points to new array
      temp = NULL;//temp points to null


      //      ar[index] = el;
      //cout << "illegal index" << endl;
    }
  
}
/*********************************
This function returns the size 
 ********************************/
template <class T>
int myVector<T>::size() const
{
  return num;
}
/*************************************
index for the returned index

This fucntion is overloaded so we can 
return the value at a specific index.
 ************************************/
template <class T>
T myVector<T>::operator[](int index) const
{
  return ar[index];
}
/******************************************
index for the index we want to access 

This fucntion will help us assign a new 
value into the given index of the vector.
 *****************************************/
template <class T>
T& myVector<T>::operator[] (int index)                 //myVector<int> v;
{//pass by reference pointing to *(ar + index)           v.push_back(0);
  if(index < num)                                      //v[0] = 9;
    return *(ar + index) ;                             //put 9 into slot 0
  else
    throw "invalid index";
}


//void print(const myVector<int>& v);
/*
int main()
{
  myVector<int> v;
  cout <<  " size " << v.size() << endl;
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);
  v.push_back(7);
  print(v);
  cout << endl;
  //cout << v[0] << endl;
  //v.erase(3);
  v.insert(1, 8);
  print(v);
  




  return 0;
}
*/
/*
void print(const myVector<int>& v)
{
  for(int i = 0; i < v.size(); i++)
    {
      cout << v[i] << " ";
    }
}
*/
#endif
