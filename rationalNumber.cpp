/*******************************************************************
CS211
1-31-2021
Template created by Kazumi Slott
rationalNumber.cpp

???  Jared Falcon  ?????????????
????? PROGRAM DESCRIPTION ??????????
This program will take two rational numbers using a struct and add them.
The program will also simplify the two added rational numbers. 
********************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

//Where do the prototypes go?
//ahaha
//declare a struct called rNum that has two fields called top and bot.
struct rNum
{
  int top;//numerator
  int bot;//denominator 

};
void simplify(rNum& n);
rNum getRationalNumber();
void print(const rNum n1, const rNum n2, const rNum ans);
rNum addRationalNumbers(const rNum n1, const rNum n2);
int main()
{
  //rNum num;

   
  rNum num1;//will store first rational number
  // int n1, n2;
  rNum num2;//will store second rational number 
  rNum answer;//stores the simplified answer for the two added rational numbers 
  // rNum num3;
  // rNum num4;

  cout << "Rational Number 1" << endl;
  num1 = getRationalNumber();//call getRationalNumber function to get the first rational number 

 
  cout << "Rational Number 2" << endl;
  num2 = getRationalNumber(); //call getRationalNumber function to get the second rational number 

  
  //call addRationalNumbers function to get the sum of the two rational numbers 
  answer = addRationalNumbers(num1, num2);//store answer

  print(num1, num2, answer);//call print function to show the answer
 
  
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
/**********************************************************************************
This function fills a rational number with the top and bottom numbers entered from the keyboard
and returns it.
************************************************************************************/

rNum getRationalNumber()
{
  rNum n; //rational number from the struct
  
  cout << "\tEnter the top number: ";
  cin >> n.top;// . operator to access the struct 
  cout << "\tEnter the bottom number: ";
  cin >> n.bot;//same for . operator 
  return n;//return the whole struct(rational number)
}


/***********************************************************************************
n1 is the first rational number
n2 is the second rational number

This function returns the sum of n1 and n2 in the simplest format.
************************************************************************************/

rNum addRationalNumbers(const rNum n1, const rNum n2)
{
  rNum ans;//rational number to hold the answer for the past two rational numbers

  ans.top = (n1.top*n2.bot)+(n1.bot*n2.top);//this will make the top number 
  ans.bot = (n1.bot*n2.bot);//botttom * bottom for the unsimplified bottom answer
 
  simplify(ans); //call simplify here   
 
  return ans;//return the simplified answer
}


/***********************************************************************************
n1 is the first rational number
n2 is the second rational number
ans is the sum of n1 and n2

This function will show the answer in the following format:

    6      13       5
 ----- + ----- = -----
    5      10       2
************************************************************************************/

void print(const rNum n1, const rNum n2, const rNum ans)
{ 
  cout << endl;
  if(ans.bot == 1)//if the bottom number is 1, dont print out the answer as a fraction
    {
      cout << right << setw(4) << n1.top << setw(8) << n2.top << endl;
      cout << "-----" << " + " << "-----" << " = " << ans.top << endl;
      cout << right << setw(4) << n1.bot << setw(8) << n2.bot << endl;
    }
  else//number is not 1, print out the fraction 
    {
      cout << right << setw(4) << n1.top << setw(8) << n2.top << setw(8) << ans.top << endl;
      cout << "-----" << " + " << "-----" << " = " << "-----" << endl;
      cout << right << setw(4) << n1.bot << setw(8) << n2.bot << setw(8)<< ans.bot << endl;
    }
  cout << endl;
}

  




