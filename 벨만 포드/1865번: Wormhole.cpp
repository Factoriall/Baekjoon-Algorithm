#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

vector<P> adj[500];
int dist[500];
bool visited[500];
bool isReachable;

void dfs(int now) {//사이클에서 출발점으로 돌아갈 수 있는지 체크
	if (now == 0) {
		isReachable = true;
		return;
	}

	for (P nextP : adj[now]) {
		int next = nextP.first;

		if (!visited[next]) {
			visited[next] = true;
			dfs(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	int T;
	const int INF = 25000001;

	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, M, W;
		isReachable = false;
		cin >> N >> M >> W;

		//초기화
		for (int i = 0; i < N; i++) {
			adj[i].clear();
			visited[i] = false;
		}

		//도로 정보
		for (int i = 0; i < M; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			adj[s - 1].push_back(P(e - 1, t));
			adj[e - 1].push_back(P(s - 1, t));
		}
		//웜홀 정보
		for (int i = 0; i < W; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			adj[s - 1].push_back(P(e - 1, -t));
		}

		fill(dist, dist + N, INF);
		dist[0] = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (P nextP : adj[j]) {
					int next = nextP.first;
					int d = nextP.second;
					if (dist[j] != INF && dist[next] > dist[j] + d) {
						if (i == N - 1) {//음의 사이클 생성, 이 사이클에서 출발점으로 돌아갈 수 있으면 성공
							visited[j] = true;
							dfs(j);
						}
						dist[next] = dist[j] + d;
					}
				}
			}
		}

		/*for (int i = 0; i < N; i++)
			cout << dist[i] << ' ';
		cout << '\n';*/

		if (isReachable)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}


	return 0;
}
