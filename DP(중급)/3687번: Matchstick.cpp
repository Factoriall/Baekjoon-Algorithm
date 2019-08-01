#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

long long dp[101][2];

long long power(int n) {//자릿수 만큼 10을 곱하는 식
	long long ret = 1;
	for (int i = 0; i < n; i++) {
		ret *= 10;
	}
	return ret;
}

long long dfs(int n, bool isFirst) {//n: 지금 숫자. isFirst: 지금 맨 첫번째 자리가 포함되어있는가 여부
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
			return ret = 6;//첫 부분이면 6 반환
		else
			return ret = 0;//아니면 0 반환
	}
	if (n == 7)
		return ret = 8;

	ret = 1000000000000000;//임의의 매우 큰 수 설정
	for (int i = 2; i <= 7; i++) {
		if ((n - i - 1) / 7 < (n - 1) / 7) {//자릿수가 적아져야 제대로 수가 줄어듦을 알 수 있다.
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

	for (int i = 0; i <= 100; i++) {//dp 초기화
		dp[i][0] = -1;
		dp[i][1] = -1;
	}

	for (int t = 0; t < T; t++) {
		int n;

		scanf("%d", &n);
		
		//작은 숫자 출력
		printf("%lld ", dfs(n, true));
		

		//큰 숫자 출력
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
