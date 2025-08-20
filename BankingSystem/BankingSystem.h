#ifndef __BANKINGSYSTEM_H__
#define __BANKINGSYSTEM_H__

// consexpr : 무조건 컴파일 타임에 값이 결정되는 상수임을 보장한다.
constexpr  int NAME_LEN = 20;

// 프로그램 사용자 선택 메뉴
enum{MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

// 신용등급
enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};

// 계좌의 종류
enum{NORMAL = 1, CREDIT = 2};

// Entity 클래스 'Account'
class Account
{
private:
    int accID;      // 계좌번호
    int balance;    // 잔액
    char* cusName;  // 고객이름

public:
    Account(int ID, int money, char* name);
    Account(const Account& ref);
    int getID() const;
    virtual void Deposit(int money);
    int Withdraw(int money);
    void showAccInfo() const;
    ~Account();
};

// 컨트롤 클래스 'AccountHandler'
class AccountHandler
{   
private:
    Account *accArr[100]; // 최대 100개까지 계좌 생성 가능
    int accNum;

public:
    AccountHandler();
    void showMenu(void) const;
    void makeAccount(void);     // 계좌 개설
    void depositMoney(void);    // 입금
    void withdrawMoney(void);   // 출금
    void showAllAccInfo(void);
    ~AccountHandler();

protected:
    void makeNormalAccount(void);   // 일반 계좌(원금 + 이자)
    void makeCreditAccount(void);   // 신용 계좌(원금 + 이자 + 신용등급에 따른 이자 추가)

};

// Entity 클래스 NormalAccount
class NormalAccount : public Account
{
private:
    int interRate;  // 이자율 %단위

public:
    NormalAccount(int ID, int money, char* name, int rate)
    : Account(ID, money, name), interRate(rate)
    {}

    virtual void Deposit (int money) override 
    {
        Account::Deposit(money); // 원금 추가
        Account::Deposit(money *(interRate/100.0));  // 이자 추가
    }
    /*
        부모 클래스에서 한 번 `virtual`을 붙이면
        - 그 함수는 계속 가상 함수 속성을 유지하기 때문에 자식, 손자클래스에서 
          `virtual` 안붙여도 된다.
        - 대신 재정의시 override는 자식이든 손자든 무조건 붙이자
    */
};

// Entity클래스 HighCreditAccount
class HighCreditAccount : public NormalAccount
{
private:
    int specialRate;

public:
    HighCreditAccount(int ID, int money, char* name, int rate, int special)
        :NormalAccount(ID, money, name, rate), specialRate(special)
        {}
    
        void Deposit(int money) override
        {
            NormalAccount::Deposit(money);  // 원금과 이자 추가
            Account::Deposit(money*(specialRate/100.0)); // special 이자 추가
        }
    
};

#endif