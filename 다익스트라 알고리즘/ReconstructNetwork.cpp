#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

typedef struct {
	int prev;
	int w;
}D;

D dist[1000];
vector<P> adj[1000];
bool visited[1000];

int main() {
	ios::sync_with_stdio(false);

	int N, M;
	const int INF = 10000;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {//쌍방향 저장
		int a, b, w;
		cin >> a >> b >> w;

		adj[a - 1].push_back(P(b - 1, w));
		adj[b - 1].push_back(P(a - 1, w));
	}

	for (int i = 1; i < N; i++) {
		dist[i].w = INF;
		dist[i].prev = -1;
	}

	priority_queue<P, vector<P>, greater<P>> PQ;//PQ first: 가중치, second: 위치 
	dist[0].w = 0;
	dist[0].prev = 0;
	PQ.push(P(0, 0));

	while (!PQ.empty()) {
		int curr; 
		do{
			curr = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[curr]);
		if (visited[curr]) break;
		
		visited[curr] = true;

		for (P nextP : adj[curr]) {//adj 배열 first: 위치, second: 간선 길이
			int next = nextP.first;
			int d = nextP.second;
			if (dist[next].w > dist[curr].w + d) {
				dist[next].w = dist[curr].w + d;
				dist[next].prev = curr;
				//cout << "curr: " << curr << ", next: " << next << ", dist[next]: " << dist[next].w << '\n';
				PQ.push(P(dist[next].w, next));
			}
		}
	}


	cout << N-1 << '\n';
	for (int i = 1; i < N; i++) {
		cout << i + 1 << ' ' << dist[i].prev + 1 << '\n';
	}

	return 0;
}