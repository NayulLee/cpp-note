/*
  서버에서 클라이언트가 보내온 요청을 보고,
   요청 종류(login, mmove, chat 등)에 따라
    각각 다른 클래스(핸들러)가 처리하게 하는 시스템
*/

#include <iostream>
#include <unordered_map>    // 해시맵 자료구조 제공(key → value) 형식
#include <memory>           // 스마트 포인터 기능, new-delete안쓰고 자동 메모리 관리


// 요청 패킷(간단화된 구조체)
struct Packet
{
    std::string command; // Login, move, chat 등
    std::string data;    // plyer1, x = 10, y = 5 등
};

// 기본 핸들러 클래스(추상클래스) 선언
class PacketHandler
{
public:
    virtual ~PacketHandler() = default;
    virtual void handle(const Packet& packet) =0;
};

class LoginHandler : public PacketHandler
{
public:
    void handle(const Packet& packet) override
    {
        std::cout << "[LoginHandler] 로그인 시도 : " << packet.data <<std:: endl;
       std:: cout << "[LoginHandler] 로그인 성공! : " << std::endl;

    }
};

class MoveHandler : public PacketHandler
{
public:
    void handle(const Packet& packet) override
    {
        std::cout << "[MoveHandler] 플레이어 이동 처리 : " << packet.data << std::endl;
    }
};

class ChatHandler : public PacketHandler
{
public:
      void handle(const Packet& packet) override
      {
        std::cout << "[ChatHandler] 채팅 메시지 수신 : " << packet.data << std::endl;
      }
};

/* 핸들러 관리자(요청 라우팅)
    들어온 요청(패킷)의 종류(command)에 따라
    어떤 핸들러가 처리할지 결정해서 실행
    ex. "login"문자열을 보고 그에 해당하는 핸들러 객체를 찾아서 실행한다.*/
class HandlerManager
{
private:
    std::unordered_map
    <
        std::string,
        std::unique_ptr<PacketHandler> 
    >handlers;

public:
    HandlerManager()
    {
        handlers["login"] = std::make_unique<LoginHandler>();
        handlers["move"] = std::make_unique<MoveHandler>();
        handlers["chat"] = std::make_unique<ChatHandler>();
    }

    void handleRequest(const Packet& Packet) // 읽기 전용
    {
        auto it = handlers.find(Packet.command);     // auto : 변수 타입을 컴파일러가 자동 추론
        if( it != handlers.end())   // .find()는 못찾으면 .end()를 반환한다.
        {
            it->second->handle(Packet);
        }
        else
        {
            std::cout << "[ERROR] Unknown command : " << Packet.command << std::endl;
        }
   
    }
};

int main() {
    HandlerManager manager;

    Packet loginReq{ "login", "player1" };
    Packet moveReq{ "move", "x=10,y=20" };
    Packet chatReq{ "chat", "Hello world!" };
    Packet wrongReq{ "disconnect", "bye" };

    manager.handleRequest(loginReq);
    manager.handleRequest(moveReq);
    manager.handleRequest(chatReq);
    manager.handleRequest(wrongReq);

    return 0;
}