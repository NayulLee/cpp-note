/*
	���� ���� ���̱ⱸ�� �αⰡ �ſ� ���� ���� ������ �ʽ��ϴ�. 
	�� ���̱ⱸ�� ���� �̿��� price�� �ε�, ���̱ⱸ�� N �� ° �̿��Ѵٸ� ���� �̿���� N�踦 �ޱ�� �Ͽ����ϴ�. 
	��, ó�� �̿�ᰡ 100�̾��ٸ� 2��°���� 200, 3��°���� 300���� ����� �λ�˴ϴ�. 

	���̱ⱸ�� count�� Ÿ�� �Ǹ� ���� �ڽ��� ������ �ִ� �ݾ� money���� �󸶰� ���ڶ������ ����ϴ� ���α׷��� 
	�ۼ��ϼ���. ��, �ݾ��� �������� ������ 0�� ����ؾ� �մϴ�. 
	price, money, count�� ���� ������� ǥ�� ��������� �־����ϴ�.
*/

#include <iostream>

int main()
{	
	//		�⺻ �̿��, ���� ��, ���Ƚ��
	long long price,     money,   count;

	std::cin >> price >> money >> count;
	
	long long result = (price * count * (count + 1)) / 2;

	if (result > money)
		std::cout << result - money << std::endl;
	else
		std::cout << "0" << std::endl;

	return 0;
}