#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#include <iostream>
#include <cstring> // C스타일 문자열 함수 모음(strlen, strcpy...) char[]다룸
#include <cctype>
#include <limits>
#include <string>   // 문자열 클래스 std::string
#include <sstream>  // 문자열 파싱용 std::stringstream
#include <stdexcept> // 예외 클래스 std::invalide_argument
#include <cstdlib>  // 콘솔창 지우기 system("clear")
#include <string>

// consexpr : 무조건 컴파일 타임에 값이 결정되는 상수임을 보장한다.
constexpr  int NAME_LEN = 20;

// 프로그램 사용자 선택 메뉴
enum{MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

// 신용등급
enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};

// 계좌의 종류
enum{NORMAL = 1, CREDIT = 2};

#endif