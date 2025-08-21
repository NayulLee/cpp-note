// 템플릿 함수의 특수화를 사용하는 프로그램
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

template<typename T>
T smaller(const T& first, const T& second)
{
    if(first < second)
    {
        return first;
    }
    return second;
}

// 템플릿 함수 특수화
template<>
const char* smaller(const char* const &first, const char* const &second)
{
    /*
    const char* smaller(const char* const &first, const char* const &second)
        - 자료형 앞에 const → 내용(read-only)
        - 포인터 뒤에 const → 포인터 값(read-only)
    const 포인터
        - 포인터가 가리키는 값을 수정할 수 업음
        - 포인터 자체는 다른 주소를 가리킬 수 있음
    포인터 const
        - 포인터 자체를 바꿀 수 없음
        - 가리키는 내용은 수정 가능
    */
    if(strcmp(first, second) < 0)
    {
        return first;
    }
    return second;
}

int main()
{
    string str1 = "Hello";
    string str2 = "Hi";
    cout << "smaller(Hello, Hi) =  " << smaller(str1, str2) << endl;
    // C문자열로 템플릿 함수 호출
    const char* s1 = "Bye";
    const char* s2 = "Bye Bye";
    cout << "smaller(Bye, ByeBye) = " << smaller(s1, s2) << endl;
    return 0;
}