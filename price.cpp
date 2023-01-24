#include <iostream>
#include "price.h"

using namespace std;

Price::Price()
{
  dollar = 0;
  cent = 0;
}

Price::Price(int d, int c)
{
  dollar = d;
  cent = c;
}
Price Price::operator+(const Price& n)
{
  int dolar = this->dollar + n.dollar;
  int centa = this->cent + n.cent;

  if(centa >= 100)
    {
      centa = centa-100;
      dolar++;
    }
  Price c1(dolar, centa);
  return c1;
}
Price Price::operator-(const Price& m)
{
  int dolar = this->dollar - m.dollar;
  // int centa = this->cent - m.cent;
  int centa;

  if(this->cent < m.cent)
    {
      dolar--;
      
      centa = (100+this->cent)-m.cent;
      //centa = centa + this->dollar;
    }
  else
    {
      centa = this->cent - m.cent;
    }
  Price c2(dolar, centa);

  return c2;
}
ostream& operator<<(ostream& os, const Price& p)
{
  if(p.cent == 0)
    {
      os << p.dollar << "." << "0" << p.cent;
    }
  else if(p.cent < 10)
    {
      os << p.dollar << "." << "0" << p.cent;
    }
  else
    {
      os << p.dollar << "." << p.cent;
    }
  return os;
}
