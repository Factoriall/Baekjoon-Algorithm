#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int uf[100000];

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

struct Planet{
	int num, d;
	Planet() {}
	Planet(int n, int d) : num(n), d(d){}
	bool operator<(const Planet& p) { return d < p.d; }
};

Planet xp[100000];
Planet yp[100000];
Planet zp[100000];

struct Edge {
	int u, v, w;
	Edge() : u(-1), v(-1), w(0) {}//기본 생성자가 존재해야합니다!
	Edge(int u1, int v1, int w1) : u(u1), v(v1), w(w1){}
	bool operator<(const Edge &O) { return w < O.w; }
};

Edge e[300000];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		xp[i] = Planet(i, x);
		yp[i] = Planet(i, y);
		zp[i] = Planet(i, z);
	}

	sort(xp, xp + N);
	sort(yp, yp + N);
	sort(zp, zp + N);

	for (int i = 0; i < N - 1; i++) {
		e[3 * i] = Edge(xp[i].num, xp[i + 1].num, abs(xp[i].d - xp[i + 1].d));
		e[3 * i + 1] = Edge(yp[i].num, yp[i + 1].num, abs(yp[i].d - yp[i + 1].d));
		e[3 * i + 2] = Edge(zp[i].num, zp[i + 1].num, abs(zp[i].d - zp[i + 1].d));
	}

	sort(e, e + 3 * (N - 1));

	fill(uf, uf + N, -1);
	int result = 0; int cnt = 0;
	for (int i = 0; ; i++) {
		if (merge(e[i].u, e[i].v)) {
			result += e[i].w;
			if (++cnt == N - 1)
				break;
		}
	}

	printf("%d\n", result);

	return 0;
}