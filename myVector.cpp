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
};

template <class T>
myVector<T>::myVector()
{
  ar = NULL;
  num = 0;//there are no elements in the array?
}

template <class T>
myVector<T>::~myVector()
{
  //The destructor is called automatically when an object of the class goes out of scope
  //The destructor cannot be called by the programmer.
  //Don’t forget to delete the array in heap!
  if(ar != NULL)
    delete [] ar;//if ar points to an array, delete it}
}

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
template <class T>
void myVector<T>::erase(int index)
{
 
  if(index > num)
    {
      cout << "Illegal index" << endl;
    }
  else
    {
      
      T* temp = new T[num - 1];
      //cout << index << endl;
      
     for(int i = 0; i < index; i++)//copy elements up to the element we want to erase
	{
	  //  cout << "HEre" << endl;
	  *(temp + i) = *(ar + i);
	}
      
       
      for(int i = index; i < num; i++)
	{
	  *(temp + i) = *(ar + i+1);//make the old array skip an element 
	}
      
      num--;
  
      delete [] ar;
  
      ar = temp;
      temp = NULL;
    }
}
template <class T>
void myVector<T>::insert(int index, const T& el)
{
  

  if(index == num)
    {
      push_back(el);
    }

    else if(index > num)
    {
      cout << "illegal index" << endl;
      //ar[index] = el;
    }
  else
    {
      T* temp = new T[num+1];
      for(int i = 0; i < index; i++)
	{
	  *(temp + i) = *(ar + i);
	}
      *(temp + 1) = el;
      for(int i = index; i < num; i++)
        {
          *(temp + i+1) = *(ar + i);
        }

      num++;

      delete [] ar;

      ar = temp;
      temp = NULL;


      //      ar[index] = el;
      //cout << "illegal index" << endl;
    }
  
}
template <class T>
int myVector<T>::size() const
{
  return num;
}
template <class T>
T myVector<T>::operator[](int index) const
{
  return ar[index];
}

template <class T>
main
T&myVector<T>::operator[] (int index)
myVector<int> v;
{//pass by reference pointing to *(ar + index)v.push_back(0);
  if(index < num)//v[0] = 9;
    return *(ar + index) ;//put 9 into slot 0
  else
    throw "invalid index";
}


void print(const myVector<int>& v);

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
void print(const myVector<int>& v)
{
  for(int i = 0; i < v.size(); i++)
    {
      cout << v[i] << " ";
    }
}
