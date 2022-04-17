#include "Complex.h"


TComplex::TComplex()
{
  re = 0;
  im = 0;
}

TComplex::TComplex(double _re, double _im)
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






double TComplex::GetRe()
{
  return re;
}

double TComplex::GetIm()
{
  return im;
}



void TComplex::SetRe(double _re)
{
  re = _re;
}

void TComplex::SetIm(double _im)
{
  im = _im;
}








void TComplex::CPrint()
{
  char znak = '+';
  if (im >= 0)
  {
    std::cout << re << " + " << im << " * i";
  }
  else
  {
    std::cout << re << im << "i";
  }
}

double TComplex::Modulus()
{
  return sqrt(re * re + im * im);
}

TComplex TComplex::Pow(double n)
{
  double r = sqrt(re * re + im * im);
  double angle = atan2(im, re);
  angle = angle * n;
  std::cout << sin(angle);
  re = 0; im = 0;
  re = pow(r, n) * cos(angle);
  im = pow(r, n) * sin(angle);
  return *this;
}



double TComplex::Arg()
{
  double arctan = std::atan(im / re);
  double ar = arctan;
  if (re < 0)
  {
    if (im > 0)
    {
      ar = M_PI - arctan;
    }
    else
    {
      ar = -M_PI + arctan;
    }
  }
  else if (re > 0)
  {
    if (im < 0)
    {
      ar = -arctan;
    }
  }
  return ar;
}

TComplex TComplex::PPow(double n)
{
  TComplex tmp(0, 0);
  double m = this->Modulus();
  double a = this->Arg();
  tmp.re = pow(m, n)*cos(a*n);
  tmp.im = pow(m, n)*sin(a*n);

  if ((tmp.re < 0.0000001) && (tmp.re > -0.0000001))
    tmp.re = 0;

  if ((tmp.im < 0.0000001) && (tmp.im > -0.0000001))
    tmp.im = 0;


  return tmp;
}

void TComplex::PrintTrig()
{
  std::cout << "z=" << Modulus() << "(cos(" << (this->Arg() / M_PI) * 180 << ") + i*sin(" << (Arg() / M_PI) * 180 << "))\n";
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
