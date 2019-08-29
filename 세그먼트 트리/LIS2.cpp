#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int segment[2097152];//first: 숫자 크기, second: 인덱스
int S = 1;
P arr[1000000];

bool cmp(P a, P b) {
	if (a.first != b.first)
		return a.first < b.first;
	else
		return a.second > b.second;
}

int maxNum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return segment[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return max(maxNum(L, R, nodeNum * 2, nodeL, mid), maxNum(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
}

void update(int i, int val) {
	i += S;
	segment[i] = val;
	while (i > 1) {
		i = i / 2;
		if (segment[i] > val)//원래 값이 더 크면 업데이트 안함
			break;
		segment[i] = val;
	}
}
	

int main() {
	int N;

	scanf("%d", &N);

	
	while (S < N)
		S *= 2;

	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		arr[i].first = a;
		arr[i].second = i;
	}

	sort(arr, arr+N, cmp);

	for (int i = 0; i < N; i++) {
		int idx = arr[i].second;//인덱스 추출
		int m = maxNum(0, idx, 1, 0, S - 1);
		update(idx, m + 1);
		//for (int i = 1; i < S * 2; i++)
		//	printf("%d ", segment[i]);
		//printf("\n");
	}

	printf("%d\n", segment[1]);

	return 0;
}