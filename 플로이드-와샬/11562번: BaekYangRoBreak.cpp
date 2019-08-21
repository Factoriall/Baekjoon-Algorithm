#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 100000;

int main() {
	int N, M, K;
	int dist[250][250] = { 0 };
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {//ÃÊ±âÈ­
		for (int j = 0; j < N; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	
	for (int i = 0; i < M; i++) {
		int u, v, b;

		scanf("%d %d %d", &u, &v, &b);

		if (b == 0) {
			dist[u - 1][v - 1] = 0;
			dist[v - 1][u - 1] = 1;
		}
		else {
			dist[u - 1][v - 1] = 0;
			dist[v - 1][u - 1] = 0;
		}
	}

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", dist[s - 1][e - 1]);
	}

	return 0;
}
