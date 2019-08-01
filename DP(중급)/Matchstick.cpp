#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

long long dp[101][2];

long long power(int n) {//�ڸ��� ��ŭ 10�� ���ϴ� ��
	long long ret = 1;
	for (int i = 0; i < n; i++) {
		ret *= 10;
	}
	return ret;
}

long long dfs(int n, bool isFirst) {//n: ���� ����. isFirst: ���� �� ù��° �ڸ��� ���ԵǾ��ִ°� ����
	long long& ret = dp[n][isFirst];
	if (ret != -1)
		return ret;
	if (n == 2)
		return ret = 1;
	if (n == 3)
		return ret = 7;
	if (n == 4)
		return ret = 4;
	if (n == 5)
		return ret = 2;
	if (n == 6) {
		if (isFirst)
			return ret = 6;//ù �κ��̸� 6 ��ȯ
		else
			return ret = 0;//�ƴϸ� 0 ��ȯ
	}
	if (n == 7)
		return ret = 8;

	ret = 1000000000000000;//������ �ſ� ū �� ����
	for (int i = 2; i <= 7; i++) {
		if ((n - i - 1) / 7 < (n - 1) / 7) {//�ڸ����� �������� ����� ���� �پ���� �� �� �ִ�.
			if (isFirst)
				ret = min(ret, dfs(i, true) * power((n - 1) / 7) + dfs(n - i, false));
			else
				ret = min(ret, dfs(i, false) * power((n - 1) / 7) + dfs(n - i, false));
		}
	}

	return ret;
}

int main() {
	int T;

	scanf("%d", &T);

	for (int i = 0; i <= 100; i++) {//dp �ʱ�ȭ
		dp[i][0] = -1;
		dp[i][1] = -1;
	}

	for (int t = 0; t < T; t++) {
		int n;

		scanf("%d", &n);
		
		//���� ���� ���
		printf("%lld ", dfs(n, true));
		

		//ū ���� ���
		if (n % 2 == 0) {
			while (n > 0) {
				printf("1");
				n = n - 2;
			}
		}
		else {
			printf("7");
			while (n > 3) {
				printf("1");
				n = n - 2;
			}
		}
		printf("\n");
	}

	return 0;
}
