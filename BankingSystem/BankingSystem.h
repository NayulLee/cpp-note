#ifndef __BANKINGSYSTEM_H__
#define __BANKINGSYSTEM_H__

// consexpr : 무조건 컴파일 타임에 값이 결정되는 상수임을 보장한다.
constexpr  int NAME_LEN = 20;

void showMenu(void);        // 메뉴 출력
void makeAccount(void);     // 계좌 개설
void depositMoney(void);     // 입금
void withdrawMoney(void);     // 출금
void showAllAccInfo(void);      // 잔액조회

enum{MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account; // 클래스가 정의되기 전에 포인터로 사용할땐 forward declaration 사용
// extern : "실제 메모리는 다른 곳에 있으니, 여기서는 그냥 존재만 알려주는 것"
extern Account* accArr[100];
extern int accNum;

class Account
{
private:
    int accID;
    int balance;
    char* cusName;

public:
    Account(int ID, int money, char* name);
    int getID() const;
    void Deposit(int money);
    int Withdraw(int money);
    void showAccInfo() const;
    ~Account();
};

#endif