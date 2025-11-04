#ifndef __Q2_H__
#define __Q2_H__

#include <iostream>

class IntegerVector
{
private:
	/*
		- 동적할당 클래스를 다룰 때 
		  포인터와 더불어 capacity와 size정보는 기본적으로 관리하도록 한다.
	*/
	int* data = nullptr; // 데이터 저장할 배열
	int size = 0; // 현재 원소 개수 저장 + 빈공간의 시작 인덱스가 된다.
	int capacity = 0; // 얼마나 저장할 수 있는지


public:
	IntegerVector(int cap);
	IntegerVector(const IntegerVector& other);
	~IntegerVector();

	int get_size();
	int get_capacity();

	// 배열 크기가 용량에 도달하면 용량 두배로 늘린다.
	void resize();	
	void append(int item);
	void pop();
	int at(int idx);


};







#endif
