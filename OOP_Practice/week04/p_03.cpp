/*
	새로 생긴 놀이기구는 인기가 매우 많아 줄이 끊이질 않습니다. 
	이 놀이기구의 원래 이용료는 price원 인데, 놀이기구를 N 번 째 이용한다면 원래 이용료의 N배를 받기로 하였습니다. 
	즉, 처음 이용료가 100이었다면 2번째에는 200, 3번째에는 300으로 요금이 인상됩니다. 

	놀이기구를 count번 타게 되면 현재 자신이 가지고 있는 금액 money에서 얼마가 모자라는지를 출력하는 프로그램을 
	작성하세요. 단, 금액이 부족하지 않으면 0을 출력해야 합니다. 
	price, money, count의 값은 순서대로 표준 입출력으로 주어집니다.
*/

#include <iostream>

int main()
{	
	//		기본 이용료, 가진 돈, 사용횟수
	long long price,     money,   count;

	std::cin >> price >> money >> count;
	
	long long result = (price * count * (count + 1)) / 2;

	if (result > money)
		std::cout << result - money << std::endl;
	else
		std::cout << "0" << std::endl;

	return 0;
}