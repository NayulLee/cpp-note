#include <iostream>
#include <cmath>
#include <cassert>
#include "Fraction.h"

Fraction::Fraction(int num, int den) : numer(num), denom(den)
{
    normalize();
}

Fraction::Fraction() : numer(0), denom(1)
{
    // empty
}

Fraction::Fraction(const Fraction& fract) : numer(fract.numer), denom(fract.denom)
{
    // empty
}

Fraction::~Fraction()
{
    // empty
}

int Fraction::getNum() const
{
    return numer;
}

int Fraction::getDenom() const
{
    return denom;
}

void Fraction::print() const
{
    std::cout << numer << "/" << denom << std::endl;
}

void Fraction::setNumer(int num)
{
    numer = num;
    normalize();
}

void Fraction::setDenom(int den)
{
    denom = den;
    normalize();
}

// normalize() : 3가지 작업을 통해 분수를 약분한다.
void Fraction::normalize()
{
    // 분모가 0인지 검사
    if(denom == 0)
    {
        std::cout << "잘못된 분모 값입니다. 프로그램을 중단합니다." << std::endl;
        assert(false);
    }

    // 분모가 음수 : 분자와 분모 부호 변경
    if (denom < 0)
    {
        denom = -denom;
        numer = -numer;
    }

    // 최대공약수로 분자와 분모 나누기
    int divisor = gcd(abs(numer), abs(denom));
    numer = numer / divisor;
    denom = denom / divisor;
}

// gcd : 최대공약수 
int Fraction::gcd(int n, int m)
{
    int gcd = 1;
    for(int k = 1; k <= n && k <= m; k++)
    {
        if(n % k == 0 && m % k == 0)
        {
            gcd = k;
        }
    }
    return gcd;
}
