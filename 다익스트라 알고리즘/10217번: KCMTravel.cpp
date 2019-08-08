#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int city;
	int cost;
	int time;
}P;

vector<P> adj[100];

struct cmp {
	bool operator()(P a, P b) {//시간 따라 priority_queue 조절
		return a.time > b.time;
	}
};

int main() {
	ios::sync_with_stdio(false);
	const int INF = 10000001;
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, M, K;
		int dist[100][10001];
		bool visited[100][10001];
		cin >> N >> M >> K;

		for (int i = 0; i < K; i++) {
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			adj[u - 1].push_back(P{ v - 1, c, d });
		}

		for (int i = 0; i < N; i++) {//초기화
			for (int j = 0; j <= M; j++) {
				dist[i][j] = INF;
				visited[i][j] = false;
			}
		}

		priority_queue<P, vector<P>, cmp> PQ;
		dist[0][0] = 0;
		PQ.push(P{ 0, 0, 0 });//1. city, 2. cost, 3. time

		bool isFinished = false;
		while (!PQ.empty()) {
			int curP;
			int curC;
			do {
				curP = PQ.top().city;
				curC = PQ.top().cost;
				PQ.pop();
			} while (!PQ.empty() && visited[curP][curC]);
			if (visited[curP][curC]) break;

			visited[curP][curC] = true;

			if (curP == N - 1) {//도착하면 끝
				cout << dist[curP][curC] << '\n';
				isFinished = true;
				break;
			}

			for (P nextP : adj[curP]) {
				int next = nextP.city;
				int c = nextP.cost;
				int d = nextP.time;
				if (curC + c <= M && dist[next][curC + c] > dist[curP][curC] + d) {
					dist[next][curC + c] = dist[curP][curC] + d;
					PQ.push(P{ next, curC + c, dist[next][curC + c] });
				}
			}
		}
		if (!isFinished)
			cout << "Poor KCM" << '\n';

		for (int i = 0; i < N; i++) //모두 초기화
			adj[i].clear();
	}

	return 0;
}
