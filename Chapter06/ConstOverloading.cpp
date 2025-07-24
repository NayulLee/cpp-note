#include <iostream>
using namespace std;

class soSimple
{
private:
    int num;

public:
    soSimple(int n) : num(n) 
    {
        // empty
    }

    soSimple& addNum(int n)
    {
        num += n;
        return *this;
    }

    void simpleFunc()
    {
        cout << "simpleFunc : " << num << endl;
    }

    void simpleFunc() const
    {
        cout << "const simpleFunc : " << num << endl;
    }
};

void yourFunc(const soSimple& obj)
{
    obj.simpleFunc();
}

int main()
{
    soSimple obj1(2);
    const soSimple obj2(7);

    obj1.simpleFunc();
    obj2.simpleFunc();

    yourFunc(obj1);
    yourFunc(obj2);
    return 0;
}