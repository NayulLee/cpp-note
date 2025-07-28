#include <iostream>

using namespace std;

class CountryArea
{
public:
    // static 상수의 경우 클래스 내부에서 초기화가 가능하다.
    const static int RUSSIA = 1707540;
    const static int CANADA = 998467;
    const static int CHINA = 957290;
    const static int KOREA = 9922;
};

int main()
{
    cout << "러시아 면적 : " << CountryArea::RUSSIA << "km^2" << endl;
    cout << "캐나다 면적 : " << CountryArea::CANADA << "km^2" << endl;
    cout << "중국 면적 : " << CountryArea::CHINA << "km^2" << endl;
    cout << "한국 면적 : " << CountryArea::KOREA << "km^2" << endl;

    return 0;
}