#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

typedef struct {
	long long weight;
	int now;
	int paved;
}Info;

struct cmp {
	bool operator()(Info a, Info b) {//weight µû¶ó priority_queue Á¶Àý
		return a.weight > b.weight;
	}
};

vector<P> adj[10000];
long long dist[10000][21];
bool visited[10000][21];

int main() {
	ios::sync_with_stdio(false);
	int C,R,K;
	const long long INF = 50000000001;

	cin >> C >> R >> K;

	for (int i = 0; i < R; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		adj[s - 1].push_back(P(w, e - 1));//first: °¡ÁßÄ¡, second: µµÂøÁ¡
		adj[e - 1].push_back(P(w, s - 1));
	}

	for (int i = 0; i < C; i++) {
		for (int j = 0; j <= K; j++) {
			dist[i][j] = INF;
		}
	}

	priority_queue<Info, vector<Info>, cmp> PQ;
	dist[0][0] = 0;
	PQ.push(Info{0, 0, 0});
	
	while (!PQ.empty()) {
		int curr;
		int pNum;
		do {
			curr = PQ.top().now;
			pNum = PQ.top().paved;
			PQ.pop();
		} while (!PQ.empty() && visited[curr][pNum]);
		if (visited[curr][pNum]) break;

		visited[curr][pNum] = true;


		for (P nextP : adj[curr]) {
			int next = nextP.second;
			int d = nextP.first;

			if (dist[next][pNum] > dist[curr][pNum] + d) {
				dist[next][pNum] = dist[curr][pNum] + d;
				PQ.push(Info{dist[next][pNum], next, pNum});
			}

			if (pNum < K && dist[next][pNum + 1] > dist[curr][pNum]) {
				dist[next][pNum + 1] = dist[curr][pNum];
				PQ.push(Info{ dist[next][pNum + 1], next, pNum + 1 });
			}
		}
	}

	cout << dist[C - 1][K] << '\n';

	/*for (int i = 0; i < C; i++) {
		for (int j = 0; j <= K; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}*/

	return 0;
}
