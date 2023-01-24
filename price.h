#ifndef PRICE_H
#define PRICE_H
#include <string>

using namespace std;

class Price
{
  friend ostream& operator<<(ostream& os, const Price& p);
 private:
  int dollar;
  int cent;


 public:
  Price();
  Price(int d, int c);
  Price operator+(const Price& n); //+ is overloaded
  Price operator-(const Price& m);

};
#endif
