#include "BankingSystem.h"
#include <iostream>
#include <cstring> // C스타일 문자열 함수 모음(strlen, strcpy...) char[]다룸
#include <cctype>
#include <limits>
#include <string>   // 묹열 클래스 std::string
#include <sstream>  // 문자열 파싱용 std::stringstream
#include <stdexcept> // 예외 클래스 std::invalide_argument

Account *accArr[100]; // 최대 100개까지 계좌 생성 가능
int accNum = 0;

Account::Account(int ID, int money, char *name)
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
    if (balance < money)
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
    delete[] cusName;
}

void showMenu(void)
{
    std::cout << "-----------------Menu-----------------" << std::endl;
    std::cout << "1. 계좌 개설" << std::endl;
    std::cout << "2. 입     금" << std::endl;
    std::cout << "3. 출     금" << std::endl;
    std::cout << "4. 계좌 정보 전체 출력" << std::endl;
    std::cout << "5. 프로그램 종료" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

void makeAccount(void)
{
    try
    { // 유효성 검사
        int id;
        char name[NAME_LEN];
        int balance;

        std::cout << "[계좌 개설]" << std::endl;
        std::cout << "계좌 번호 입력 : ";
        std::cin >> id;
        if (std::cin.fail())
            throw std::invalid_argument("계좌 번호는 숫자만 가능합니다.");

        std::cout << "이름  입력 : ";
        std::cin >> name;
        for (int i = 0; name[i] != '\0'; i++)
        {
            if (isdigit(name[i]) || ispunct(name[i]) || isspace(name[i])) // 숫자 || 특문 || 스페이스
                throw std::invalid_argument("이름에는 숫자/특수문자를 넣을 수 없습니다.");
        }

        std::cout << "초기 금액 입력 : ";
        std::cin >> balance;
        if (balance < 0)
            throw std::invalid_argument("입금액은 0이상이어야 합니다.");

        accArr[accNum++] = new Account(id, balance, name);

        std::cout << "COMPLETE : 계좌 개설 완료!" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 최대값만큼 버퍼를 무시, 개행문자 무시
    }
    catch (const std::exception &e)
    {
        std::cerr << "ERROR : " << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    try
    {
        int money;
        int id;
        std::cout << "[입  금]" << std::endl;
        std::cout << "계좌 번호 입력 : ";   std::cin >> id;
        
        if (std::cin.fail())
            throw std::invalid_argument("계좌 번호는 숫자만 가능합니다");

        for (int i = 0; i < accNum; i++) // accNum을 이용해 배열에서 계좌 찾기
        {
            if (accArr[i]->getID() == id)
            {
                std::cout << "입금액 입력: ";   std::cin >> money;              
                if (std::cin.fail() || money <= 0)
                    throw std::invalid_argument("잘못된 입력값입니다.");

                accArr[i]->Deposit(money);
                std::cout << "COMPLETE : 입금완료" << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //

                return;
            }
        }
        throw std::invalid_argument("해당 계좌를 찾을 수 없습니다.");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    catch (const std::exception &e)
    {
        std::cerr << "ERROR : " << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void withdrawMoney(void) // 출금
{   // cin 대신 getline + stringstream방식을 이용하여 리팩토링
    std::string input;
    int id;
    int money;

    std::cout << "[출  금]" << std::endl;
    std::cout << "계좌 번호 입력 : ";
    std::getline(std::cin, input); 
    /*
    std::getline(입력스트림, 문자열 변수);
     - 입력 스트림 → 보통 std::cin
     - 문자열변수 → 입력받은 내용을 저장할 std::string
     - 사용자가 엔터 칠 때까지 입력받고, 마지막 개행문자 버리고 저장
    cin>> → 공백 전까지만 입력받는다 : 버퍼에 남은 개행때문에 다음 입력 고일 수 있다.
    getline → 엔터 칠 때까지 한 줄 전부 입력받음 : 엔터까지 처리해줘서 안정적

    */
    { // cin 입력값 검사
        std::stringstream ss(input);
        if(!(ss>>id) || !(ss.eof()))
            throw std::invalid_argument("계좌 번호는 숫자만 가능합니다.");
    }
    for(int i = 0; i < accNum; i++)
    {
        if(accArr[i]->getID() == id)
        {
            std::cout << "출금액 입력 : ";
            std::getline(std::cin, input);
            {   // cin 입력값 검사
                std::stringstream ss(input);
                if(!(ss >> money) || !(ss.eof()))
                    throw std::invalid_argument("출금액은 숫자만 가능합니다.");
            }
               // 잔액보다 많으면 불가
                if(accArr[i]->Withdraw(money) == 0)
                {
                    std::cout << "ERROR : 잔액이 부족합니다" << std::endl;
                    return;
                }
            std::cout << "COMPLETE : 출금 완료!" << std::endl;
            std::cout << std::endl;
            return;
        }
    }
            std::cout << "ERROR : 해당 계좌를 찾을 수 없습니다" << std::endl;
}

void showAllAccInfo(void)
{
    for (int i = 0; i < accNum; i++)
    {
        accArr[i]->showAccInfo();
        std::cout << std::endl;
    }
}