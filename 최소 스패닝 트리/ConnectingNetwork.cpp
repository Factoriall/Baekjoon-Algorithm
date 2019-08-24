#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int uf[1000];


int find(int a) {//���� ���տ� �ִ��� Ȯ�� �۾�
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {//���� ���տ� �ִ��� Ȯ�� �� ������ false, �ٸ��� true
	a = find(a);
	b = find(b);
	if (a == b) return false;
	uf[b] = a;
	return true;
}

struct Edge {
	int u, v, w;
	Edge() : Edge(-1, -1, 0) {}//����Ʈ ������
	Edge(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {}//������
	bool operator <(const Edge &O) { return w < O.w; }//< ������ �����ε�
};

Edge e[100000];

int main() {
	int N, M;
	
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[i] = Edge(a - 1, b - 1, c);//������
	}

	sort(e, e + M);

	int result = 0;
	int cnt = 0;
	fill(uf, uf + N, -1);

	for (int i = 0; ; i++) {
		if (merge(e[i].u, e[i].v)) {
			result += e[i].w;//����ġ ��
			if (++cnt == N - 1) break;
		}
	}
	printf("%d\n", result);

	return 0;
}