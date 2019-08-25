#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int uf[200000];

int find(int a) {
	if (uf[a] == -1) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int u, int v) {
	int a = find(u);
	int b = find(v);
	if (a == b)
		return false;
	uf[a] = b;
	return true;
}

struct Edge {
	int u, v, w;
	Edge() : u(-1), v(-1), w(0) {}
	Edge(int u, int v, int w) : u(u), v(v), w(w){}
	bool operator<(const Edge &O) { return w < O.w; }
};

Edge e[200000];

int main() {
	int M, N;

	scanf("%d %d", &M, &N);

	while (M != 0 || N != 0) {
		int total = 0;
		for (int i = 0; i < N; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			e[i] = Edge(x, y, z);
			total += z;
		}

		sort(e, e + N);

		/*printf("\n");
		for (int i = 0; i < N; i++)
			printf("%d %d %d\n", e[i].u, e[i].v, e[i].w);*/


		int result = 0; int cnt = 0;
		fill(uf, uf + M, -1);
		for (int i = 0; ; i++) {
			if (merge(e[i].u, e[i].v)) {
				//printf("optimal: %d %d %d\n", e[i].u, e[i].v, e[i].w);
				result += e[i].w;
				if (++cnt == M - 1)
					break;
			}
		}
		printf("%d\n", total - result);

		scanf("%d %d", &M, &N);
	}

	return 0;
}