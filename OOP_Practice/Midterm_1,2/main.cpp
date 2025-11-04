#include "q2.h"
#include "q3.h"

int main()
{
	IntegerVector intVec(2);

	intVec.append(3);
	intVec.append(10);
	intVec.append(9);
	intVec.append(1);
	intVec.append(12);
	intVec.pop();
	intVec.pop();
	intVec.append(6);


	int* dataA = intVec.get_data();
	int sizeA = intVec.get_size();

	std::cout << "IntegerVector : ";

	for (int i = 0; i < sizeA; i++)
	{
		std::cout << dataA[i] << ", ";
	}

	std::cout << std::endl;
	SortedIntegerVector sortVec(3);

	sortVec.append(9);
	sortVec.append(1);
	sortVec.append(8);
	sortVec.append(8);
	sortVec.append(10);
	sortVec.append(0);
	sortVec.append(0);
	sortVec.pop(8);
	sortVec.pop(4);

	dataA = sortVec.get_data();
	sizeA = sortVec.get_size();

	std::cout << "SortIntegerVector : ";
	for (int i = 0; i < sizeA; i++)
	{
		std::cout << dataA[i] << ", ";
	}

	return 0;
}