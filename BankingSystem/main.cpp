#include "BankingSystem.h"
#include <iostream>

int main()
{
    int choice;

    while(true)
    {
        showMenu();
        std::cout << "선택 >> "; 
        std::cin >> choice ; 
        std::cout<<std::endl;

        switch(choice)
        {
        case MAKE:
            makeAccount();
            break;
        case DEPOSIT:
            depositMoney();
            break;
        case WITHDRAW:
            withdrawMoney();
            break;
        case INQUIRE:
            showAllAccInfo();
            break;
        case EXIT:
            for(int i = 0; i < accNum; i++)
            delete accArr[i];
            
            return 0;
        default:
            std::cout << "illegal section..." << std::endl;
        }
    }
    return 0;
}