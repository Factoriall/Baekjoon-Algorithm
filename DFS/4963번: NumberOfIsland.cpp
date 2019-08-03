#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int dy[8] = { 0 , 1, 0, -1, 1, 1, -1, -1 };
int dx[8] = { 1, 0, -1, 0, -1, 1, 1, -1 };

int map[50][50];
int N, M;

void dfs(int y, int x) {
	map[y][x] = 0;

	for (int i = 0; i < 8; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M) {
			if (map[nextY][nextX] == 1) {
				dfs(nextY, nextX);
			}
		}
	}
}

int main() {
	

	scanf("%d %d", &M, &N);
	while (N != 0 && M != 0) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}*/

		printf("%d\n", cnt);

		scanf("%d %d", &M, &N);
	}

	return 0;
}
