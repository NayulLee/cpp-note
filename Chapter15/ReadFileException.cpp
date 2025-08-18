#include <iostream>
#include <fstream>      // 파일 입출력용 라이브러리
#include <stdexcept>    // C++표준 예외 클래스 헤더

void loadConfig(const std::string& filename)
{
    std::ifstream file(filename);
    if(!file.is_open())
        throw std::runtime_error("Faild to open config File >> " + filename);
}

int main()
{
    try{
        loadConfig("config.txt");
        std::cout << "Config loaded!" << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << "error : " << e.what() << std::endl;
        // 서버 종료 또는 기본값으로 초기화
    }
}