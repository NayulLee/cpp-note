#include <iostream>	

int solution(int k, int m, int score[], int score_len)
{
	int temp = 0;
	int result = 0;
	int total = 0;

	// 내림차순 정렬
	for (int i = 0; i < score_len - 1; i++) {
		for (int j = 0; j < score_len - i - 1; j++) {
			if (score[j] < score[j + 1]) {
				temp = score[j];
				score[j] = score[j + 1];
				score[j + 1] = temp;
			}
		}
	}

	// 최대이익 계산
	for (int i = 0; i + m -1 < score_len; i += m)
	{
		result = score[i + m - 1];
		total += result * m;
	}
}


int main()
{
	int k;
	int m;
	
		


	return 0;
}