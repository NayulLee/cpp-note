#ifndef __Q3_H__
#define __Q3_H__

#include "q2.h"
#include <algorithm>

class SortedIntegerVector :public IntegerVector
{
	
	
public:
	SortedIntegerVector(int cap);
	void append(int item) override;
	void pop(int value);
};

#endif