/******************************************************************
Jared Falcon
CS 211
4/15/2021

This program will be used as a college application that will add 
students and give them a unique ID. It will also add students from 
a file. It will be able to display a specific students' info or display
the info for all students. It will allow students to add courses to 
their schedule as well as dropping courses from their schedule. The
system will charge the student for adding a course and reducing a fee
if they drop a course as well. Students will be able to make a payment
to reduce their fees by their pay amount.
*******************************************************************/
#include <iostream>
#include <cstdlib> //for atoi() <-- you might not use this
#include <fstream>
#include <string>
#include "array.h"
#include "student.h"
#include "price.h"

using namespace std;
#include "/cs/slott/cs211/checkInput.h"

const int SIZE = 100; //size of the array
const int START = 100000;//student id starts at 100000
const int PASSWORD = 123; //password for admission's office 
const int PRIME1 = 31; //used to calculate a student's password
const int PRIME2 = 5;

int showMenu();
int showAdmMenu();
int showStuMenu();
void addStu(Student ar[], int& c, int& id);
void showStuInfo(const Student& s);
void allStuInfo(const Student ar[], int c);
bool operator==(const Student& s, int id );
void removeStu(Student ar[], int& count, int& id);
void addStuFromFile(Student ar[], int& c, int& id);
void addCourse(Student& s);
void dropCourse(Student& s);
void makePayment(Student& s);
int verifyStu(const Student a[], int c);
void viewStuInfo(const Student a[], int c);
int findStu(const Student a[], int c);
bool checkPassword(int word);

int main()
{
  int count = 0; //the number of students in the array
  int curID = START; //curID is the student id used for the next student you are creating
  Student arr[SIZE]; //student class array
  int ID;//changes the ID we are looking for in the array
  int Main;//shows the main menu
  int stuMenu;//used for the student menu
  int stuID;//verify student
  int admin;//used fo admin menu

  
  do{
    Main = showMenu();//MAIN menu

    switch(Main)//check what the user wants to do 
      {                   
      case 1: //admission menu
	if(checkPassword(123))//check password
	  {
	    do
	      {
		admin = showAdmMenu();  //show admin menu if correct
		switch(admin)//admin choices
		  {
		  case 1:
		    addStu(arr, count, curID);
		    break;
		  case 2:
		    addStuFromFile(arr, count, curID);
		    break;
		  case 3:
		    removeStu(arr,count, ID);
		    break;
		  case 4:
		    viewStuInfo(arr,count);
		    break;
		  case 5:
		    allStuInfo(arr, count);
		    break;
		  }
	      }while(admin !=6);//so we can quit this admin menu
	  }
	break;
      case 2: //student Menu
	stuID = verifyStu(arr,count);//check Student ID
	if(stuID != -1)//verify student
	  {
	    if(checkPassword(arr[stuID].getStuID() % (PRIME1 * PRIME2)))//passwords match
	    {
	      cout << "Welcome " << arr[stuID].getFirstName() << endl;
	      do
		{
		  stuMenu = showStuMenu();  //displays student Menu
		  switch(stuMenu)//student menu options
		    {
		    case 1:
		      addCourse(arr[stuID]);
		      break;
		    case 2:
		      dropCourse(arr[stuID]);
		      break;
		    case 3:
		      makePayment(arr[stuID]);
		      break;
		    case 4:
		      showStuInfo(arr[stuID]);
		      break;
		    }
		}while(stuMenu != 5);//quit the student menu
	    }
	}
      break;  //END for case 2:
      }
  }while(Main != 3);
  
  return 0;
}



// ************************  PHASE 1  ****************************
/***********************************************************
ar[] is the student array
c is the amount of students we have in the array
id will be their new ID given to each student

This fucntion will create a student object with 4 parameters 
and it will store the student in the array with all their info.
 **********************************************************/
