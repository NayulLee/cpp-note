// stack 템플릿 클래스 구현 파일
#ifndef __STACK_CPP__
#define __STACK_CPP__

#include "stack.h"

template<typename T>
Stack<T>::Stack(int capacity)
    :capacity(capacity), size(0)
{
    ptr = new T[capacity];
}

template<typename T>
Stack<T>::~Stack()
{
    delete [] ptr;
}

template<typename T>
void Stack<T>::push(const T& element)
{
    if(size < capacity)
    {
        ptr[size] = element;
        size++;
    }
    else
    {
        cout << "스택이 꽉 차서 삽입할 수 없습니다." << endl;
        assert(false);
    }
}

template<typename T>
T Stack<T>::pop()
{
    if(size > 0)
    {
        T temp = ptr[size - 1];
        size--;
        return temp;
    }
    else
    {
        cout << "스택이 비어서 삭제할 수 없습니다" << endl;
        assert(false);
    }
}

#endif