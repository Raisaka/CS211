/*********************************************************************
Jared Falcon
cs 211
2/11/21

This program will take visitors info and save them in three different 
arrays. The program will be able to reject bad inputs as well as 
print the statistics of the museum visits to the console. It will also
display them in a seperate file with the name of the days date. 
 *******************************************************************/
#include <iostream>
#include <iomanip>
#include "array.h"
#include <fstream>
#include <cstdlib>

using namespace std;
#include "/cs/slott/cs211/checkInput.h"

int showMenu();
void getVisitorInfo(string ar[], int ar2[], double ar3[], int size, int& visitors);
bool checkPassword();
template<class T>//template class to use cout or fout
void showStatistic(T& out, string ar1[], const int ar2[], const double ar3[], int visitors);


int main()
{
  const int SIZE = 100;//array size
  string info1[SIZE];//string array
  int info2[SIZE];//age array
  double info3[SIZE];//hours visited array
  char end;//used to get out of while loop 
  int option1;//used to store showMenu() 1 or 2
  bool option2;//used to store true or false for our password
  // int option3;
  int people = 0;//stores number of people at the museum
  char YorN;//stores answer to closing the museum
 
  do//do while loop to keep showing the menu as long as the staff doesnt close the museum
    {
      option1 = showMenu();//call menu with 1 or 2
      // cout << endl;
      switch(option1)//switch statement for our two options
	{
	case 1://case 1 is for the visitor
	  getVisitorInfo(info1, info2, info3, SIZE, people);//get their info
	  break;
	case 2: option2 = checkPassword();//case 2 if for the staff, checks password
	  if(option2 == true)//if the password is correct
	    {
	      showStatistic(cout, info1, info2, info3, people);//show stats
	     
	      //ask if they want to close the museum
	      cout << "Do you want to close the museum? Y or N: ";
	      YorN = getYN("Invalid answer. Enter Y or N: ");
	      //	      cout << endl;
	      if(YorN == 'Y')//if yes, open a file 
		{
		  ofstream fout;//writing to a file
		  string date;//our files name
		  string filename;//used to combine the date and txt
		  //ask for the date
		  cout << "Enter today's date: ";
		  cin >> date;
		  filename = date + ".txt";//filename gets date
		  fout.open(filename.c_str());//create and open file with the date
		  //print to file
		  showStatistic(fout, info1, info2, info3, people);//write the stats to the file date
		  fout.close();//close file
		  end = 'Y';//used to get out of loop		  
		}
	      else//if not closed, return to the main menu
		{
		  end = 'N';
		}
	      
	    }
	  else//else if password is wrong go back to the menu
	    {
	      end = 'N';
	    }
	  break;
	default: cout << "No" << endl;//default case not used
	}
    }
  while(end != 'Y');//condition to get out of loop
  {
    cout << endl;
  }
  


  return 0;
}
/***************************************************************
This function will display the menu of the museum.
 **************************************************************/
int showMenu()
{
  int choice;
  cout << endl;
  cout << "=============================================" << endl;
  cout << "1. Visitor" << endl;
  cout << "2. Museum Staff" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 2, "Invalid choice. Enter 1 or 2: ");
  return choice;//return 1 or 2 for visitor or staff

  
}
/*****************************************************************
string ar is to save our country names
int ar2 is to save the ages of visitors
int ar3 is to save the amount of hours they stayed
int size is for the max size of the array
int& visitors is to change the exact amount if visitors in the museum

This funtion is used to get the visitors information and store the 
three different sets of data into three different arrays.
 ****************************************************************/
void getVisitorInfo(string ar[], int ar2[], double ar3[], int size, int& visitors)

{

  string country;//to enter country
  int age;//visitor age
  double hours;//amount of hours spent
  // int index=0;

  
  if(visitors < size)//if visitors is less than the max size, you can enter more info
    {
      cout << endl;
      cout << "Enter your country: ";
      cin >> country;
      cout << "Enter your age: ";
      age = getData(0, 200, "The age has to be between 0 and 200. Enter again: ");//used to reject bad data
      cout << "Enter the number of hours you explored: ";
      hours = getData(0.0, 10.0, "The number of hours has to be between 0 and 10.0. Enter again: ");//reject double bad data
      //using visitors as the index of the arrays
      ar[visitors] = country;
      ar2[visitors] = age;
      ar3[visitors] = hours;
     
      visitors++;//after the data is entered for a visitor, increase the index 
    }
  else//reached the max amount of data that can be stored
    {
      cout << "We cannot take any more visitor info" << endl;//no more visitors
    }
  //  cout << endl;
  //  cout << "============================================" << endl;
}
/************************************************************************
This function will check for the entered password, if its correct return
true otherwise return false and display msg.
 ************************************************************************/
bool checkPassword()
{
  int pass;//user enters password

  cout << "Enter the password: ";
  cin >> pass;
  if(pass == 5678)//if paswword is correct
    {
      return true;
    }
  else//wrong, display msg and return false
    {
      cout << "Password is wrong" << endl << endl;
      return false;
    }

}
/**************************************************************************
T& out is used to print either cout or fout
string ar is to save our country names
int ar2 is to save the ages of visitors
int ar3 is to save the amount of hours they stayed
int visitors is to change the exact amount of visitors in the museum

This function will show the stats for the day. It will show oldest person, 
youngest, average time, etc. The function will display the countries people
are from and their data as a whole. If there are no visitors it wont display.
 *************************************************************************/
template<class T>//used for out 
void showStatistic(T& out, string ar[], const int ar2[], const double ar3[], int visitors)
{
  
  out << endl;
  out << "The total number of visitors is " << visitors << endl;//amount of visitors
  out << endl;
  
  //if there is visitors
  if(visitors > 0)//visitors stats are displayed if at least one
    {
      
      int youngest;//used to store the youngest person
      int oldest;//oldest person
      double ages;//average ages
      int low;//lowest time spent
      int high;//highest time spent
      double average;//average hours spent
      string uni[visitors];//array to store unique items
      int uni2;//used to get amount of unique items
      out << "------- The name of the countries of visitors ------" << endl;
      uni2 = unique(ar, uni, visitors);//call unique
     
      sort(uni, uni2);//sort the countries

      printOUT(out, uni, uni2);
      //print the countries

      youngest = getLowest(ar2, visitors);//stores youngest age index
      oldest = getHighest(ar2, visitors);//stores oldest age index
      ages = getAvg(ar2, visitors);//stores average age
      out << endl << endl;
      out << fixed << setprecision(1);//1 decimal
      out << "The age of the youngest visitor: " << ar2[youngest] << endl;//use the second age array with index
      out << "The age of the oldest visitor: " << ar2[oldest] << endl;//age array with oldest index
      out << "The average age of the visitors: " << ages << endl;//average age
      out << endl;
      low = getLowest(ar3, visitors);//index of lowest hours
      high = getHighest(ar3, visitors);//index of highest hours
      average = getAvg(ar3, visitors);//stores average time visit
      out << "The shortest visit hours: " << ar3[low] << endl;//hours array with low index
      out << "The longest visit hours: " << ar3[high] << endl;//hours array with high index
      out << "The average visit hours: " << average << endl;//display average hours
      out << endl;
    }
  
}
