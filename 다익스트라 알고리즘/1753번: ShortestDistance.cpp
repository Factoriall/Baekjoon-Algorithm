#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
bool visited[20000];


int main() {
	vector<P> adj[20000];
	int dist[20000];
	const int INF = 1000000000;

	int V, E, S;
	scanf("%d %d", &V, &E);
	scanf("%d", &S);
	S--;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u - 1].push_back(P(v - 1, w));//adj 배열의 pair함수는 first: 간선번호, second: 가중치
	}

	
	fill(dist, dist + V, INF);

	// pair함수의 경우 first 먼저 비교하고 같을 시 second 비교
	//greater 사용 시 top에 가장 작은 수가 올라온다, less는 가장 큰 수.
	////PQ에서 pair 함수 first: 가중치, second: 이어진 간선 번호 -> adj와 반대!
	priority_queue<P, vector<P>, greater<P>> PQ; 

	//다익스트라 알고리즘
	dist[S] = 0;
	PQ.push(P(0, S));

	while (!PQ.empty()) {
		int curr;
		do {
			curr = PQ.top().second;//위치
			PQ.pop();
		} while (!PQ.empty() && visited[curr]);

		if (visited[curr])//비었고 해당노드는 방문했으므로 더이상 갈 곳 없음
			break;

		visited[curr] = true;
		for (P nextP : adj[curr]) {
			int next = nextP.first;//다음 위치
			int nw = nextP.second;//가중치
			
			if (dist[next] > dist[curr] + nw) {
				dist[next] = dist[curr] + nw;
				PQ.push(P(dist[next], next));
			}
		}
	}

	for (int i = 0; i < V; i++) {
		if (dist[i] == INF)
			puts("INF");
		else
			printf("%d\n", dist[i]);
	}


	return 0;
}
