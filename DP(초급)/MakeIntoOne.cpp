#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000001;

int dp[MAX];

int f(int n) {
	if (n == 1)//1�̸� ��
		return 0;
	if (dp[n] != -1)//���� �̹� ���� �����
		return dp[n];//�̹� ���� ��� return
	
	int result = f(n - 1) + 1;//�ϴ� �⺻���� ���

	if (n % 3 == 0) //3�� ����� ���
		result = min(f(n / 3) + 1, result);
	if (n % 2 == 0)//2�� ����� ���
		result = min(f(n / 2) + 1, result);

	dp[n] = result;
	return result;
}

int main() {
	int N;
	int result;

	cin >> N;
	fill(dp, dp + MAX, -1);//fill: ó�� ��ġ���� �� ��ġ���� -1�� ä��� algorithm �Լ�
	result = f(N);
	cout << result << '\n';

	return 0;
}