void addStu(Student ar[], int& c, int& id)
{
//case 1 of admission
  
  // Student s;
  // int index = 0;
  // int newID = START;
  string fn;//first name
  string ln;//last name
  char G;//gender
  //  s(s.first, s.last, s.G, newID);
  
  //Enter the student info
  cout << "Enter new student info: " << endl;
  cout << "Enter first name: ";
  cin >> fn; 
  cout << "Enter last name: ";
  cin >> ln;
  cout << "Enter gender: ";
  cin >> G;
  cout << endl;
  Student s(fn, ln, G, id);//make a student object
  // newID++;
  ar[c] = s;//add student to student array
  id++;//increment id
  c++;//increment count, number of students
  //create a student object. The first student created is given a stu id, 100000 (coming from const START).
  //The second student gets 100001, the third student gets 100002, etc (notice curID in main).

  //copy the info from the stu obj into the array at the appropriate slot


}
/**************************************************************
s will pass a student

This function will show the information of one student, as well
as their classes, and money they owe.
 **************************************************************/
void showStuInfo(const Student& s)            
{                                                                                                                                             
//*********************************************************************
//DO NOT send the entire array to this function. BIG deduction if you do.
//SEND only ONE student object as a parameter. If you don't know how, check
//lab1-struct.cpp.
//********************************************************************** 
  Price p;
  Price c(50, 14);

  //displays the student info using the get function
  cout << "--------------------" << endl;                                                         
                                                                                                                                             
  cout << "first name: " << s.getFirstName() << endl;                                                                                                 
 
  cout << "last name: " << s.getLastName()  << endl;                                                                                                  
 
  cout << "gender: " << s.getGender() << endl;                                                                                                      
 
  cout << "stu id: " << s.getStuID() << endl;                                                                                                      
 
  cout << "num classes: " << s.getNumClasses()  << endl;                                                                                                  
 
                                                                                                                                            
  cout << "Courses: ";                                                                                                                        
  //display the amount of courses
  for(int i = 0; i < s.getNumClasses() ; i++)  //Don't use showAllCourses() but show each course at a time. Which memeber func    
    {
      cout << s.getClassOf(i)  << " ";                               
      p = p + c;//price adds up for every class
    }
  
  //displays the amount a student owes
  //  Price p;
  //Price c(50, 14);
  
  cout << "\nAmount owed $" << s.getBalance()  << endl;  //You have an operator overloading function to show a price object at once                   
 
  cout << endl;                                                                                                                               
 
  }
/**************************************************************
ar[] for the student array
c for the amount of students in the array

This fucntion will display all the students info from the array
it will be calling showStuInfo().
 *************************************************************/
void allStuInfo(const Student ar[], int c)
{
//Case 5 of Admission and case 4 of student
//Call showStuInfo()
//******************************************
//YOU MUST call showStuInfo() to show each student.
//*******************************************
  //for loop to go through the student array
  for(int i = 0; i < c; i++)
    {
      showStuInfo(ar[i]);//call showStuInfo
    } 
}
/*******************************************************
s is the student object
id is the ID we want to compare

This function will let us overload ==  
 *****************************************************/
bool operator==(const Student& s, int id )
{
  if(s.getStuID() == id)//compare the passes id 
    {
      return true;//true
    }
  else//not the same
    {
      return false;//false
    }
  
  
  //????????
}
/*********************************************************
ar is the student array
count for the amount of students
id for finding our student

This function will allow us to remove a student from our array
we will be calling find() and remove() from array.h
 ********************************************************/
void removeStu(Student ar[], int& count, int& id)
{
//Case 3 of Admission

//2 different messages

     //"student with id " << id << " doesn't exist" << endl;
     // f << " " << l << " has been removed." << endl;
  // bool found;
  int fin;//stores the found index 
  // found = find(ar, count, id); 
  cout << "Enter the student ID: ";
  cin >> id;
  fin = find(ar, count, id);//find the student using their ID
  //found = remove(ar, count, id);

  if(fin == -1)//if find returns -1, not found
    {
      cout << "student with id " << id << " doesn't exist" << endl;
    }
  else//else the student was found
    {
      //remove(ar, count, id);
      //display the first and last name of the student being removed
      cout << ar[fin].getFirstName() << " " << ar[fin].getLastName() << " has been removed." << endl;
      remove(ar, count, id);//now remove the student
      // cout <<"Student has been removed." << endl;
      count--;//decrement the amount of students in the array
    }

}
/***********************************************************
ar for student array
c for the amount of students
id for the new student id

This fucntion will read names from a file and add them to the 
student array.
 **********************************************************/
