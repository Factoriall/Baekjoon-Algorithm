#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<long long, long long> P;//first: cnt, second: sum

P arr[524288];
const int S = 262144;
const int MOD = 1000000007;

void update(int i, int val) {
	i += S;
	arr[i].first++;
	arr[i].second += val;

	while (i > 1) {
		i /= 2;
		arr[i].first = arr[2 * i].first + arr[2 * i + 1].first;
		arr[i].second = arr[2 * i].second + arr[2 * i + 1].second;
	}
}

long long cnt(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum].first;
	int mid = (nodeL + nodeR) / 2;
	return cnt(L, R, nodeNum * 2, nodeL, mid) + cnt(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}

long long sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum].second;
	int mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeNum * 2, nodeL, mid) + sum(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}

int main() {
	int N;
	
	scanf("%d", &N);

	long long result = 1;
	for (int i = 0; i < N; i++) {
		int d;
		scanf("%d", &d);
		update(d, d);

		if (i != 0) {
			//printf("%d %lld %lld %d %lld\n", cnt(0, d - 1, 1, 0, S - 1)*d, sum(0, d - 1, 1, 0, S - 1), sum(d + 1, S - 1, 1, 0, S - 1), cnt(d + 1, S - 1, 1, 0, S - 1)*d,
			//	cnt(0, d - 1, 1, 0, S - 1)*d - sum(0, d - 1, 1, 0, S - 1)
			//	+ sum(d + 1, S - 1, 1, 0, S - 1) - cnt(d + 1, S - 1, 1, 0, S - 1)*d);
		
			result *= (cnt(0, d - 1, 1, 0, S - 1)*d - sum(0, d - 1, 1, 0, S - 1)
				+ sum(d + 1, S - 1, 1, 0, S - 1) - cnt(d + 1, S - 1, 1, 0, S - 1)*d)%MOD;
			//printf("result: %lld\n", result);
		}
	}
	printf("%lld\n", result % MOD);

	return 0;
}