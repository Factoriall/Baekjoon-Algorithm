#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

long long arr[2097152];//세그먼트 트리

long long sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeNum * 2, nodeL, mid) + sum(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}

int main() {
	int N, M, K;
	//vector<int> ans;
	scanf("%d %d %d", &N, &M, &K);

	int start = 1;
	while (N > start)
		start *= 2;

	for (int i = start; i < start + N; i++)
		scanf("%lld", &arr[i]);

	for (int i = start - 1; i > 0; i--)//세그먼트 트리 생성
		arr[i] = arr[i * 2] + arr[i * 2 + 1];

	/*for (int i = 1; i < start * 2; i++)
		printf("%d ", arr[i]);
	printf("\n");*/
	
	for (int i = 0; i < M + K; i++) {
		int a, b;
		long long c;
		scanf("%d %d %lld", &a, &b, &c);
		if (a == 1) {//업데이트 하는 법
			int sIdx = b - 1 + start;
			arr[sIdx] = c;
			while (sIdx > 1) {
				sIdx /= 2;
				arr[sIdx] = arr[sIdx * 2] + arr[sIdx * 2 + 1];
			}
		}
		if (a == 2)
			printf("%lld\n", sum(b - 1, c - 1, 1, 0, start - 1));
	
	}

	return 0;
}
