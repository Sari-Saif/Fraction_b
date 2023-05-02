/**
 *declare about implemention and logic of the structure  program
 *@author Sari Safe
 *@since 16.04.23
 */

#include <iostream>
#include <stdexcept>
#include "Fraction.hpp"
using std::ostream, std::istream, std::endl, std::cout;

namespace ariel
{

    Fraction::Fraction(int numerator,
                       int denominator) : _numerator(numerator), _denominator(denominator)
    {
        // possibility div by 0 !
        if (_denominator == 0)
        {
            throw std::runtime_error(" cannot be 0 .");
        }
        // simplify the fraction
        simplify();
    }
    Fraction::Fraction() : _numerator(1), _denominator(1){

                                          };
    Fraction::Fraction(float value) : Fraction((value * 1000), 1000)
    {
    }
    // getters
    int Fraction::getNumerator() const
    {
        return _numerator;
    }
    int Fraction::getDenominator() const
    {
        return _denominator;
    }

    /**
     * @param input two integeres(num_0, num_1)
     * @param return gcd(num_0,num_1)
     */
    int Fraction::GCD(int num_0, int num_1) const
    {

        if (num_0 == 0)
        {
            return num_1;
        }
        if (num_1 == 0)
        {
            return num_0;
        }
        while (num_1 != 0)
        {
            int temp = num_1;
            num_1 = num_0 % num_1;
            num_0 = temp;
        }
        return num_0;
    }

    void Fraction::simplify()
    {
        int gcd = GCD(_numerator, _denominator);
        _numerator /= gcd;
        _denominator /= gcd;
    }

    // must pass the stream by reference, not by value. streams are not copyable
    ostream &operator<<(ostream &out, Fraction &other)
    {
        if (typeid(other) != typeid(Fraction))
        {
            throw std::invalid_argument("Err");
        }
        out << other._numerator << "/" << other._denominator;
        return out;
    }

    istream &operator>>(istream &into, Fraction &other)
    {
        // temporary parameters
        other._denominator == 1;
        other._numerator == 1;
        into >> other._numerator >> other._denominator;
        if (other._denominator == 1)
        {
            into.clear();
            throw std::invalid_argument("there need two parameters to absorb to build a fractoin ");
        }
        return into;
    }

    Fraction Fraction::operator+(Fraction other)
    {
        // default state and dont need of default constructor :)
        Fraction result(0, 1);
        result._numerator = (this->_numerator * other._denominator) + (this->_denominator * other._numerator);
        result._denominator = (this->_denominator * other._denominator);
        result.simplify();
        return result;
    }

    Fraction operator+(float j, Fraction frac)
    {
        Fraction a = Fraction(j);
        int num = frac.getDenominator() * a.getNumerator() + frac.getNumerator() * a.getDenominator();
        int den = frac.getDenominator() * a.getDenominator();
        return Fraction(num, den);
    }

    Fraction operator+(Fraction frac, float j)
    {
        Fraction a = Fraction(j);
        int num = frac.getDenominator() * a.getNumerator() + frac.getNumerator() * a.getDenominator();
        int den = frac.getDenominator() * a.getDenominator();
        return Fraction(num, den);
    }

    // here we use the + operator to subscracts
    Fraction Fraction::operator-(Fraction frac)
    {
        int num = this->_numerator * frac.getDenominator() - frac.getNumerator() * this->_denominator;
        int den = frac.getDenominator() * this->_denominator;
        return Fraction(num, den);
    }

    Fraction operator-(float num, Fraction frac)
    {
        return Fraction(num) - frac;
    }

    Fraction operator-(Fraction other, float num)
    {

        return other - Fraction(num);
    }

    Fraction Fraction::operator*(Fraction other)
    {
        // default state and dont need of default constructor :)
        Fraction result(0, 1);
        result._numerator = (this->_numerator * other._numerator);
        result._denominator = (this->_denominator * other._denominator);
        result.simplify();
        return result;
    }

    Fraction operator*(float num, Fraction frac)
    {
        Fraction a = Fraction(num);
        a.simplify();
        int ner = a.getNumerator() * frac._numerator;
        int det = a.getDenominator() * frac._denominator;

        // 1. here we can be confidence that there no divided  with 0
        return Fraction(ner, det);
    }

    Fraction operator*(Fraction frac, float num)
    {
        Fraction a = Fraction(num);
        a.simplify();
        int ner = a.getNumerator() * frac.getNumerator();
        int det = a.getDenominator() * frac.getDenominator();
        // 1. here we can be confidence that there no divided  with 0
        return Fraction(ner, det);
    }

