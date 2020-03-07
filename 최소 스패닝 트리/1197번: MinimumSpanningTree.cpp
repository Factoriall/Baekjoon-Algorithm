#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int uf[10000]; // union-find 배열

// union-find의 find 연산
int find(int a) {
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

// union-find의 union 연산
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	uf[b] = a;
	return true;
}

// 간선 구조체. w 기준으로 정렬됨
struct Edge {
	int u, v, w;
	Edge() : Edge(-1, -1, 0) {}
	Edge(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {}
	bool operator <(const Edge& O)const { return w < O.w; }
};

int main() {
	int V, E;
	scanf("%d %d", &V, &E);
	
	Edge MST[10000];
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		MST[i] = Edge(u - 1, v - 1, w);
	}
	sort(MST, MST + E);
	/*for (int i = 0; i < E; i++) {
		printf("[%d %d %d]", MST[i].u, MST[i].v, MST[i].w);
	}
	printf("\n");*/

	int result = 0; int cnt = 0;

	fill(uf, uf + V, -1);
	for (int i = 0; i < E; i++) {
		int a = MST[i].u; int b = MST[i].v;
		if (merge(a, b)) {
			cnt++;
			result += MST[i].w;
		}
		if (cnt == V - 1)
			break;
	}

	printf("%d\n", result);

	return 0;
}
