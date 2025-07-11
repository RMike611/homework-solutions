#include <iostream>
#include "rational.h"

using namespace std;

Rational::Rational(int numerator, int denominator)
{
    n = numerator;
    d = denominator;
}

Rational Rational::add(const Rational& add)
{
    Rational a;

    a.n = add.n * d + add.d * n;
    a.d = add.d * d;
    a.reducedFraction();

    return a;
}

Rational Rational::subtract(const Rational& subtract)
{
    Rational s;

    s.n = subtract.d * n - d * subtract.n;
    s.d = subtract.d * d;
    s.reducedFraction();

    return s;
}

Rational Rational::multiply(const Rational& M)
{
    Rational m;

    m.n = M.n * n;
    m.d = M.d * d;
    m.reducedFraction();

    return m;
}

Rational Rational::divide(Rational& D)
{
    Rational div;

    div.n = D.d * n;
    div.d = d * D.n;
    div.reducedFraction();

    return div;
}

void Rational::printRational(void)
{
    if (d == 0)
        cout << "\nCan't divde by 0" << '\n';
    else if (n == 0)
        cout << 0;
    else
        cout << n << "/" << d;
}

void Rational::printFloatingrational(void)
{
    cout << (double)n / d;
}

void Rational::reducedFraction(void)
{
    int largest;

    if (n > d)
        largest = n;
    else
        largest = d;

    int GCD = 0;

    for (int i = 2; i <= largest; i++)
        if (n % i == 0 && d % i == 0)
            GCD = i;

    if (GCD != 0)
    {
        n /= GCD;
        d /= GCD;
    }
}
