#include <iostream>

using namespace std;

class soSimple
{
private:
    int num;

public:
    soSimple(int n) : num(n) {}
    soSimple& addNum(int n)
    {
        num += n;
        return *this;
    }

    void showData() const
    {
        cout << "num : " << num << endl;
    }
};

int main()
{
    const soSimple obj(7);
    // obj.addNum(20);
    obj.showData();
    return 0;
}