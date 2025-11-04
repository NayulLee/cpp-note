#include "q3.h"

SortedIntegerVector::SortedIntegerVector(int cap)
	:IntegerVector(cap) // 부모 생성자 호출
{
}

void SortedIntegerVector::append(int item)
{
	if (size == capacity)
		resize();

	// 값을 추가할 때 정렬 된 상태로 값을 추가한다.(삽입정렬 사용)
	data[size] = item; // push
	size++;
	
	int j = size - 2;
	while (j >= 0 && data[j] > item)
	{
		data[j + 1] = data[j];
		j--;
	}
	data[j + 1] = item;
}

void SortedIntegerVector::pop(int value)
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == value)
		{
			for (int j = i; j < size - 1; j++)
			{
				data[j] = data[j + 1];
			}
			size--;
			i--;
		}
	}
}