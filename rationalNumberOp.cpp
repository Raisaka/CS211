/********************************************
Template created by Kazumi Slott
CS211
Date: 2/20/2021????????????????
Your name: Jared Falcon???????????????
Description of your program: This program will use operator ovverloading functions 
in order to input, output, add and compare rational numbers.
 ???????????????
********************************************/
#include <iostream>
using namespace std;
#include "array.h"  //This is your array.h

struct rNum
{
  int top; //numrator
  int bot; //denominator
};
istream& operator>>(istream& is, rNum& n);
ostream& operator<<(ostream& os, const rNum& n);
rNum operator+(const rNum& n1, const rNum& n2);
rNum operator+=(rNum& n1, rNum& n2);
bool operator==(const rNum& n1, const rNum& n2);
bool operator>(rNum& n1, rNum& n2);
void simplify(rNum& n);

int main()
{
  rNum n1;//first rational number
  rNum n2;//second rational number 
  rNum ans;//answer for both rational numbers 

  cout << "\n-------------- 1 -----------------" << endl;
  cout << "Rational Number 1";
  cin >> n1;//is operator overloading a rational number  
  
  cout << "n1 is " << n1 << endl;// os operator overloading to output the rational number
 
  cout << "\n-------------- 2 -----------------" << endl;
  cout << "\nRational Number 2";
  cin >> n2;//is operator overloading a rational number
  
  cout << "n2 is " << n2 << endl; // os operator overloading to output the rational number
 
  cout << "\n-------------- 3 -----------------" << endl;
  ans = n1 + n2;//+ operator overloading to add two rational numbers and store them into another 
 
  cout << n1 << " + " << n2 << " = " << ans << endl; //os operator overloading to output the rational numbers
  
  cout << "\n-------------- 4 -----------------" << endl;
  const int SIZE = 3;//const variable 
  //Declare an array of rNums that has SIZE slots
  rNum ar[SIZE];//rational number array
  //?????????? 
 
  //fill the array by calling fill() in your array.h
  fill(ar, SIZE);
  //??????????

  cout << "Checking to see if the array is filled" << endl;
  //print the array by calling print() in your array.h
  /*
  for(int i = 0; i < SIZE; i++)
    {
      cout << ar[i] << " ";
    }
  */  
  print(ar, SIZE);
    
  //?????????
  
  
  cout << "\n-------------- 5 -----------------" << endl;
  //sort the array in ascending order by calling sort() in your array.h
  sort(ar, SIZE);
  //???????????

  cout << "Checking to see if the array is sorted in ascending order" << endl;
  //print the array by calling print() in your array.h
  print(ar, SIZE);
  //?????????

    
  cout << "\n-------------- 6 -----------------" << endl;
  cout << "Checking to see if " << n1 << " is in the array " << endl;
  //Call find() in your array.h to see if n1 exists in the array. Say found or not found. See #6 in the test runs in the hw document.   
  int found;//int variable to store the index found
  found = find(ar, SIZE, n1);//find function 
  //  cout << found << endl;
  if(found == -1)//if the found value is -1 display message
    {
      cout << n1 << " is not in the array." << endl;
    }
  else//otherwise it returns the index and display rational number found 
    {
      cout << ar[found] << " is found." << endl;
    }
    

  cout << "\n-------------- 7 -----------------" << endl;
  cout << "n1 is " <x< n1 << " n2 is " << n2 << " before n1 += n2" << endl;
  n1 += n2;//+= operator overloading the two rational numbers
 
  cout << "After n1 += n2, n1 is " << n1 << endl << endl;
  
  return 0;
}
/***********************************************************************************
n is a rational number

This function simplifies n, which is a rational number in the caller
************************************************************************************/
void simplify(rNum& n)
{
  int upper = n.top;//copy top number
  int down = n.bot;//copy bottom number
  while(upper != down)//stay in the loop as long as top and bottom are not equal to find the Greatest Common Denominator
    {
      if(upper > down)//top is bigger
	{
	  upper = upper - down;//up is now the product of top - bottom
	}
      else//until bottom is bigger, down will be the prodcut of bottom - top
	{
	  down = down - upper;//down changes
	}
    }
  //exit the loop if top and bottom numbers are equal and thats the GCF
  //upper is the GCF
  n.top = n.top / upper;//n.top = 125/25 = 5
  n.bot = n.bot / upper;//n.bot = 50/25 = 2

}

/******************************************
Create operator overloading functions down below so the above main runs.
You need to figure out what you need to make.
*******************************************/
/**********************************************************
n1 is a rational number
n2 is a rational number

THis function will overload the operator > using two rational numbers.
**********************************************************/
bool operator>(rNum& n1, rNum& n2)
{
  if((double)n1.top/n1.bot > (double)n2.top/n2.bot)//compares the values of the rational numbers 
    {
      return true;
    }
  else//if less than return false
    {
      return false;
    }
}
/***********************************************************
is will able to overload >> for cin
n is the rational number we want to type 

This function will let us type in a rational number in main,
without us having to call top or bottom while in main.
 **********************************************************/
istream& operator>>(istream& is, rNum& n)
{
  cout << endl;
  cout << "\tEnter the top number: ";
  is >> n.top;
  cout << "\tEnter the bottom number: ";
  is >> n.bot;
  return is;//return inputs 
}
/*******************************************************
os will be able to use << for cout
n is the rational number that will be displayed

This fuction will be able to display our rational number 
in main without top or bot being displayed.
 ******************************************************/
ostream& operator<<(ostream& os, const rNum& n)
{
  os << n.top << "/" << n.bot;
  return os;//return outputs 
}
/*********************************************************
n1 is the first rational number
n2 is the second rational number 
ans is the answer when you add both n1 and n2 and it will be simplified

This function will return the simplified addition of two 
rational numbers.
 ********************************************************/
rNum operator+(const rNum& n1, const rNum& n2)
{
  rNum ans;//stores rational numbers added 
  ans.top = n1.top * n2.bot + n2.top * n1.bot;
  ans.bot = n1.bot * n2.bot;
  simplify(ans);//simplify ans
  return ans;//return ans 
}
/*******************************************************
n1 is the first rational number
n2 is the second rational number

This function will let us the += operator in main so we 
can add two rational numbers.
 ******************************************************/
rNum operator+=(rNum& n1, rNum& n2)
{
  //rNum n3;
  n1 = n1 + n2;//add both rational numbers and store in n1
  return n1;//return n1
}
/********************************************************
n1 is a rational number 
n2 is a rational number 

This function will compare two rational numbers if they are the same.
 ******************************************************/
bool operator==(const rNum& n1, const rNum& n2)
{
 
  if(n1.top == n2.top && n1.bot == n2.bot)//compares the rational numbers top and bottom if they are the same
    {
      return true;
    }
  else//not the same
    {
      return false;
    }
}

