#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

bool visited[100001];
int N, K;

void bfs() {
	queue<int> q;
	q.push(N);
	visited[N] = true;
	int cnt = 0;

	while (!q.empty()) {
		int qSize = q.size();
		for (int t = 0; t < qSize; t++) {
			int now = q.front();
			q.pop();

			if (now == K) {
				printf("%d\n", cnt);
				return;
			}
			for (int i = 0; i < 3; i++) {
				int next;
				if (i == 0)
					next = now + 1;
				else if (i == 1)
					next = now - 1;
				else
					next = now * 2;

				if (next >= 0 && next <= 100000 && !visited[next]) {
					q.push(next);
					visited[next] = true;
				}
			}
		}
		cnt++;
	}
}

int main() {
	scanf("%d %d", &N, &K);
	bfs();

	return 0;
}
