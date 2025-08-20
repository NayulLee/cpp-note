#ifndef __BANKINGSYSTEM_H__
#define __BANKINGSYSTEM_H__

// consexpr : 무조건 컴파일 타임에 값이 결정되는 상수임을 보장한다.
constexpr  int NAME_LEN = 20;

enum{MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

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
    void Deposit(int money);
    int Withdraw(int money);
    void showAccInfo() const;
    ~Account();
};

class AccountHandler
{   // 컨트롤 클래스 AccountHandler
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

#endif