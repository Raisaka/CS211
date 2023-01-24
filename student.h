#ifndef STUDENT_H
#define STUDENT_H
#include "price.h"
#include <string>

using namespace std;
const int MAX = 6;
class Student
{
 private:
  string Fname;
  string Lname;
  char Gender;
  int numClass;//number of classes the student is taking
  int Classes[MAX];//max amount of classes a student can take
  int stuID;
  Price balance;

 public:
  Student();
  Student(string first, string last, char G, int ID);
  int addCourse(int crn);
  void viewAllCourses() const;
  bool dropCourse(int crn);
  string getFirstName()const;
  string getLastName() const;
  char getGender() const;
  int getNumClasses() const;
  int getStuID() const;
  int getClassOf(int i) const;
  Price getBalance() const;
  void addFee(int d, int c);
  void reduceFee(int d, int c);
};
#endif

