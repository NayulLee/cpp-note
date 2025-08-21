// stack 클래스를 사용하는 어플리케이션 파일
#include "stack.h"

int main()
{
    Stack<int> stack(10);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(3);
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;

    return 0;
}