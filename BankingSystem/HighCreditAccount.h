#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalCreditAccount.h"

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