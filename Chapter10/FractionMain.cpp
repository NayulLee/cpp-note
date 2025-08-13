#include "Fraction.h"
#include <iostream>

int main()
{
    Fraction fraction1;
    Fraction fraction2(14, 21);
    Fraction fraction3(11, -8);
    Fraction fraction4(fraction3);

    std::cout << "---Printing 4 fractions---" << std::endl;
    std::cout << "fraction1 : ";
    fraction1.print();

    std::cout << "fraction2 : ";
    fraction2.print();

    std::cout << "fraction3 : ";
    fraction3.print();

    std::cout << "fraction4 : ";
    fraction4.print();

    return 0;
}