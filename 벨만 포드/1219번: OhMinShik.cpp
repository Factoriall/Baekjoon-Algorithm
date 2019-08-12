#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
vector<P> adj[100];
int city[100];
long long dist[100];


void check(int n, bool v[]) {
	for (P nextP : adj[n]) {
		int next = nextP.first;
		if (!v[next]) {
			v[next] = true;
			check(next, v);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int N, S, E, M;
	const long long INF = 10000000000000;

	cin >> N >> S >> E >> M;
	for (int i = 0; i < M; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		adj[s].push_back(P(e, w));
	}
	for (int i = 0; i < N; i++) {
		cin >> city[i];
	}

	/*for (int i = 0; i < N; i++) {
		for (P next : adj[i]) {
			
			cout << next.first << ' ' << next.second << '\n';
		}
	}*/
	
	
	fill(dist, dist + N, INF);
	dist[S] = -city[S];
	bool cycle = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (P next : adj[j]) {
				int n = next.first;
				int d = next.second;
				if (dist[j] != INF && dist[n] > dist[j] + d - city[n]) {
					dist[n] = dist[j] + d - city[n];
					if (i == N - 1) {//음의 사이클에서 목적지까지 가는지 확인
						bool visited[100];
						fill(visited, visited + N, false);
						visited[j] = true;
						check(j, visited);
						if (visited[E]) {
							cycle = true;
							break;
						}
					}
				}
			}
		}
	}


	if (dist[E] == INF)
		cout << "gg" << '\n';
	else {
		if (cycle)
			cout << "Gee" << '\n';
		else
			cout << -dist[E] << '\n';
	}


	return 0;
}