void addStuFromFile(Student ar[], int& c, int& id)
{
//Case 2 of admiss
//  Student s;
  string fn;//stores first name
  string ln;//stores last name
  char G;//stores gender
  string filename;//our filename to type
  cout << "Enter a filename: ";
  cin >> filename;//enter filename

  ifstream inFile;//declare the input file locallyin this function
  inFile.open(filename.c_str());//change this to enter from keyboard

  if(!inFile)//If the input file doesn't exist
    {
      cout << "Cannot open the file" << endl;
      //      exit(1);
    }
  else
    {
      inFile >> fn >> ln >> G;//read first line from file
      //      Student s(fn, ln, G, id);
      // ar[c] = s;
      while(inFile && c < SIZE)//while infile and size is less than amount of student
	{
	  
	  Student s(fn, ln, G, id);//make student object
	  ar[c++] = s;//add student to array
	  id++;//increment id
	  inFile >> fn >> ln >> G;//read next line
	  
	}
      inFile.close();//close file
    }
}

//*******************  PHASE 2 ****************************

/**********************************************************
s is the student were are trying to pass

This function will allow a student to add a course if they 
dont have the course already and if their schedule is not full.
 *********************************************************/
void addCourse(Student& s)
{
//case 1 of student
//FYI, I am passing one student to this function not the array. 
  int CRN;//course number
  int pass;//will store a different option

  cout << "Enter CRN: ";
  cin >> CRN;
  
  pass = s.addCourse(CRN);//store the returned value in pass
  if(pass == 1)//value is 1, able to add course
    {
      cout << CRN << " was added successfully" << endl;
      s.addFee(50, 14);//add fee
    }
  else if(pass == 0)//value is 0, the student already has the course
    {
      cout << CRN << " was not added because you have " << CRN << " already" << endl;
    }
  else//there is no more room for more courses
    {
      cout << CRN << " was not added because your schedule is full." << endl;
    }
    

//3 different messages to show

  // " has been added successfully" << endl;
  // " was not added because you have " << crn << " already." <<  endl;
  // " was not added because your schedule is full." <<  endl;


}
/*******************************************************
s is the student we are passing

This function will allow a student to drop a course if
they have the course only. It will reduce their fee if
the course is dropped.
 ******************************************************/
void dropCourse(Student& s)
{
//case 2 of admission
//FYI, I am passing one student to this function not the array. 
  int CRN;//our course number

  cout << "Enter the CRN: ";
  cin >> CRN;

  if(s.dropCourse(CRN) == false)//check if true or false
    {
      cout << CRN << " wasnt dropped from " << s.getFirstName() << " because " << CRN << " doesnt exist" << endl;
    }
  else
    {
      cout << CRN << " has been dropped successfully." << endl;
      s.reduceFee(50, 14);
    }
//2 different messages
    // " wasn't dropped from " << s.getFirstName() << " because " << cr << " doesn't exist" << endl;
    // " has been dropped successfully." << endl;


}
/*********************************************************************
s is the student we are passing 

This function will allow the student to make a payment for their classes.
It will convert a string into an integer for the amount money they owe.
 ********************************************************************/
void makePayment(Student& s)
{
  int dollars;//will store dollars
  int cents;//stores cents
  string owe;//user payment input
  bool y = false;//set y to false and true later 
  cout << "You owe: " << s.getBalance() << endl;
  cout << "Enter your payment: ";
  cin >> owe;
  int x = owe.find(".");
  
  if(x == -1)//"." was not found two digits
    {
      dollars = atoi(owe.c_str());//convert to int
      cents = 0;//make cents = 0
      y = true;
    }
  else// check for different pay formats
    {
      string cent = owe.substr(x + 1, owe.length() - x + 1);//if its 1 2 or 3 digits long
      dollars = atoi(owe.substr(0, x).c_str());//this should just be two digits
      
      if(cent.length() != 2)//if its bigger than two digits for cents, its wrong
	{
	  cout << "Wrong pay format! " << endl;
	  
	}
      else if(cent.length() == 2)//if its equal to 2 digits, its correct
	{
	  cents = atoi(cent.c_str());//make cents equal to whatever cent had, which is 2 digits 
	  y = true;
	}
    }
  if(y == true)//if the format is good, reduce the fee
    {
      s.reduceFee(dollars, cents);

    }
  
}
  //case 3 of student
