#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int map[100][100];
long long memo[100][100];

long long dp(int n, int m) {
	long long& ret = memo[n][m];
	if (ret != -1)
		return ret;
	if (n == 0 && m == 0)
		return 1;

	long long result = 0;
	for (int i = 0; i < n; i++)
		if (map[i][m] + i == n)
			result += dp(i, m);
	for (int j = 0; j < m; j++)
		if (map[n][j] + j == m)
			result += dp(n, j);

	return ret = result;
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			memo[i][j] = -1;
		}

	printf("%lld\n", dp(N - 1, N - 1));

	return 0;
}