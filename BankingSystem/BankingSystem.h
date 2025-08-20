#ifndef __BANKINGSYSTEM_H__
#define __BANKINGSYSTEM_H__

// consexpr : 무조건 컴파일 타임에 값이 결정되는 상수임을 보장한다.
constexpr  int NAME_LEN = 20;

// 프로그램 사용자 선택 메뉴
enum{MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

// 신용등급
enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};

// 계좌의 종류
enum{NOMAL = 1, CREDIT = 2};

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

    void Deposit (int money) override 
    {
        Account::Deposit(money); // 원금 추가
        Account::Deposit(money *(interRate/100.0));  // 이자 추가
    }
};

// Entity클래스 HighCreditAccount
class HighCreditAccount : public Account
{
private:
    
}

#endif