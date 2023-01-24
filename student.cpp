#include <iostream>
#include "student.h"
#include "array.h"
#include "price.h"

using namespace std;

Student::Student()
{
  Fname = "unknown";
  Lname = "unknown";
  Gender = 'x';
  numClass = 0;
  stuID = -1;
}
Student::Student(string first, string last, char G, int ID)
{
  Fname = first;
  Lname = last;
  Gender = G;
  numClass = 0;
  stuID = ID;
}
void Student::addFee(int d, int c)
{
  int dol = d;
  int cen = c;
  Price p1(dol, cen);
  balance = balance + p1;
}
void Student::reduceFee(int d, int c)
{
  int dol = d;
  int cen = c;
  Price p2(dol, cen);
  balance = balance - p2;
}
Price Student::getBalance() const
{
  return balance;
}
string Student::getFirstName()const
{
  return Fname;
}
string Student::getLastName() const
{
  return Lname;
}
char Student::getGender() const
{
  return Gender;
}
int Student::getNumClasses() const
{
  return numClass;
}
int Student::getStuID() const
{
  return stuID;
}
int Student::getClassOf(int i) const
{
  return Classes[i];
}
int Student::addCourse(int crn)
{
  int found;
  if(numClass < MAX)//room in array
    {
      found = find(Classes, numClass, crn);//store returned value in found
      if(found == -1)//if crn was not found
	{
	  Classes[numClass++] = crn;//add class to array and increment numClass
	  return 1;//return 1
	}
      else if(found >= 0)//if crn was found
	{
	  return 0;//return 0 and dont add class
	}
    }
  else//array is full 
    {
      return -1;
    }
  /*  for(numClass = numClass; numClass < MAX; numClass++)
    {
      if(Classes[numClass] == crn)
	{
	  return 0;
	}
      else if(numClass < MAX)
	{
	  Classes[numClass++] = crn;
	  return 1;
	}
      else if(numClass >= MAX)
	{
	  return -1;
	}
    }
  */
	/* if(numClass < MAX)//theres room in the array
    {
    Classes[numClass++] = crn;
    return 1;
    }
    else if(numClass >= MAX)
    {
    return -1;
    }
    else(Classes
    {
    return 0;
    }
	*/
}
void Student::viewAllCourses() const
{
  if(numClass > 0)
    {
      //      for(int i = 0; i < numClass; i++)
      // {
      //cout << Classes[i] << " " << endl;
      // }
      print(Classes, numClass);
      
    }
  else
    {
      ;
    }
}
bool Student::dropCourse(int crn)
{
  bool rm;
  rm = remove(Classes, numClass, crn);
  if(rm == true)
    {
      numClass--;
      return true;
    }
  else
    {
      return false;
    }
}
