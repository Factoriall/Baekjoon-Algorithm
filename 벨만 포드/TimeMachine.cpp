#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

vector<P> adj[500];
int dist[500];

int main() {
	ios::sync_with_stdio(false);

	int N, M;
	const int INF = 100000000;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a - 1].push_back(P(b - 1, c));//first: 도착점, second: 시간
	}

	fill(dist, dist + 500, INF);
	dist[0] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (P nextP : adj[j]) {
				int next = nextP.first;
				int d = nextP.second;

				if (dist[j] != INF && dist[next] > dist[j] + d) {
					if (i == N - 1) {
						cout << -1 << '\n';
						return 0;
					}
					dist[next] = dist[j] + d;
				}
			}
		}
	}

	for (int i = 1; i < N; i++) {
		if (dist[i] != INF)
			cout << dist[i] << '\n';
		else
			cout << -1 << '\n';
	}
	


	return 0;
}