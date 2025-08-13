#ifndef __FRACTION_H__
#define __FRACTION_H__

class Fraction
{
private:
    int numer;
    int denom;

public:
    Fraction(int num, int den = 1);
    Fraction();
    Fraction(const Fraction& fract);
    ~Fraction();

    // getter
    int getNum() const;
    int getDenom() const;
    void print() const;

    // setter
    void setNumer(int num);
    void setDenom(int den);

    // private 보조 멤버 함수
private:
    void normalize();   // gcd이용하여 불변 속성 처리
    int gcd(int n, int m); // gcd:최대공약수    
};

#endif