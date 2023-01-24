#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
  ifstream fin;
  fin.open("scores.dat");
  string name;
  int score1;
  int score2;

  if(!fin)
    {
      cout << "The input file does not exist!" << endl;
    }
  else
    {
      fin >> name >> score1 >> score2;

      while(fin)
	{
	  cout << fixed << setprecision(1);
	  cout << left << setw(10) << name << right << setw(5) << (double)(score1+score2)/2 << endl;
	  fin >> name >> score1 >> score2;
	}
    }
  fin.close();
      


  return 0;
}
