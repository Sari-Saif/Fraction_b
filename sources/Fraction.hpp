/**
 *declare about the structure program
 *@author Sari Safe
 *@since 16.04.23
 */

// to dont include the header alot, once at most
#pragma once

#include <iostream>

using std::istream, std::ostream;
namespace ariel
{

  class Fraction
  {
  private:
    int _numerator;
    int _denominator;
    /*greatest common divisor of the original values of two integeres.*/
    int GCD(int, int);

  public:
    // help function
    void simplify();
    // getters
    int getNumerator() const;
    int getDenominator() const;

    /*ctor*/
    Fraction(int, int);
    Fraction();
    // convert float to fraction
    Fraction Float_to_Fraction(float);
    /* istream and ostream */
    friend ostream &operator<<(ostream &, const Fraction &);
    friend istream &operator>>(istream &, Fraction &);
    /*
      addition of tow objacts (Fractions)
    */
    Fraction operator+(const Fraction &);
    /*
      additon Fraction and flaot(Fractoin+float)
    */
    friend Fraction operator+(const Fraction &, float);
    /*
      additon Fraction and flaot(float+Fractoin)
    */
    friend Fraction operator+(float, const Fraction &);
    /*
      subtraction two Fractions
    */
    Fraction operator-(const Fraction &);
    /*
     subtraction float and Fraction(Fractoin-float)
    */
    friend Fraction operator-(float, const Fraction &);
    /*
     subtraction float and Fraction(float-Fractoin)
    */
    friend Fraction operator-(const Fraction &, float);
    /*
     multiply two Fractions
    */
    Fraction operator*(const Fraction &);
    /*
      multiply float and Fraction(Fractoin*float) - there no exist in demo examples
    */
    friend Fraction operator*(float, const Fraction &);
    /*
     multiply float and Fraction(float*Fractoin) - there no exist in demo examples
    */
    friend Fraction operator*(const Fraction &, float);
    /*
      divison two Fractions
     */
    Fraction operator/(const Fraction &);
    /*
      divison float and Fraction(Fractoin/float)
     */
    friend Fraction operator/(float, const Fraction &);
    /*
      divison float and Fraction(float/Fractoin)
    */
    friend Fraction operator/(const Fraction &, float);
    /*
     equallity two Fractions
    */
    bool operator==(const Fraction &) const;
    /*
      equallity float and Fraction(Fractoin == float)
    */
    friend bool operator==(float, const Fraction &);
    /*
      equallity float and Fraction(float == Fractoin)
    */
    friend bool operator==(const Fraction &, float);
    /*
      less than float and Fraction(Fractoin < Fractoin)
    */
    bool operator<(const Fraction &);
    /*
      less than float and Fraction(Fractoin< float)
    */
    friend bool operator<(const Fraction &, float);
    /*
      less than float and Fraction(float <Fractoin)
    */
    friend bool operator<(float, const Fraction &);
    /*
      less than or equal Fractoin and Fraction(Fracion<=Fractoin)
    */
    bool operator<=(const Fraction &);
    /*
      less than or equal float and Fraction(float<=Fractoin)
    */
    friend bool operator<=(float, const Fraction &);
    /*
      less than or equal float and Fraction(Fractoin<=float)
    */
    friend bool operator<=(const Fraction &, float);
    /*
      greater Fractoin and Fractoin(Fractoin<Fractoin)
    */
    bool operator>(const Fraction &);
    /*
      greater float and Fractoin(float<Fractoin)
    */
    friend bool operator>(float, const Fraction &);
    /*
      greater Fractoin and float(float>Fractoin)
    */
    friend bool operator>(const Fraction &, float);
    /*
      greater than or equal Fractoin and float(float=>Fractoin)
     */
    bool operator>=(const Fraction &);
    /*
      greater than or equal Fractoin and float(float=>Fractoin)
     */
    friend bool operator>=(float, const Fraction &);
    /*
      greater than or equal Fractoin and float(Fractoin=>float)
     */
    friend bool operator>=(const Fraction &, float);
    /*
     increment Fractoin(Fractior++)
   */
    Fraction operator++(int);
    /*
     increment Fractoin(++Fractior)
   */
    Fraction &operator++();
    /*
      decrement Fractoin(Fractior--)
    */
    Fraction operator--(int);
    /*
      decrement Fractoin(--Fractior)
    */
    Fraction &operator--();
  };

};
