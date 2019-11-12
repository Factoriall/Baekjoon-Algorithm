#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int S;
const int MAX = 1000001;
const int MIN = -1;

typedef pair<int, int> P;

P arr[262145];


//L,R : ���� �츮�� ���Ϸ� �ߴ� ����
//nodeNum: ���� ���� �ִ� ��� ��ȣ
//nodeL, nodeR: nodeNum�� �����ϴ� ����

//���׸�Ʈ Ʈ�� ���� �� �ּڰ� ����
int minNum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return MAX;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum].first;
	int mid = (nodeL + nodeR) / 2;
	return min(minNum(L, R, nodeNum * 2, nodeL, mid), minNum(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
}

//���׸�Ʈ Ʈ�� ���� �� �ִ� ����
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
		//���������� �ִ밪 �� �ּҰ� ����
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
			//i�� ��ġ�� � ��ȣ�� å�� �ִ°� ���
			arr[i] = P(i - S, i - S);//ó���� MIN, MAX �� ����
		}
		for (int i = S + N; i < 2 * S; i++) {
			//������ ���� �� ���� ������ ä��
			arr[i] = P(MAX, MIN);
		}
		construct();

		//printTree();

		for (int i = 0; i < K; i++) {
			int q, a, b;
			scanf("%d %d %d", &q, &a, &b);
			if (q) {//�մ� ��ũ ������
				//printf("min: %d, max: %d\n", minNum(a, b, 1, 0, S - 1), maxNum(a, b, 1, 0, S - 1));
				if (minNum(a, b, 1, 0, S - 1) >= a && maxNum(a, b, 1, 0, S - 1) <= b) {
					puts("YES");
				}
				else
					puts("NO");
			}
			else {//������ ���� �ٲٱ�
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