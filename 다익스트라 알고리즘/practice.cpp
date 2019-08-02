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
		adj[u - 1].push_back(P(v - 1, w));//adj �迭�� pair�Լ��� first: ������ȣ, second: ����ġ
	}

	
	fill(dist, dist + V, INF);

	// pair�Լ��� ��� first ���� ���ϰ� ���� �� second ��
	//greater ��� �� top�� ���� ���� ���� �ö�´�, less�� ���� ū ��.
	////PQ���� pair �Լ� first: ����ġ, second: �̾��� ���� ��ȣ -> adj�� �ݴ�!
	priority_queue<P, vector<P>, greater<P>> PQ; 

	//���ͽ�Ʈ�� �˰���
	dist[S] = 0;
	PQ.push(P(0, S));

	while (!PQ.empty()) {
		int curr;
		do {
			curr = PQ.top().second;//��ġ
			PQ.pop();
		} while (!PQ.empty() && visited[curr]);

		if (visited[curr])//����� �ش���� �湮�����Ƿ� ���̻� �� �� ����
			break;

		visited[curr] = true;
		for (P nextP : adj[curr]) {
			int next = nextP.first;//���� ��ġ
			int nw = nextP.second;//����ġ
			
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