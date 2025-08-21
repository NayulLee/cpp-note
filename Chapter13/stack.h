// stack 템플릿 클래스 예제
#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class Stack
{
private :
    T* ptr;
    int capacity;
    int size;

public:
    Stack(int capacity);
    ~Stack();
    void push(const T& element);
    T pop();
};

#endif