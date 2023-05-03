/**
 *declare about implemention and logic of the structure  program
 *@author Sari Safe
 *@since 16.04.23
 */

#include <iostream>
#include <stdexcept>
#include "Fraction.hpp"
using std::ostream, std::istream, std::endl, std::cout;

using namespace ariel;

Fraction::Fraction(int numerator,
                   int denominator) : _numerator(numerator), _denominator(denominator)
{
    // possibility div by 0 !
    if (_denominator == 0)
    {
        throw std::invalid_argument(" cannot be 0 .");
    }

    // in the case there negative value(negative Fraction) and we want represent him in numerator
    if (_denominator < 0)
    {

        _numerator = -1 * numerator;
        _denominator = -1 * denominator;
    }
    // simplify the fraction
    simplify();
}

// default ctor
Fraction::Fraction() : _numerator(1), _denominator(1){

                                      };

// ctor convert float to Fraction object
Fraction::Fraction(float value) : Fraction((value * 1000), 1000)
{
}

//---------------------------------------------------HELP FUNCTIONS---------------------------------------------------------------------------//

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
 * gcd function
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
//-------------------------------------The Main Function's---------------------------------------------------------------------------------------------------------------------------------//
// must pass the stream by reference, not by value. streams are not copyable
ostream &ariel::operator<<(ostream &out, Fraction &other)
{
    if (typeid(other) != typeid(Fraction))
    {
        throw std::invalid_argument("Err");
    }
    out << other._numerator << "/" << other._denominator;
    return out;
}

istream &ariel::operator>>(istream &into, Fraction &other)
{
    // temporary parameters
    other._denominator = 1;
    other._numerator = 1;
    into >> other._numerator >> other._denominator;
    if (other._denominator == 1)
    {
        into.clear();
        throw std::runtime_error("there need two parameters to absorb to build a fractoin ");
    }
    if (other._denominator == 0)
    {
        into.clear();
        throw std::runtime_error("there need two parameters to absorb to build a fractoin ");
    }
    return into;
}

Fraction ariel::operator+(const Fraction &curr, const Fraction &other)
{
    // default state and dont need of default constructor :)
    Fraction result(0, 1);
    result._numerator = (curr._numerator * other._denominator) + (curr._denominator * other._numerator);
    result._denominator = (curr._denominator * other._denominator);
    result.simplify();
    return result;
}

Fraction ariel::operator+(float number, const Fraction &frac)
{
    Fraction a = Fraction(number);
    int num = frac._denominator * a._numerator + frac._numerator * a._denominator;
    int den = frac._denominator * a._denominator;
    return Fraction(num, den);
}

Fraction ariel::operator+(const Fraction &frac, float number)
{

    Fraction a = Fraction(number);
    int num = frac._denominator * a.getNumerator() + frac._numerator * a.getDenominator();
    int den = frac._denominator * a.getDenominator();
    return Fraction(num, den);
}

// here we use the + operator to subscracts
Fraction ariel::operator-(const Fraction &curr, const Fraction &other)
{
    int num = curr._numerator * other._denominator - other._numerator * curr._denominator;
    int den = other._denominator * curr._denominator;
    return Fraction(num, den);
}

Fraction ariel::operator-(float num, const Fraction &frac)
{
    return Fraction(num) - frac;
}

Fraction ariel::operator-(const Fraction &other, float num)
{

    return other - Fraction(num);
}

Fraction ariel::operator*(const Fraction &curr, const Fraction &other)
{
    // default state and dont need of default constructor :)
    Fraction result(0, 1);
    result._numerator = (curr._numerator * other._numerator);
    result._denominator = (curr._denominator * other._denominator);
    result.simplify();
    return result;
}

Fraction ariel::operator*(float num, const Fraction &frac)
{
    Fraction a = Fraction(num);
    a.simplify();
    int ner = a.getNumerator() * frac._numerator;
    int det = a.getDenominator() * frac._denominator;

    // 1. here we can be confidence that there no divided  with 0
    return Fraction(ner, det);
}

