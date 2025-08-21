#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
    int accID;      // 계좌번호
    int balance;    // 잔액
    char* cusName;  // 고객이름

public:
    Account(int ID, int money, char* name);
    Account(const Account& ref);
    virtual ~Account();
    
    int getID() const;      // getter
    virtual void Deposit(int money);    // 입금
    int Withdraw(int money);    // 출금
    void showAccInfo() const;   // 사용자 정보 출력

};

#endif