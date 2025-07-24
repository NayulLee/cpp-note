// 명함을 의미하는 nameCard 클래스를 정의해 보자.
#include <iostream>
#include <cstring>

using namespace std;

enum class COMP_POS{CLERK, SENIOR, ASSIST, MANAGER}; // 사원, 주임, 대리, 과장

class NameCard
{
private:
    char* name;
    char* company;
    char* phone;
    COMP_POS position;   // enum class 타입 그대로 저장한다.

public:

    NameCard(const char* n, const char* c, const char* p, COMP_POS pos)
    {
       name = new char[strlen(n) + 1];
       strcpy(name, n);
       company = new char[strlen(c) + 1];
       strcpy(company, c);
       phone = new char[strlen(p) + 1];
       strcpy(phone, p);

       position = pos;
    }

    NameCard(const NameCard& ref)   // 생성자 내부에서 동적할당하고 있기 때문에 복사생성자 필수
    {
        name = new char[strlen(ref.name) + 1];
        strcpy(name, ref.name);
        company = new char[strlen(ref.company) + 1];
        strcpy(company, ref.company);
        phone = new char[strlen(ref.phone) + 1];
        strcpy(phone, ref.phone);

        position = ref.position;
    }

    void showNameCardInfo() const
    {
        cout << "이름 : " << name << endl;
        cout << "회사 : " << company << endl;
        cout << "전화번호 : " << phone << endl;
        cout << "직급 : ";
        switch(position){
            case COMP_POS::CLERK: cout << "사원"; break;
            case COMP_POS::SENIOR: cout << "주임"; break;
            case COMP_POS::ASSIST: cout << "대리"; break;
            case COMP_POS::MANAGER: cout << "과장"; break;
        };
        cout << endl;
    }
};

int main()
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSenior;
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.showNameCardInfo(); cout << endl;
    manSenior.showNameCardInfo(); cout << endl;
    manAssist.showNameCardInfo(); cout << endl;

    cout << "-----복사생성자로 만든 객체 출력-----" << endl;
    copy1.showNameCardInfo(); cout << endl;
    copy2.showNameCardInfo();
    return 0;
}