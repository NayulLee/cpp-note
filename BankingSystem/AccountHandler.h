#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "Account.h"

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
    virtual ~AccountHandler();

protected:
    void makeNormalAccount(void);   // 일반 계좌(원금 + 이자)
    void makeCreditAccount(void);   // 신용 계좌(원금 + 이자 + 신용등급에 따른 이자 추가)

};

#endif