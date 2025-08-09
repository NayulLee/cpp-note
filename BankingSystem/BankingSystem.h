#ifndef __BANKINGSYSTEM_H__
#define __BANKINGSYSTEM_H__

// consexpr : 무조건 컴파이랕임에 값이 결정되는 상수임을 보장한다.
constexpr  int NAME_LEN = 20;

void showMenu(void);        // 메뉴 출력
void makeAccount(void);     // 계좌 개설
void depositMoney(void);     // 입금
void withdraqMoney(void);     // 출금
void showAllAccInfo(void);      // 잔액조회

enum{MAKE = 1, DEPOSIT, WITHDROW, EXIT};

class Account
{
private:
    int accID;
    int balance;
    char* cusName;

public:
    Account(int ID, int money, char* name);
    int getID();
    void Deposit(int money);
    int Withdraw(int money);
    void showAccInfo() const;
    ~Account();
};






#endif