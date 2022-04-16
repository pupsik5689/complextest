#pragma once
#include <iostream>
#include <math.h>
#define M_PI       3.14159   // pi

class TComplex
{
public:
  TComplex();
  TComplex(float _re, float _im);
  ~TComplex();


  TComplex operator+(TComplex &other);
  TComplex operator-(TComplex &other);
  TComplex operator*(TComplex &other);
  TComplex operator/(TComplex &other);
  TComplex& operator=(const TComplex& other);
  bool operator==(TComplex &other);
  friend std::istream& operator>>(std::istream& istr, TComplex &other);
  friend std::ostream& operator<<(std::ostream& str, const TComplex &other);
  

  float GetRe();
  float GetIm();


  void SetRe(float _re);
  void SetIm(float _im);


  void CPrint();
  float Modulus();


  TComplex Pow(float n);



protected:

  float re;
  float im;

};