Fraction ariel::operator*(const Fraction &frac, float num)
{
    Fraction a = Fraction(num);
    a.simplify();
    int ner = a.getNumerator() * frac._numerator;
    int det = a.getDenominator() * frac._denominator;
    // 1. here we can be confidence that there no divided  with 0
    return Fraction(ner, det);
}

Fraction ariel::operator/(const Fraction &curr, const Fraction &other)
{
    if (curr._numerator == 0 || other._numerator == 0)
    {
        throw std::runtime_error(" cannot be 0 .");
    }
    int num = curr._numerator * other._denominator;
    int den = curr._denominator * other._numerator;

    return Fraction(num, den);
}

Fraction ariel::operator/(float number, const Fraction &frac)
{
    if (number == 0)
    {
        throw std::runtime_error(" there no divide by zero");
    }
    if (frac._numerator == 0)
    {
        throw std::invalid_argument(" cannot be 0 .");
    }

    Fraction res = Fraction(number) * Fraction(frac._denominator, frac._numerator);
    return res;
}

Fraction ariel::operator/(const Fraction &frac, float num)
{
    if (num == 0)
    {
        throw std::runtime_error(" cannot be 0 .");
    }
    return (Fraction(frac._numerator, frac._denominator) / Fraction(num));
}

bool ariel::operator==(const Fraction &curr, const Fraction &other)
{
    Fraction f1((float)curr._numerator / curr._denominator);
    Fraction f2((float)other._numerator / other._denominator);

    f1.simplify();
    f2.simplify();

    return (curr._numerator == other._numerator) && (curr._denominator == other._denominator);
}

bool ariel::operator==(float num, const Fraction &frac)
{
    float num_0 = ((float)frac._numerator / frac._denominator);
    return (num == num_0);
}

bool ariel::operator==(const Fraction &frac, float num)
{
    float num_0 = ((float)frac._numerator / frac._denominator);
    return (num_0 == num);
}

bool ariel::operator<(const Fraction &curr, const Fraction &other)
{
    if (curr._numerator == other._numerator)
    {
        return curr._denominator > other._denominator; // must be true , satisfied answer .
    }
    return ((float)(curr._numerator / curr._denominator)) < ((float)(other._numerator / other._denominator));
}

bool ariel::operator<(const Fraction &frac, float num)
{
    float num_1 = ((float)frac._numerator / (frac._denominator));
    return num_1 < num;
}

bool ariel::operator<(float num, const Fraction &frac)
{
    float num_1 = (((float)frac._numerator / frac._denominator));
    return num < num_1;
}

bool ariel::operator<=(const Fraction &curr, const Fraction &other)
{
    if (curr._numerator == other._numerator)
    {
        return curr._denominator >= other._denominator; // must be true , satisfied answer .
    }
    else if (curr._numerator == other._numerator && curr._denominator == other._denominator)
    {
        return true;
    }
    else
    {
        return (((float)curr._numerator / curr._denominator)) <= ((float)other._numerator / other._denominator);
    }
}

bool ariel::operator<=(const Fraction &frac, float num)
{

    return (frac <= Fraction(num));
}

bool ariel::operator<=(float num, const Fraction &frac)
{

    return Fraction(num) <= frac;
}

bool ariel::operator>(const Fraction &curr, const Fraction &other)
{
    if (curr._numerator == other._numerator)
    {
        return curr._denominator < other._denominator;
    }
    return (((float)curr._numerator / curr._denominator)) > ((float)other._numerator / other._denominator);
}

bool ariel::operator>(const Fraction &frac, float num)
{

    return frac > Fraction(num);
}

bool ariel::operator>(float num, const Fraction &frac)
{

    return Fraction(num) > frac;
}

bool ariel::operator>=(const Fraction &curr, const Fraction &other)
{
    if (curr._numerator == other._numerator && other._numerator == curr._denominator)
    {
        return true;
    }
    else if (curr._numerator == other._numerator)
    {
        return curr._denominator < other._denominator; // must be true , satisfied answer .
    }

    else
    {
        return ((float)curr._numerator / curr._denominator) >= ((float)other._numerator / other._denominator);
    }
}

bool ariel::operator>=(const Fraction &frac, float num)
{

    return (frac >= Fraction(num));
}

bool ariel::operator>=(float num, const Fraction &frac)
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
