#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;//first: ����ġ, second: ������ġ
vector<P> adj[500];

typedef struct {
	int w;
	vector<int> prev;
}Info;

Info dist[500];
bool visited[500];

void remove(int start, int now) {
	//cout << "start: " << start << ", now: " << now << endl;
	if (now == start) 
		return;
	
	for (int prev : dist[now].prev) {
		vector<P>::iterator iter;
		for (iter = adj[prev].begin(); iter != adj[prev].end(); ++iter) {
			if ((*iter).second == now) {
				break;
			}
		}
		if (iter == adj[prev].end())
			return;

		adj[prev].erase(iter);
		remove(start, prev);
	}
}

int main() {
	ios::sync_with_stdio(false);

	int N, M;
	const int INF = 10000001;

	cin >> N >> M;//N: ����� ��, M: ������ ��

	while (N != 0 && M != 0) {
		int S, E;

		cin >> S >> E;

		for (int i = 0; i < M; i++) {
			int s, e, w;
			cin >> s >> e >> w;
			adj[s].push_back(P(w, e));//first: ����ġ, second: ������ġ
		}

		/*for (int i = 0; i < N; i++) {
			cout << i << "��: ";
			for (P j : adj[i])
				cout << '(' << j.second << ' ' << j.first << ") ";
			cout << '\n';
		}*/

		for (int i = 0; i < N; i++) {//�ʱ�ȭ
			dist[i].w = INF;
			dist[i].prev.clear();
			visited[i] = false;
		}

		priority_queue<P, vector<P>, greater<P>> pq;
		dist[S].w = 0;
		dist[S].prev.push_back(-1);
		pq.push(P(0, S));

		while (!pq.empty()) {
			int curr;
			do {
				curr = pq.top().second;
				pq.pop();
			} while (!pq.empty() && visited[curr]);
			if (visited[curr]) break;

			visited[curr] = true;
			if (curr == E) {//���� ���� �ִܰŸ� ã��
				while (!pq.empty())
					pq.pop();
				break;
			}

			for (P nextP : adj[curr]) {
				int next = nextP.second;
				int d = nextP.first;
				if (dist[next].w > dist[curr].w + d) {
					dist[next].w = dist[curr].w + d;
					dist[next].prev.clear();
					dist[next].prev.push_back(curr);
					pq.push(P(dist[next].w, next));
				}
				else if (dist[next].w == dist[curr].w + d) {
					dist[next].prev.push_back(curr);
				}
			}
		}
		
		remove(S, E);

		/*for (int i = 0; i < N; i++) {
			cout << i << "��: ";
			for (P j : adj[i])
				cout << '(' << j.second << ' ' << j.first << ") ";
			cout << '\n';
		}*/

		for (int i = 0; i < N; i++) {//�ʱ�ȭ
			dist[i].w = INF;
			dist[i].prev.clear();
			visited[i] = false;
		}
		
		dist[S].w = 0;
		dist[S].prev.push_back(-1);
		pq.push(P(0, S));

		int len = -1;
		while (!pq.empty()) {
			int curr;
			do {
				curr = pq.top().second;
				pq.pop();
			} while (!pq.empty() && visited[curr]);
			if (visited[curr])break;

			visited[curr] = true;
			if (curr == E) {//���� ���� �ִܰŸ� ã��
				len = dist[E].w;
				break;
			}

			for (P nextP : adj[curr]) {
				int next = nextP.second;
				int d = nextP.first;
				if (dist[next].w > dist[curr].w + d) {
					dist[next].w = dist[curr].w + d;
					dist[next].prev.clear();
					dist[next].prev.push_back(curr);
					pq.push(P(dist[next].w, next));
				}
			}
		}

		cout << len << '\n';


		//�ƿ� �ʱ�ȭ
		while (!pq.empty())
			pq.pop();
		for (int i = 0; i < N; i++) 
			adj[i].clear();

		cin >> N >> M;
	}

	return 0;
}