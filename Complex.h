#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>


class TComplex
{
public:
  TComplex();
  TComplex(double _re, double _im);
  ~TComplex();


  TComplex operator+(TComplex &other);
  TComplex operator-(TComplex &other);
  TComplex operator*(TComplex &other);
  TComplex operator/(TComplex &other);
  TComplex& operator=(const TComplex& other);
  bool operator==(TComplex &other);
  friend std::istream& operator>>(std::istream& istr, TComplex &other);
  friend std::ostream& operator<<(std::ostream& str, const TComplex &other);
  

  double GetRe();
  double GetIm();


  void SetRe(double _re);
  void SetIm(double _im);

  void PrintTrig();


  void CPrint();
  double Modulus();


  TComplex Pow(double n);
  TComplex PPow(double n);

  double Arg();


protected:

  double re;
  double im;

};