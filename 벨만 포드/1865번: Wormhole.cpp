#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

vector<P> adj[500];
int dist[500];
bool visited[500];

int main() {
	ios::sync_with_stdio(false);

	int T;
	const int INF = 25000001;//임의의 매우 큰 수

	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, M, W;
		bool isReachable = false;
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
		
		int n = 0;
		do {
			if (!visited[n]) {//방문 안했다면 컴포넌트가 따로 존재한다는 의미, 다른 컴포넌트 내에서도 벨만포드 알고리즘 적용
				dist[n] = 0;
				visited[n] = true;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						for (P nextP : adj[j]) {
							int next = nextP.first;
							int d = nextP.second;
							if (dist[j] != INF && dist[next] > dist[j] + d) {
								if (i == N - 1) {
									isReachable = true;
								}
								dist[next] = dist[j] + d;
								visited[next] = true;
							}
						}
					}
				}
			}
			n++;
		} while (n < N && !isReachable);

		if (isReachable)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}


	return 0;
}
