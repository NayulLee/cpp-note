#include "BankingSystem.h"
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string input;
    int choice;

    while(true)
    {
        showMenu();
        std::cout << "선택 >> "; 
        std::getline(std::cin, input); // 한 줄 통째로 입력 받음
        std::stringstream ss(input);
        /*
        std::cin >> choice는 정수(int)입력만 기대한다. 그러나 사용자가 3. 같이 숫자+특문으로 입력할 경우
        cin은 정수 부분만 읽으려 시도하고 특문은 버퍼에 남게 된다.
        'std::cin.clear(); std::cin.ignore(100, '\n');'로 막아줘도 버퍼에 남아있을 수 있다.
        [해결방법]
        std::cin >> choice 대신에 `getline`을 사용한다
            - 한줄 단위로 입력받고, 파싱해서 정수 변환이 안전하다.
            - 이렇게 하면 숫자 뒤에 공백, 글자 등 포함 여부까지 검사할 수 있다.

        std::stringstream ss(input)
            - header : <sstream>
            - input문자열을 스트림처럼 취급 가능하게 한다.
                - 보통 `cin >> x`는 키보드 입력을 읽어 변수에 저장
                - `stringstream ss(str) : 이미 가지고 잇는 문자열을 마치 cin처럼 읽어서 변수에 저장가능
        */
        if(!(ss >> choice) || !(ss.eof()))
        {
            /*
            ss >> choice :
             - 문자열 스트림에서 정수로 변환 시도(true, false반환)
            ss.eof() : 
             - 스트림 끝에 도달했는지 확인
             - 변환 후 남은 문자가 없으면 true, 있으면 false
            */
            std::cerr << "잘못된 입력입니다. 숫자만 입력해주세요" << std::endl;
            continue;
        }

        try{
        switch(choice)
        {
        case MAKE:
            makeAccount();  break;
        case DEPOSIT:
            depositMoney(); break;
        case WITHDRAW:
            withdrawMoney(); break;
        case INQUIRE:
            showAllAccInfo(); break;
        case EXIT:
            for(int i = 0; i < accNum; i++) delete accArr[i];    
            return 0;
        default:
            throw std::out_of_range("메뉴 번호가 잘못되었습니다.");
          }
        }
        catch(const std::exception& e){
        std::cerr << "ERROR : " << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(100, '\n');
      }
    }   
    return 0;
}