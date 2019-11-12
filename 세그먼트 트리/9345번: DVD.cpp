#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int S;
const int MAX = 1000001;
const int MIN = -1;

typedef pair<int, int> P;

P arr[262145];


//L,R : 원래 우리가 구하려 했던 범위
//nodeNum: 현재 보고 있는 노드 번호
//nodeL, nodeR: nodeNum이 포함하는 구간

//세그먼트 트리 범위 중 최솟값 추출
int minNum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return MAX;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum].first;
	int mid = (nodeL + nodeR) / 2;
	return min(minNum(L, R, nodeNum * 2, nodeL, mid), minNum(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
}

//세그먼트 트리 범위 중 최댓값 추출
int maxNum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return MIN;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum].second;
	int mid = (nodeL + nodeR) / 2;
	return max(maxNum(L, R, nodeNum * 2, nodeL, mid), maxNum(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
}


void update(int i) {
	i += S;
	while (i > 1) {
		i /= 2;
		arr[i] = P(min(arr[i * 2].first, arr[i * 2 + 1].first),
			max(arr[i * 2].second, arr[i * 2 + 1].second));
	}
}

void construct() {
	for (int i = S - 1; i > 0; --i) {
		//범위에서의 최대값 및 최소값 삽입
		arr[i] = P(min(arr[i * 2].first, arr[i * 2 + 1].first),
			max(arr[i * 2].second, arr[i * 2 + 1].second));
	}
}

void printTree() {
	int tmp = 2;
	for (int i = 1; i < 2 * S; i++) {
		if (tmp <= i) {
			printf("\n");
			tmp *= 2;
		}
		printf("(%d, %d) ", arr[i].first, arr[i].second);
	}
	printf("\n");
}



int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int N, K;
		scanf("%d %d", &N, &K);

		S = 1;
		while (S < N)
			S *= 2;

		for (int i = S; i < S + N; i++) {
			//i의 위치에 어떤 번호의 책이 있는가 기록
			arr[i] = P(i - S, i - S);//처음은 MIN, MAX 값 같음
		}
		for (int i = S + N; i < 2 * S; i++) {
			//나머지 나올 수 없는 값으로 채움
			arr[i] = P(MAX, MIN);
		}
		construct();

		//printTree();

		for (int i = 0; i < K; i++) {
			int q, a, b;
			scanf("%d %d %d", &q, &a, &b);
			if (q) {//손님 디스크 꺼내기
				//printf("min: %d, max: %d\n", minNum(a, b, 1, 0, S - 1), maxNum(a, b, 1, 0, S - 1));
				if (minNum(a, b, 1, 0, S - 1) >= a && maxNum(a, b, 1, 0, S - 1) <= b) {
					puts("YES");
				}
				else
					puts("NO");
			}
			else {//진상이 순서 바꾸기
				P tmp = arr[S + a];
				arr[S + a] = arr[S + b];
				arr[S + b] = tmp;
				update(a);
				update(b);
				//printTree();
			}
		}
	}

	return 0;
}
