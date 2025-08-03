#include <iostream>

using namespace std;

class Base
{
public:
    virtual void print(void) const
    {
        cout << "In the Base" << endl;
    }
};


class Drived : public Base
{
public:
    // Override
    void print(void) const
    {
        cout << "In the Drived" << endl;
    }
};
/* 
메모리 시작지점부터 Base클래스를 위한 메모리 구역이 먼저 할당되고
파생 클래스들을 위한 메모리 구역이 추가로 할당되게 된다.
*/
int main()
{
    Base* base_ptr = new Base();
    base_ptr->print();
    delete base_ptr;

    Drived* derived_prt = new Drived();
    derived_prt->print();
    delete derived_prt;

    Base* drived_ptr1 = new Drived();
    drived_ptr1->print();

    return 0;
}