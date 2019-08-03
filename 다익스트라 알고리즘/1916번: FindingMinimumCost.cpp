#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;


int main() {
	int N, M;
	const int INF = 100000000;
	vector<P> city[1000];
	int dist[1000];
	bool visited[1000] = { 0 };

	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		city[s - 1].push_back(P(w, e - 1));//first: 가중치, second: 번호
	}

	int S, E;
	scanf("%d %d", &S, &E);
	S--; E--;

	fill(dist, dist + N, INF);

	priority_queue<P, vector<P>, greater<P>> pq;

	dist[S] = 0;
	pq.push(P(0, S));//first: 가중치, second: 번호
	
	//fill(visited, visited + N, false);

	while (!pq.empty()) {
		int curr;
		do {
			curr = pq.top().second;//번호
			pq.pop();
		} while (!pq.empty() && visited[curr]);
		if (visited[curr]) break;

		visited[curr] = true;

		if (curr == E) {
			printf("%d\n", dist[curr]);
			break;
		}

		for (P nextP : city[curr]) {
			int d = nextP.first;
			int next = nextP.second;

			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				pq.push(P(dist[next], next));
			}
		}
	}

	return 0;
}
