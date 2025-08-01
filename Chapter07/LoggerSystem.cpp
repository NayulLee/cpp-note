#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

// Logger : 공통 로깅 기능 제공
class Loger
{
protected:
    string getTimestamp() const{
        time_t now = time(nullptr);  // time(): 현재 시각 초단위 반환, nullptr넘기면 내부에서 자동으로 현재시간 반환
        char buf[64];
        // strftime(): struct tm 구조체(시분초년월등으로 나뉜 시간 구조체)를 받아 읽기좋게 문자열로 반환
        // buf에 결과 저장, 최대 sizeof(buf)까지
        // localtime(&now): time_t값을 struct tm* 포인터로 변환
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
        return buf;
    }
};

int main()
{


    
    return 0;
}