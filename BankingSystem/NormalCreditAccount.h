#ifndef __NORMAL_CREDIT_ACCOUNT_H__
#define __NORMAL_CREDIT_ACCOUNT_H__

#include "Account.h"

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
};

#endif