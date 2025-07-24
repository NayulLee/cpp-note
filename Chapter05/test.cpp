#include <iostream>
#include <string>

using namespace std;

class Message{
private:
    string text;

public :
    Message(string s) : text(s){
        cout << "생성됨 : "<< text << endl;
    }
    ~Message(){
        cout << "소멸됨 : " <<text << endl;
    }
    void print() const{
        cout << "내용 : " << text << endl;
    }
};

Message createMessage(){
    return Message("안녕!"); 
}

int main(){
    const Message& ref = createMessage();   // 임시 객체 생성
    ref.print();
}