#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int uf[1000];


int find(int a) {//같은 집합에 있는지 확인 작업
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {//같은 집합에 있는지 확인 후 있으면 false, 다르면 true
	a = find(a);
	b = find(b);
	if (a == b) return false;
	uf[b] = a;
	return true;
}

struct Edge {
	int u, v, w;
	Edge() : Edge(-1, -1, 0) {}//디폴트 생성자
	Edge(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {}//생성자
	bool operator <(const Edge &O) { return w < O.w; }//< 연산자 오버로딩
};

Edge e[100000];

int main() {
	int N, M;
	
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[i] = Edge(a - 1, b - 1, c);//생성자
	}

	sort(e, e + M);

	int result = 0;
	int cnt = 0;
	fill(uf, uf + N, -1);

	for (int i = 0; ; i++) {
		if (merge(e[i].u, e[i].v)) {
			result += e[i].w;//가중치 합
			if (++cnt == N - 1) break;
		}
	}
	printf("%d\n", result);

	return 0;
}