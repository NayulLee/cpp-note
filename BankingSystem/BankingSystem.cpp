#include "BankingSystem.h"
#include <iostream>
#include <cstring>
#include <cctype>

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
    std::cout << "-----------------Menu-----------------" << std::endl;
    std::cout << "1. 계좌 개설" << std::endl;
    std::cout << "2. 입     금" << std::endl;
    std::cout << "3. 출     금" << std::endl;
    std::cout << "4. 계좌 정보 전체 출력" << std::endl;
    std::cout << "5. 프로그램 종료" << std::endl;
}

void makeAccount(void)
{
    try{    // 유효성 검사
    int id;
    char name[NAME_LEN];
    int balance;

    std::cout << "[계좌 개설]" << std::endl;
    std::cout << "계좌 번호 입력 : " ;   std::cin >> id;
    if(std::cin.fail()) throw std::invalid_argument("계좌 번호는 숫자만 가능합니다.");

    std::cout << "이름  입력 : " ;   std::cin >> name;
    for(int i = 0; name[i] != '\0'; i++){
        if(isdigit(name[i]) || ispunct(name[i]) || isspace(name[i])) // 숫자 || 특문 || 스페이스
            throw std::invalid_argument("이름에는 숫자/특수문자를 넣을 수 없습니다.");
    }

    std::cout << "입금액 입력 : " ;   std::cin >> balance;
    if(balance < 0) throw std::invalid_argument("입금액은 0이상이어야 합니다.");

        accArr[accNum++] = new Account(id, balance, name);

    std::cout << "-------------------계좌 개설 완료!-------------------"<< std::endl;    
    }
    catch(const std::exception& e){
        std::cerr << "ERROR : " << e.what() << std:: endl;
        std::cin.clear();
        std::cin.ignore(100, '\n');
        /*
        > 입력 스트림(cin)의 상태를 초기화하고 남은 입력을 버린다.
        > !!!입력값 유효성 검사 후 무조건 넣어줘야하는 코드!!!
         std::cin.clear();
         - 입력 도중 오류가 발생하면(ex.숫자 입력인데 문자 입력) failbit가 켜지고 입력이 전부 막힌다
         - 'cin.clear()' : 입력 스트림의 상태 플래그를 초기화(clear)해서 다시 사용 가능하게 만드는 함수

        std::cin.ignore(100, '\n'); 
         - 입력 버퍼에는 사용자가 입력하고 엔터 친 값이 남아있다(개행 문자)
         - 'cin.ignore(n, delim)': 버퍼에서 n개 문자 혹은 delim(구분자)까지 버린다.
         - 여기서는 최대 100문자, 또는 개행 문자까지 버리면서 다음 입력 준비 완료시킨다.
        */
    }
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