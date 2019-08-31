#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

long long arr[2097152];
int size = 1;
const int MOD = 1000000007;

void update(int i, int val) {
	i += size;
	arr[i] = val;
	while (i > 1) {
		i /= 2;
		arr[i] = arr[2 * i] * arr[2 * i + 1] % MOD;
	}
}

long long multiply(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (L > nodeR || R < nodeL) return 1;
	if (L <= nodeL && R >= nodeR) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return multiply(L, R, nodeNum * 2, nodeL, mid) * multiply(L, R, nodeNum * 2 + 1, mid + 1, nodeR) % MOD;
}

int main() {
	int N, M, K;

	scanf("%d %d %d", &N, &M, &K);
	while (size < N)
		size *= 2;

	for (int i = size; i < size + N; i++)
		scanf("%lld", &arr[i]);
	for (int i = size + N; i < size * 2; i++)
		arr[i] = 1;

	for (int i = size - 1; i > 0; i--)//¼¼±×¸ÕÆ® Æ®¸® »ý¼º
		arr[i] = (long long)(arr[2 * i] * arr[2 * i + 1]) % MOD;
	
	for (int i = 0; i < M + K; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) 
			update(b - 1, c);
		else 
			printf("%lld\n", multiply(b - 1, c - 1, 1, 0, size - 1));
	}

	return 0;
}
