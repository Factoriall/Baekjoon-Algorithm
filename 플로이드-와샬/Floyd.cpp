#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 100000000;

int main() {
	int N, M;
	int dist[100][100];

	ios::sync_with_stdio(false);
	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		dist[s - 1][e - 1] = min(dist[s - 1][e - 1], w);
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dist[i][j] == INF)
				cout << "0 ";
			else
				cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}


	return 0;
}