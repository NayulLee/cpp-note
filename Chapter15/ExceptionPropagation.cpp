#include <iostream>

void funcB()
{
    throw std::runtime_error("B에서 예외 발생");
}

void funcA()
{
    funcB();    // 예외 처리 안함 → 호출자에게 전파
}

int main()
{
    try{
        funcA();
    }
    catch(const std::exception& e){
        std::cout << "잡힌 예외 : " << e.what() << std::endl;
    }
}