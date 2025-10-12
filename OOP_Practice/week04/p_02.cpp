/*
	"명함 지갑을 만드는 회사에서 지갑의 크기를 정하려고 합니다. 
	다양한 모양과 크기의 명함들을 모두 수납할 수 있으면서, 작아서 들고 다니기 편한 지갑을 만들어야 합니다.
	이러한 요건을 만족하는 지갑을 만들기 위해 디자인팀은 모든 명함의 가로 길이와 세로 길이를 조사했습니다.
	아래 표는 4가지 명함의 가로 길이와 세로 길이를 나타냅니다. 
	명함 번호 가로길이 세로길이 
		1		60		50 
		2		30		70 
		3		60		30 
		4		80		40 
	가장 긴 가로 길이와 세로 길이가 각각 80, 70이기 때문에 80(가로) x 70(세로) 크기의 지갑을 만들면 
	모든 명함들을 수납할 수 있습니다. 하지만 2번 명함을 가로로 눕혀 수납한다면 80(가로) x 50(세로) 
	크기의 지갑으로 모든 명함들을 수납할 수 있습니다. 이때의 지갑 크기는 4000(=80 x 50)입니다. 
	첫 줄에는 명함의 개수 N이 주어지고, 이어지는 N개의 줄에는 각 명함의 가로 길이 w와 세로 길이 h가 
	공백으로 구분되어 주어집니다. 모든 명함을 수납할 수 있는 가장 작은 지갑의 넓이를 계산하여 
	출력하는 프로그램을 작성하세요. 이때 값은 값은 표준 입출력으로 주어집니다. "
*/
#include <iostream>
#include <vector>

int main()
{
	int n = 0, w, h;
	std::vector<std::pair<int, int>>cards;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> w >> h;
		if (w >= h)
			cards.push_back({ w, h });
		else
			cards.push_back({ h, w });
	}

	int max_width = 0;
	int max_height = 0;
	for (int i = 0; i < n; i++)
	{
		if (cards[i].first > max_width)
			max_width = cards[i].first;

		if (cards[i].second > max_height)
			max_height = cards[i].second;
	}

	std::cout << "지갑의 넓이 : " << max_width * max_height << "cm";

	return 0;
}