    Fraction Fraction::operator/(Fraction other)
    {
        if (other._numerator == 0)
        {
            throw std::runtime_error(" cannot be 0 .");
        }

        // using something already done.
        // 1. here too.
        // We turned the fraction (from the denominator in the numerator) then the multiplied
        return this->operator*(Fraction(other._denominator, other._numerator));
    }

    Fraction operator/(float num, Fraction frac)
    {
        if (frac._numerator == 0)
        {
            throw std::runtime_error(" cannot be 0 .");
        }

        // 1. here too.

        return Fraction(num) * Fraction(frac._denominator, frac._numerator);
    }

    Fraction operator/(Fraction frac, float num)
    {
        if (num == 0)
        {
            throw std::runtime_error(" cannot be 0 .");
            ;
        }

        return (Fraction(frac._numerator, frac._denominator) / Fraction(num));
    }

    bool Fraction::operator==(Fraction other)
    {
        float num_0 = ((float)this->_numerator / (float)this->_denominator);
        float num_1 = ((float)other.getNumerator() / (float)other.getDenominator());
        return num_0 == num_1;
    }

    bool operator==(float num, Fraction frac)
    {
        float num_0 = ((float)frac.getNumerator() / (float)frac.getDenominator());
        return (num == num_0);
    }

    bool operator==(Fraction frac, float num)
    {
        float num_0 = ((float)frac.getNumerator() / (float)frac.getDenominator());
        return (num_0 == num);
    }

    bool Fraction::operator<(Fraction other)
    {
        if (this->_numerator == other.getNumerator())
        {
            return this->_denominator > other.getDenominator(); // must be true , satisfied answer .
        }
        return ((float)(this->_numerator / this->_denominator)) < ((float)(other.getNumerator() / other.getDenominator()));
    }

    bool operator<(Fraction frac, float num)
    {
        float num_1 = ((float)frac.getNumerator() / ((float)frac.getDenominator()));
        cout << num_1 << endl;
        return num_1 < num;
    }

    bool operator<(float num, Fraction frac)
    {
        float num_1 = (((float)frac.getNumerator() / (float)frac.getDenominator()));
        return num < num_1;
    }

    bool Fraction::operator<=(Fraction other)
    {
        if (this->_numerator == other.getNumerator())
        {
            return this->_denominator >= other.getDenominator(); // must be true , satisfied answer .
        }
        else if (this->_numerator == other.getNumerator() && this->_denominator == other.getDenominator())
        {
            return true;
        }
        else
        {
            return (((float)this->_numerator / (float)this->_denominator)) <= ((float)other.getNumerator() / (float)other.getDenominator());
        }
    }

    bool operator<=(Fraction frac, float num)
    {

        return (frac <= Fraction(num));
    }

    bool operator<=(float num, Fraction frac)
    {

        return Fraction(num) <= frac;
    }

    bool Fraction::operator>(Fraction other)
    {
        if (this->_numerator == other.getNumerator())
        {
            return this->_denominator < other.getDenominator();
        }
        return (((float)this->_numerator / (float)this->_denominator)) > ((float)other.getNumerator() / (float)other.getDenominator());
    }

    bool operator>(Fraction frac, float num)
    {

        return frac > Fraction(num);
    }

    bool operator>(float num, Fraction frac)
    {

        return Fraction(num) > frac;
    }

    bool Fraction::operator>=(Fraction other)
    {
        if (this->_numerator == other.getNumerator() && this->_denominator == other.getDenominator())
        {
            return true;
        }
        else if (this->_numerator == other.getNumerator())
        {
            return this->_denominator < other.getDenominator(); // must be true , satisfied answer .
        }

        else
        {
            return ((float)this->_numerator / (float)this->_denominator) >= ((float)other.getNumerator() / (float)other.getDenominator());
        }
    }

    bool operator>=(Fraction frac, float num)
    {

        return (frac >= Fraction(num));
    }

    bool operator>=(float num, Fraction frac)
    {
        return (Fraction(num) >= frac);
    }

    Fraction &Fraction::operator--()
    {
        _numerator -= _denominator;
        simplify();
        return *this;
    }
    Fraction Fraction::operator--(int dumy_flag_for_increment)
    {
        //_numerator += _denominator;
        Fraction min_copy(*this);
        _numerator -= _denominator;
        // simplify();
        return min_copy;
    }
    Fraction Fraction ::operator++(int dumy_flag_for_increment)
    {
        //_numerator += _denominator;
        Fraction p_copy(*this);
        _numerator += _denominator;
        // simplify();
        return p_copy;
    }

    Fraction &Fraction::operator++()
    {

        _numerator += _denominator;
        simplify();
        return *this;
    }
};
