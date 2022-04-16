#include "Complex.h"


int main()
{
  
  TComplex a(sqrt(3), 1);
  TComplex b(2, 1);
  TComplex c(-1, 10);

  std::cout << a;

  /*double angle = atan(a.GetIm() / a.GetRe());
  std::cout << angle <<"\n\n";*/

  TComplex d = a / b;
  d.CPrint();

  a = b + c;

  a.Pow(6);
  a.Modulus();

  //a.CPrint();

  if (a == b)
    std::cout << "\nFFFFF\n";
  else
    std::cout << "\nAAAAAf\n";


  //std::cout << a.Modulus();

  //a.CPrint();

  std::cout << a;



  

  return 0;
}