//FYI, I am passing one student to this function not the array.  
  // }
  //}




//******************** PHASE 3 ****************************
/****************************************************************
word is the password we pass

This function will check if the password the user enter is correct.
It will return true or false depending if its correct or not.
 ***************************************************************/
bool checkPassword(int word)
{
  int pass;//user enters password
  cout << "Enter the password: ";
  cin >> pass;

  if(pass != word)//if it doesnt match actual password
    {
      cout << "The password is incorrect! " << endl;
      return false;//not correct
    }
  else//password is the same
    {
      return true;
    }
//I am using this function to check a password for both the admission's office and student
//FYI, I am passing the correct password as a parameter and returning true/false.
//The correct password for a student is  student_id % (PRIME1 * PRIME2)
}
/*******************************************************************
ar[] is our student array
size is the size of the array

This function will be able to find a student and return the index
where the student is found in the student array.
 *******************************************************************/
int findStu(const Student ar[], int size)
{
  int ID;//look for ID
  cout << "Enter the student ID: ";
  cin >> ID;

  int found = find(ar, size, ID);//call find function to return index if found
  return found;
//Small function. You may choose not to use this function. That is OK.

//Ask for the student id
//call find() to find the student id
//return what find() returned which is index where it was found or -1
}
/******************************************************************
ar[] is our student array
size is the size of the array

This function will be able to find a student and if the student is 
in the array, it will display the student info. Otherwise it doesnt
exist in the array.
*******************************************************************/
void viewStuInfo(const Student ar[], int size)
{
  int find = findStu(ar, size);//call findStu
  if(find == -1)//not found
    {
      cout << "The student ID does not exist." << endl;
      cout << endl;
    }
  else//found, show the info
    {
      showStuInfo(ar[find]);
    }
//Case 4 of admission
//Ask for the student id
//If the student doesn't exist, show an error message.
//If it exists, call showStuInfo to show the student
}
/****************************************************************
ar[] is our student array
size is the size of the array

This function will able to verify if the student is the array.
 ***************************************************************/
int verifyStu(const Student ar[], int size)
{
  int find = findStu(ar, size);//call findStu
  if(find == -1)//not found
    {
      cout << "The student ID does not exist." << endl;
      return -1;
    }
  else//student was found
    {
      return find;
    }
//You may decide not to use this function. If so, that is OK.

//When the user is a student, select 2 in the top menu. He/she enters hi/her student id.
//Make sure the stuent id exists in the array. If not, I am showing an error message.
//FYI, I am returning the index where the student was found or -1 if not found.
}
/************************************************
This function shows the main menu.
 ***********************************************/
int showMenu()
{
  int choice;
  cout << "========================================================" << endl;
  cout << "1: Admission's Office" << endl;
  cout << "2: Student" << endl;
  cout << "3: End program" << endl;
  cout << "========================================================" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 3, "\tInvalid choice. Enter only 1, 2 or 3: ");

  return choice;
}
/***************************************************
This function shows the student menu.
****************************************************/
int showStuMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a course" << endl;
  cout << "2: drop a course" << endl;
  cout << "3: Make a payment" << endl;
  cout << "4: View my information" << endl;
  cout << "5: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 5, "\tInvalid choice. Enter only 1 through 5: ");

  return choice;
}
/*****************************************************
This function shows the admin menu.
 ****************************************************/
int showAdmMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a new student" << endl;
  cout << "2: Add new students from a file" << endl;
  cout << "3: drop a student" << endl;
  cout << "4: View one student info" << endl;
  cout << "5: View all students' info" << endl;
  cout << "6: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 6, "\tInvalid choice. Enter only 1 through 6: ");

  return choice;
}



