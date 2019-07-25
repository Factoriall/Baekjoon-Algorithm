#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

long long dp[32][32];//dp 안에는 n,m 개수 조건을 만족하는 비트의 종류 수를 저장

long long binary(int n, int m) {//n: 앞으로 채워야 할 남은 비트수, m: 채워야할 남은 1의 개수
	long long& ret = dp[n][m];
	if (ret != -1)
		return ret;
	if (n == 0 || m == 0)
		return ret = 1;

	ret = binary(n - 1, m);//지금 수를 0으로 채웠을 때
	if (m > 0)
		ret += binary(n - 1, m - 1);//지금 수를 1로 채웠을 때
	
	return ret;
}

void printAns(int n, int m, long long r) {
	if (m == 0 || r == 1) {
		while (n > 0) {
			printf("0");
			n--;
		}
		return;
	}
	if (n == 0)
		return;

	if (r > dp[n - 1][m]) {//1로 채워지는 경우
		printf("1");
		//printf("%d %d %d\n", n - 1, m - 1, r - dp[n - 1][m]);
		printAns(n - 1, m - 1, r - dp[n - 1][m]);
	}
	else {//0으로 채워지는 경우
		printf("0");
		//printf("%d %d %d\n", n - 1, m, r);
		printAns(n - 1, m, r);
	}
}

int main() {
	int N, L;
	long long I;

	scanf("%d %d %lld", &N, &L, &I);

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= L; j++) {
			dp[i][j] = -1;
		}
	}

	binary(N, L);
	printAns(N, L, I);
	printf("\n");
	/*for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= L; j++) {
			printf("%d\t", dp[i][j]);
		}
		printf("\n");
	}*/

	return 0;
}