#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int tree[524288];

void update(int i, int val) {
	tree[i] = val;
	while (i > 1) {
		i /= 2;
		tree[i] = tree[2 * i] + tree[2 * i + 1];
	}
}

int sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return tree[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeNum * 2, nodeL, mid) + sum(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}

int main() {
	int T;

	scanf("%d", &T);
	
	for (int t = 0; t < T; t++) {
		int s = 1;
		int n, m;
		int pnt[100000];
		vector<int> ans;
		scanf("%d %d", &n, &m);

		while (s < m || s < n)//둘다 따져서 
			s *= 2;
		
		s *= 2;

		int p = s + s / 2 - 1;//값 저장
		for (int i = 0; i < n; i++) {
			pnt[i] = p;
			tree[p] = 1;
			p--;
		}

		/*for (int i = 0; i < n; i++)
			printf("%d ", pnt[i]);
		printf("\n[Tree]\n");
		for (int i = 1; i < 2*s; i++)
			printf("%d ", tree[i]);
		printf("\n");*/
		
		//construct 함수
		for (int i = s - 1; i > 0; i--)
			tree[i] = tree[2 * i] + tree[2 * i + 1];

		/*for (int i = 0; i < n; i++)
			printf("%d ", pnt[i]);
		printf("\n[Tree]\n");
		for (int i = 1; i < 2*s; i++)
			printf("%d ", tree[i]);
		printf("\n");
		printf("s: %d\n", s);*/
		for (int i = 0; i < m; i++) {
			int a;
			int start = s + s / 2 + i;
			scanf("%d", &a);
			update(pnt[a - 1], 0);
			update(start, 1);
			ans.push_back(sum(pnt[a - 1] + 1, start, 1, s, 2 * s - 1) - 1);
			pnt[a - 1] = start;

			/*for (int i = 0; i < n; i++)
				printf("%d ", pnt[i]);
			printf("\n[Tree]\n");
			for (int i = 1; i < 2 * s; i++)
				printf("%d ", tree[i]);
			printf("\n");*/
		}
		for (int n : ans)
			printf("%d ", n);
		printf("\n");
	}



	return 0;
}