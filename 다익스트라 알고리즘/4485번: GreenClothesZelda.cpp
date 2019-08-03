#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

typedef struct {
	int y;
	int x;
	int w;
}P;

struct cmp {
	bool operator()(P a, P b) {//weight 따라 priority_queue 조절
		return a.w > b.w;
	}
};

int main() {
	int N;
	int map[125][125];
	bool visited[125][125];
	int dist[125][125];
	int cnt = 1;
	const int INF = 25000;

	scanf("%d", &N);

	while (N != 0) {
		int result;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {//초기화
			for (int j = 0; j < N; j++) {
				visited[i][j] = false;
				dist[i][j] = INF;
			}
		}

		priority_queue<P, vector<P>, cmp> pq;
		dist[0][0] = map[0][0];
		pq.push(P{ 0, 0, map[0][0] });

		while (!pq.empty()) {
			int curY;
			int curX;
			do {
				curY = pq.top().y;
				curX = pq.top().x;
				pq.pop();
			} while (!pq.empty() && visited[curY][curX]);
			if (visited[curY][curX]) break;

			visited[curY][curX] = true;

			if (curY == N - 1 && curX == N - 1) {//끝점 도달
				/*for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						if (dist[i][j] == INF)
							printf("INF\t");
						else
							printf("%d\t", dist[i][j]);
					}
					printf("\n");
				}
				printf("\n");*/
				result = dist[N - 1][N - 1];
				break;
			}

			for (int i = 0; i < 4; i++) {//4방향 이동 기록
				int nextY = curY + dy[i];
				int nextX = curX + dx[i];
				if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < N) {//기본 조건
					//printf("nextY: %d, nextX: %d\n", nextY, nextX);
					if (dist[nextY][nextX] > dist[curY][curX] + map[nextY][nextX]) {
						dist[nextY][nextX] = dist[curY][curX] + map[nextY][nextX];
						pq.push(P{ nextY, nextX, dist[nextY][nextX] });
					}
				}
			}
		}

		printf("Problem %d: %d\n", cnt++, result);

		scanf("%d", &N);
	}

	return 0;
}
