#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

long long dp[100][2];

void trackAnswer(long long now, int p) {
	if (p == 0) 
		return;

	if (now - dp[p][0] >= 0) {
		printf("1");
		trackAnswer(now - dp[p][0], p - 1);
	}
	else {
		printf("0");
		trackAnswer(now, p - 1);
	}

}

int main() {
	long long K;

	scanf("%lld", &K);

	dp[1][0] = 1; dp[1][1] = 1;

	int i = 1;
	while (K >= dp[i][0] + dp[i][1]) {
		i++;
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	/*for (int m = 1; m <= i; m++) {
		printf("%lld %lld\n", dp[m][0], dp[m][1]);
	}*/

	trackAnswer(K, i);


	return 0;
}