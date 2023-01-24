#include <iostream>

using namespace std;
void showProgInfo();
void getInfo(string& name, char& gender, int& age);
bool verifyEligibility(char gender, int age);
void printLetter(bool YorN, string name);
int main()
{
  string name;
  char g;
  int age;
  bool YorN;
  showProgInfo();
  getInfo(name, g, age);
  YorN = verifyEligibility(g, age);
  printLetter(YorN, name);

  return 0;
}
void showProgInfo()
{

  cout << "*******************************************************************" << endl;
  cout << "This program will tell you if you are eligible to join the military." << endl;
  cout << "*******************************************************************" << endl;

}
void getInfo(string& name, char& gender, int& age)
{
  cout << "Enter first name: ";
  cin >> name;
  cout << "Enter gender: ";
  cin >> gender;
  cout << "Enter age: ";
  cin >> age;

}
bool verifyEligibility(char gender, int age)
{
  if(gender == 'f')
    {
      return false;
    }
  else if(gender == 'm' && age >= 18)
    {
      return true;
    }
  else 
    {
      return false;
    }
}
void printLetter(bool YorN, string name)
{
  if(YorN == true)
    {
      cout << "Dear " << name << " please consider joining the military." << endl;
    }
  else 
    {
      cout << "Thank you for applying." << endl;
    }
}
