#include "Complex.h"


int main()
{
  
  TComplex a(1, sqrt(3));
  TComplex b(-2, -1);
  TComplex c(-1, 10);

  b.PrintTrig();

  TComplex d = a / b;
  d.CPrint();

  d = b + c;
  d = b - c;
  d = b * c;
  d = b / c;

  std::cout << "\n\n";
  std::cout << a.Modulus() <<"\n";


  if (a == b)
    std::cout << "\nTrue\n";
  else
    std::cout << "\nFalse\n";


  //std::cout << a.Modulus();

  //a.CPrint();

  std::cout << a.PPow(3);

  std::cout << "\n";

  std::cin >> a;
  

  return 0;
}