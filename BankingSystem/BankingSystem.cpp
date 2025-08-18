#include "BankingSystem.h"
#include <iostream>
#include <cstring>

Account* accArr[100];  // 최대 100개까지 계좌 생성 가능
int accNum = 0;

Account::Account(int ID, int money, char* name)
 : accID(ID), balance(money)
 {
    cusName = new char[strlen(name) + 1];
    strcpy(cusName, name);
 }

 int Account::getID() const
 {
    return accID;
 }

void Account::Deposit(int money)
{
    balance += money;
}

int Account::Withdraw(int money)
{
    if(balance < money)
    {
        return 0;
    }

    balance -= money;
    return money;
}

void Account::showAccInfo() const
{
    std::cout << "계좌번호 : " << accID << std::endl;
    std::cout << "잔  액 : " << balance << std::endl;
    std::cout << "이  름 : " << cusName << std::endl;
}

Account::~Account()
{
    delete []cusName;
}

void showMenu(void)
{
    std::cout << "-----------------Meny-----------------" << std::endl;
    std::cout << "1. 계좌 개설" << std::endl;
    std::cout << "2. 입     금" << std::endl;
    std::cout << "3. 출     금" << std::endl;
    std::cout << "4. 계좌 정보 전체 출력" << std::endl;
    std::cout << "5. 프로그램 종료" << std::endl;
}

void makeAccount(void)
{
    int id;
    char name[NAME_LEN];
    int balance;

    std::cout << "[계좌 개설]" << std::endl;
    std::cout << "계좌 번호 입력 : " ;   std::cin >> id;
    std::cout << "이름  입력 : " ;   std::cin >> name;
    std::cout << "입금액 입력 : " ;   std::cin >> balance;
    std::cout << std::endl;    

    accArr[accNum++] = new Account(id, balance, name);
}

void depositMoney(void)
{
    int money;
    int id;
     std::cout << "[입  금]" << std::endl;
     std::cout << "계좌 ID : ";    std::cin>>id;
     std::cout << "입금액 : " ;    std::cin>>money;

     for(int i = 0; i < accNum; i++)
     {
        if(accArr[i]->getID()==id)
        {
            accArr[i]->Deposit(money);
            std::cout << "\"입금완료\"" << std::endl << std::endl;
            return;
        }
     }
     std::cout << "유효하지 않은 ID 입니다." << std::endl << std::endl;
}

void withdrawMoney(void)     // 출금
{
    int money;
    int id;
     std::cout << "[출  금]" << std::endl;
     std::cout << "계좌 ID : ";    std::cin>>id;
     std::cout << "출금액 : ";      std::cin>>money;

     for(int i = 0; i < accNum; i++){
        if(accArr[i]->getID() == id)
        {
            if(accArr[i]->Withdraw(money)==0){
                std::cout << "\"error : 잔액이 부족합니다. \"" << std::endl;
                return;
            }
            std::cout << "출금 완료" << std::endl << std::endl;
            return;
        }
     }
     std::cout << "유효하지 않은 ID입니다." << std::endl;

    
}

void showAllAccInfo(void)
{
    for(int i = 0; i < accNum; i++)
    {
        accArr[i]-> showAccInfo();
        std::cout << std::endl;
    }
}