#include <iostream>
using namespace std;

class SoSimple
{
public:
    static int simObjCnt;

public:
    SoSimple()
    {
        simObjCnt++;
    }
};
int SoSimple::simObjCnt = 0;

int main()
{
    cout << SoSimple::simObjCnt<<"번째 SoSimple 객체" << endl;
    SoSimple sim1; // 생성자 호출되면서 simObjCnt++;
    SoSimple sim2; // 생성자 호출되면서 simObjCnt++;

    cout << SoSimple::simObjCnt<<"번째 SoSimple 객체" << endl;
    // 멤버 변수에 접근하는것과 같은 오해를 불러 일으키기 때문에, 
    // public static 멤버에 접근할 때에는 클래스 이름을 이용하여 접근하는 것이 좋다.
    cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;
    cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;
    return 0;
}