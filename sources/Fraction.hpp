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
    int GCD(int, int) const;

  public:
    // help function
    void simplify();
    // getters
    int getNumerator() const;
    int getDenominator() const;

    /*ctor's*/
    Fraction(int, int);
    Fraction();
    // convert float to fraction
    Fraction(float);

    /* istream and ostream */
    friend ostream &operator<<(ostream &, const Fraction &);
    friend istream &operator>>(istream &, Fraction &);

    /*
    subtraction two Fractions
    */
    Fraction operator-(Fraction);
    /*
    greater than or equal Fractoin and float(float=>Fractoin)
    */
    bool operator>=(Fraction);
    /*
    greater Fractoin and Fractoin(Fractoin<Fractoin)
    */
    bool operator>(Fraction);
    /*
      addition of tow objacts (Fractions)
    */
    Fraction operator+(Fraction);
    /*
     multiply two Fractions
    */
    Fraction operator*(Fraction);
    /*
      less than or equal Fractoin and Fraction(Fracion<=Fractoin)
    */
    bool operator<=(Fraction);
    /*
      divison two Fractions
     */
    Fraction operator/(Fraction);
    /*---------------------------------------------------------RIGHT-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*
    multiply float and Fraction(float*Fractoin) - there no exist in demo examples
    */
    friend Fraction operator*(Fraction, float);
    /*
      additon Fraction and flaot(Fractoin+float)
    */
    friend Fraction operator+(Fraction, float);
    /*
     subtraction float and Fraction(float-Fractoin)
    */
    friend Fraction operator-(Fraction, float);
    /*
      equallity float and Fraction(float == Fractoin)
    */
    friend bool operator==(Fraction, float);
    /*
      less than float and Fraction(Fractoin< float)
    */
    friend bool operator<(Fraction, float);
    /*
      greater than or equal Fractoin and float(Fractoin=>float)
     */
    friend bool operator>=(Fraction, float);
    /*
      greater Fractoin and float(float>Fractoin)
    */
    friend bool operator>(Fraction, float);
    /*
      less than or equal float and Fraction(Fractoin<=float)
    */
    friend bool operator<=(Fraction, float);
    /*
      divison float and Fraction(float/Fractoin)
    */
    friend Fraction operator/(Fraction, float);
    /*---------------------------------------------LEFT-----------------------------------------------------------------------------------*/
    /*
      additon Fraction and flaot(float+Fractoin)
    */
    friend Fraction operator+(float, Fraction);

    /*
     subtraction float and Fraction(Fractoin-float)
    */
    friend Fraction operator-(float, Fraction);
    /*
      multiply float and Fraction(Fractoin*float) - there no exist in demo examples
    */
    friend Fraction operator*(float, Fraction);
    /*
      divison float and Fraction(Fractoin/float)
     */
    friend Fraction operator/(float, Fraction);
    /*
     equallity two Fractions
    */
    bool operator==(Fraction) const;
    /*
      equallity float and Fraction(Fractoin == float)
    */
    friend bool operator==(float, Fraction);
    /*
      less than float and Fraction(Fractoin < Fractoin)
    */
    bool operator<(Fraction);
    /*
      less than float and Fraction(float <Fractoin)
    */
    friend bool operator<(float, Fraction);
    /*
      less than or equal float and Fraction(float<=Fractoin)
    */
    friend bool operator<=(float, Fraction);
    /*
      greater float and Fractoin(float<Fractoin)
    */
    friend bool operator>(float, Fraction);
    /*
      greater than or equal Fractoin and float(float=>Fractoin)
     */
    friend bool operator>=(float, Fraction);

    /*----------------------------------------------------------------------------------------------------------------------*/

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
