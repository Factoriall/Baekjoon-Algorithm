#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;//first: ÃÖ¼Ú°ª, second: ÃÖ´ñ°ª
int S = 1;
P arr[262144];

int maxNum(int L, int R, int nodeNum, int nodeL, int nodeR){
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum].second;
	int mid = (nodeL + nodeR) / 2;
	return max(maxNum(L, R, nodeNum * 2, nodeL, mid), maxNum(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
}

int minNum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 1000000001;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum].first;
	int mid = (nodeL + nodeR) / 2;
	return min(minNum(L, R, nodeNum * 2, nodeL, mid), minNum(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
}


int main() {
	int N, M;

	scanf("%d %d", &N, &M);

	while (S < N)
		S *= 2;

	for (int i = S; i < S + N; i++) {
		int a;
		scanf("%d", &a);
		arr[i].first = arr[i].second = a;
	}
	for (int i = S + N; i < S * 2; i++) {
		arr[i].first = 1000000001;
		arr[i].second = 0;
	}

	for (int i = S - 1; i > 0; i--) {
		arr[i].first = min(arr[2 * i].first, arr[2 * i + 1].first);
		arr[i].second = max(arr[2 * i].second, arr[2 * i + 1].second);
	}

	//for (int i = 1; i < S * 2; i++)
	//	printf("(%d %d)\n", arr[i].first, arr[i].second);
	//printf("\n");

	for (int i = 0; i < M; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d %d\n", minNum(l - 1, r - 1, 1, 0, S - 1), maxNum(l - 1, r - 1, 1, 0, S - 1));
	}


	return 0;
}
