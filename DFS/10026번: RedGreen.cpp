#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

char map1[100][100];
char map2[100][100];

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int N;

void normalDFS(int n, int m, char c) {
	map1[n][m] = '.';

	for (int i = 0; i < 4; i++) {
		if (n + dy[i] >= 0 && n + dy[i] < N && m + dx[i] >= 0 && m + dx[i] < N && map1[n + dy[i]][m + dx[i]] == c)
			normalDFS(n + dy[i], m + dx[i], c);
	}
}

void abnormalDFS(int n, int m, char c) {
	map2[n][m] = '.';

	for (int i = 0; i < 4; i++) {
		if (n + dy[i] >= 0 && n + dy[i] < N && m + dx[i] >= 0 && m + dx[i] < N && map2[n + dy[i]][m + dx[i]] == c)
			abnormalDFS(n + dy[i], m + dx[i], c);
	}
}

int main() {
	int i, j;
	
	int normal = 0;
	int abnormal = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%s", map1[i]);
		for (j = 0; j < N; j++) {
			if (map1[i][j] == 'G')
				map2[i][j] = 'R';
			else
				map2[i][j] = map1[i][j];
		}
	}

	/*for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%c", map1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%c", map2[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (map1[i][j] != '.') {
				normalDFS(i, j, map1[i][j]);
				normal++;
			}
			if (map2[i][j] != '.') {
				abnormalDFS(i, j, map2[i][j]);
				abnormal++;
			}
		}
	}

	printf("%d %d\n", normal, abnormal);

	return 0;
}
