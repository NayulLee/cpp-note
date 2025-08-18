# 코드 리뷰
> **서버 시작 시 설정 파일을 로드하는 기본 구조**를 예외 처리와 함께 보여주는 예제 

## 🐣 이 코드의 목적
- `config.txt`라는 파일을 열어 **서버 설정**을 불러오는 기능을 구현한 예제
- 만약 파일이 없거나, 열기에 실패할 경우 **예외**를 던지고 프로그램이 처리하도록 한다

### 언제 쓰이는가
- 게임 서버 / 웹 서버 / 응용 프로그램 시작 시
    - `포트 번호`, `DB연결 정보`, `로그 경로`, `동시 접속자 제한`같은 환경 설정을 파일에서 불러온다
- 파일이 없다면 → 그냥 크래시하면 안되고
    - 1. 서버 실행 중단
    - 2. 기본값으로 실행(ex. port 8080, 로그는 콘솔에만 찍기)</br>
    둘 중 하나로 안전하게 처리해야 한다

---
## 🐣함수 설명
### void loadConfig()
```cpp
std::ifstream file(filename)
```
- `ifstream` 객체 `file`을 만들어서 `filename`경로의 파일을 연다
- 만약 `"config.txt"`가 있다면 파일 스트림이 열리고, 없다면 실패 상태가 된다.

```cpp
if(!file.is_open())
{
    throw std::runtime_error("설정 파일 열기 실패 :" + filename)
}
```
- `is_open`: 파일이 성공적으로 열렸는지 확인
- 실패하면 `throw`로 예외 발생
    - `std::runtime_error`는 실행 중 발생하는 일반적인 예외를 표현하는 클래스
    - 문자열 메세지를 함게 전달 -> **`e.what()`으로 나중에 출력 가능**하다.

### main()
```cpp
try{
        loadConfig("config.txt");
        std::cout << "Config loaded!" << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << "error : " << e.what() << std::endl;
        // 서버 종료 또는 기본값으로 초기화
    }
```
- `std::cerr` : 오류 메시지 출력용 스트림
    - 보통 콘솔에 빨간색으로 나온다
    - `std::cout` : 표준 출력
    - `std::cerr` : 에러 전용 출력
- `e.what()` : 예외 객체가 가진 메시지를 문자열로 리턴