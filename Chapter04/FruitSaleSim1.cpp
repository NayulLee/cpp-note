/*두 클래스의 멤버변수는 private로 선언되어 있다.
그러나 "사과의 구매를 목적으로 0보다 작은 수를 전달할 수 없다"는 조건 추가해 보기.
예제의 안전성을 높일 수 있도록 일부 함수를 const로 선언해 보자.*/

#include <iostream>

using namespace std;

class FruitSeller{
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    void initMembers(int price, int num, int money)
    {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }

    int saleApples(int money)
    {
        int num = money/APPLE_PRICE;
        numOfApples-=num;
        myMoney +=money;
        return num;
    }

    void showSaleResult() const{
        cout << "남은 사과 : " << numOfApples << endl;
        cout << "판매 수익 : " << myMoney << endl;
    }
};

class FruitBuyer
{
    int myMoney;
    int numOfApples;

public:
    void InitMembers(int money)
    {
        myMoney = money;
        numOfApples = 0;
    }

    void BuyApples(FruitSeller &seller, int money)
    {
        if(money <= 0)
        {
            cout << "잘못된 금액입니다" << endl;
            return;
        }
        numOfApples += seller.saleApples(money);
        myMoney -= money;
    }

    void showBuyResult() const
    {
        cout << "현재 잔액 : " << myMoney << endl;
        cout << "사과 개수 : " << numOfApples << endl;
    }
};

int main()
{
    FruitSeller seller;
    seller.initMembers(1000, 20, 0);
    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000);

    cout << "[판매자 현황]" << endl;
    seller.showSaleResult();
    cout << "[구매자 현황] " << endl;
    buyer.showBuyResult();

    return 0;
}