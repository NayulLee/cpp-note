#include "q2.h"


IntegerVector::IntegerVector(int cap) : capacity(cap), size(0)
{
	data = new int[capacity];
}

IntegerVector::IntegerVector(const IntegerVector& other)
{
	size = other.size;
	capacity = other.capacity;
	if (other.capacity != 0)
	{
		data = new int[other.capacity];
		for (int i = 0; i < other.size; i++)
		{
			data[i] = other.data[i];
		}
	}
}

IntegerVector::~IntegerVector()
{
	delete[] data;
}

int* IntegerVector::get_data() { return data; }

int IntegerVector::get_size() { return size; }

int IntegerVector::get_capacity() { return capacity; }

void IntegerVector::set_size(int sz) { size = sz; }

void IntegerVector::set_capacity(int cp) { capacity = cp; }

// 단일 책임 원칙에 의해 기능(요소 추가, 배열 2배 확장)은 분리하도록 한다.(append, resize)
void IntegerVector::resize()
{
	int* old = data;
	int newCap = capacity * 2;
	int* temp = new int[newCap];

	for (int i = 0; i < size; i++)
	{
		temp[i] = old[i];
	}

	data = temp;
	delete[] old;
	capacity = newCap;

	std::cout << "vector size up..."<< std::endl;
}

void IntegerVector::append(int item)
{
	if (size == capacity)
	{
		resize();
	}

	data[size] = item;
	size++;
}

void IntegerVector::pop()
{
	if (size > 0)
	{
		size--;
	}
}

int IntegerVector::at(int idx)
{
	// 주어지는 배열 위치에 저장된 값을 반환한다.
	return data[idx];
}

