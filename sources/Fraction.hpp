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
    /**
     * gcd function : greatest common divisor of the original values of two integeres.
     * @param input two integeres(num_0, num_1)
     * @param return gcd(num_0,num_1)
     *
     */
    int GCD(int, int) const;

  public:
    /*ctor's*/
    Fraction(int, int);
    Fraction();
    // convert float to fraction
    Fraction(float);

    // help function
    void simplify();
    // getters
    int getNumerator() const;
    int getDenominator() const;

    /* istream and ostream */
    friend ostream &operator<<(ostream &, Fraction &);
    friend istream &operator>>(istream &, Fraction &);

    /*
    subtraction two Fractions
    */
    friend Fraction operator-(const Fraction &, const Fraction &);
    /*
    greater than or equal Fractoin and float(float=>Fractoin)
    */
    friend bool operator>=(const Fraction &, const Fraction &);
    /*
    greater Fractoin and Fractoin(Fractoin<Fractoin)
    */
    friend bool operator>(const Fraction &, const Fraction &);
    /*
      addition of tow objacts (Fractions)
    */
    friend Fraction operator+(const Fraction &, const Fraction &);
    /*
     multiply two Fractions
    */
    friend Fraction operator*(const Fraction &, const Fraction &);
    /*
      less than or equal Fractoin and Fraction(Fracion<=Fractoin)
    */
    friend bool operator<=(const Fraction &, const Fraction &);
    /*
      divison two Fractions
     */
    friend Fraction operator/(const Fraction &, const Fraction &);
    /*---------------------------------------------------------RIGHT-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*
    multiply float and Fraction(float*Fractoin) - there no exist in demo examples
    */
    friend Fraction operator*(const Fraction &, float);
    /*
      additon Fraction and flaot(Fractoin+float)
    */
    friend Fraction operator+(const Fraction &, float);
    /*
     subtraction float and Fraction(float-Fractoin)
    */
    friend Fraction operator-(const Fraction &, float);
    /*
      equallity float and Fraction(float == Fractoin)
    */
    friend bool operator==(const Fraction &, float);
    /*
      less than float and Fraction(Fractoin< float)
    */
    friend bool operator<(const Fraction &, float);
    /*
      greater than or equal Fractoin and float(Fractoin=>float)
     */
    friend bool operator>=(const Fraction &, float);
    /*
      greater Fractoin and float(float>Fractoin)
    */
    friend bool operator>(const Fraction &, float);
    /*
      less than or equal float and Fraction(Fractoin<=float)
    */
    friend bool operator<=(const Fraction &, float);
    /*
      divison float and Fraction(float/Fractoin)
    */
    friend Fraction operator/(const Fraction &, float);
    /*---------------------------------------------LEFT-----------------------------------------------------------------------------------*/
    /*
      additon Fraction and flaot(float+Fractoin)
    */
    friend Fraction operator+(float, const Fraction &);

    /*
     subtraction float and Fraction(Fractoin-float)
    */
    friend Fraction operator-(float, const Fraction &);
    /*
      multiply float and Fraction(Fractoin*float) - there no exist in demo examples
    */
    friend Fraction operator*(float, const Fraction &);
    /*
      divison float and Fraction(Fractoin/float)
     */
    friend Fraction operator/(float, const Fraction &);
    /*
     equallity two Fractions
    */
    friend bool operator==(const Fraction &other0, const Fraction &other1);
    /*
      equallity float and Fraction(Fractoin == float)
    */
    friend bool operator==(float, const Fraction &);
    /*
      less than float and Fraction(Fractoin < Fractoin)
    */
    friend bool operator<(const Fraction &, const Fraction &);
    /*
      less than float and Fraction(float <Fractoin)
    */
    friend bool operator<(float, const Fraction &);
    /*
      less than or equal float and Fraction(float<=Fractoin)
    */
    friend bool operator<=(float, const Fraction &);
    /*
      greater float and Fractoin(float<Fractoin)
    */
    friend bool operator>(float, const Fraction &);
    /*
      greater than or equal Fractoin and float(float=>Fractoin)
     */
    friend bool operator>=(float, const Fraction &);

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
