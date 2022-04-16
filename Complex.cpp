#include "Complex.h"
#define PI 3.14159265

TComplex::TComplex()
{
  re = 0;
  im = 0;
}

TComplex::TComplex(float _re, float _im)
{
  re = _re;
  im = _im;
}

TComplex::~TComplex()
{
}





TComplex TComplex::operator+(TComplex & other)
{
  return TComplex(re + other.re, im + other.im);
}

TComplex TComplex::operator-(TComplex & other)
{
  return TComplex(re - other.re, im - other.im);
}

TComplex TComplex::operator*(TComplex & other)
{
  int z = 0;
  return TComplex(re * other.re - im * other.im, re * other.im + im * other.re);
}

TComplex TComplex::operator/(TComplex & other)
{
  return TComplex((re * other.re + im * other.im)/( other.re * other.re + other.im * other.im), (im * other.re - re * other.im) / (other.re * other.re + other.im * other.im));
}

TComplex& TComplex::operator=(const TComplex& other)
{
  re = other.re;
  im = other.im;
  return *this;
}


bool TComplex::operator==(TComplex &other)
{
  return ((re == other.re) && (im == other.im));
}






float TComplex::GetRe()
{
  return re;
}

float TComplex::GetIm()
{
  return im;
}



void TComplex::SetRe(float _re)
{
  re = _re;
}

void TComplex::SetIm(float _im)
{
  im = _im;
}








void TComplex::CPrint()
{
  char znak = '+';
  if (im >= 0)
  {
    std::cout << re << " + " << im << "i";
  }
  else
  {
    std::cout << re << im << "i";
  }
}

float TComplex::Modulus()
{
  return sqrt(re * re + im * im);
}

TComplex TComplex::Pow(float n)
{
  float r = sqrt(re * re + im * im);
  float angle = atan2(im, re);
  angle = angle * n;
  std::cout << sin(angle);
  re = pow(r, n) * cos(angle);
  im = pow(r, n) * (sin(angle));
  return TComplex(re, im);
}

std::istream & operator>>(std::istream & istr, TComplex & other)
{
  istr >> other.re;
  istr >> other.im;
  return istr;
}

std::ostream & operator<<(std::ostream & str, const TComplex & other)
{
  str << "Re=" << other.re << " ";
  str << "Im=" << other.im << " ";
  return str;
}
