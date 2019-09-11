#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int result = 0;
int R, C;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

char map[20][20];
bool AlpVisited[26];
bool visited[20][20];

void dfs(int y, int x, int cnt) {
	//printf("%d %d %d\n", y, x, cnt);
	visited[y][x] = true;
	AlpVisited[map[y][x] - 'A'] = true;
	bool isFinished = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
			if (!visited[ny][nx] && !AlpVisited[map[ny][nx] - 'A']) {
				isFinished = false;
				dfs(ny, nx, cnt + 1);
				visited[ny][nx] = false;
				AlpVisited[map[ny][nx] - 'A'] = false;
			}
		}
	}
	if (isFinished) {
		/*for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				printf("%d", visited[i][j]);
			}
			printf("\n");
		}
		printf("=================\n");*/
		//printf("cnt: %d\n", cnt);
		result = max(result, cnt);
	}
}

int main() {
	
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		scanf("%s", &map[i]);
	}

	/*for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}*/

	dfs(0, 0, 1);

	printf("%d", result);

	return 0;
}