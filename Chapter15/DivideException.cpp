/* divide(int a, int b) 함수에서 b == 0이면 std::runtime_error를 던지고, 
main()에서 예외를 잡아 처리하라.*/

#include <iostream>
#include <stdexcept>

int divide(const int a, const int b);

int main()
{
    int num1, num2;
    std::cout << "num1 >> ";
    std::cin >> num1;
    std::cout << "num2 >> ";
    std::cin >> num2;

    try{
        int result = divide(num1, num2);
        std::cout << "Divide result : " << result << std::endl;
    }
    catch(const std::runtime_error& e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}

int divide(const int a, const int b)
{
    if(b == 0) throw std::runtime_error("error : input 0");

    return a / b;
}