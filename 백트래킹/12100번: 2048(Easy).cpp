#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int result = 0;
int N;
int map[20][20];

void copymap(int copy[20][20], int origin[20][20]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			copy[i][j] = origin[i][j];
}

//dir - 0 : 오른쪽, 1: 아래쪽, 2: 왼쪽, 3: 위쪽
void dfs(int n, int dir) {
	int cnt = 0;
	if (dir == 0) {//오른쪽
		for (int i = 0; i < N; i++) {
			int py = N - 1;//넣을 위치
			int strd = 0;//기준의 값
			int sy;//기준의 위치
			for (int j = N - 1; j >= 0; j--) {
				if (map[i][j] != 0) {
					if (strd == 0) {
						strd = map[i][j];
						sy = j;
						if (n == 5)
							cnt = max(cnt, map[i][j]);
					}
					else {
						if (map[i][j] == strd) {//같으면 곱하기
							map[i][py] = 2 * strd;
							strd = 0;
						}
						else {//다르면 기준 변경
							map[i][py] = strd;
							strd = map[i][j];
							sy = j;
						}
						if (n == 5)
							cnt = max(cnt, map[i][py]);
					}
					
					map[i][j] = 0;
				}
			}
			if (strd != 0)
				map[i][py] = strd;
		}
	}
	if (dir == 1) {//아래쪽
		for (int j = 0; j < N; j++) {
			int px = N - 1;//넣을 위치
			int strd = 0;//기준의 값
			int sx;//기준의 위치
			for (int i = N - 1; i >= 0; i--) {
				if (map[i][j] != 0) {
					if (strd == 0) {
						strd = map[i][j];
						sx = i;
						if (n == 5)
							cnt = max(cnt, map[i][j]);
					}
					else {
						if (map[i][j] == strd) {//같으면 곱하기
							map[px][j] = 2 * strd;
							strd = 0;
						}
						else {//다르면 기준 변경
							map[px][j] = strd;
							strd = map[i][j];
							sx = i;
						}
						if (n == 5)
							cnt = max(cnt, map[px][j]);
						px--;
					}
					map[i][j] = 0;
				}
			}
			if (strd != 0)
				map[px][j] = strd;
		}
	}
	if (dir == 2) {//왼쪽
		for (int i = 0; i < N; i++) {
			int py = 0;//넣을 위치
			int strd = 0;//기준의 값
			int sy;//기준의 위치
			for (int j = 0; j < N; j++) {
				if (map[i][j] != 0) {
					if (strd == 0) {
						strd = map[i][j];
						sy = j;
						if (n == 5)
							cnt = max(cnt, map[i][j]);
					}
					else {
						if (map[i][j] == strd) {//같으면 곱하기
							map[i][py] = 2 * strd;
							strd = 0;
						}
						else {//다르면 기준 변경
							map[i][py] = strd;
							strd = map[i][j];
							sy = j;
						}
						if (n == 5)
							cnt = max(cnt, map[i][py]);
						py++;
					}
					map[i][j] = 0;
				}
			}
			if (strd != 0)
				map[i][py] = strd;
		}
	}
	if (dir == 3) {//위쪽
		for (int j = 0; j < N; j++) {
			int px = 0;//넣을 위치
			int strd = 0;//기준의 값
			int sx;//기준의 위치
			for (int i = 0; i < N; i++) {
				if (map[i][j] != 0) {
					if (strd == 0) {
						strd = map[i][j];
						sx = i;
						if (n == 5)
							cnt = max(cnt, map[i][j]);
					}
					else {
						if (map[i][j] == strd) {//같으면 곱하기
							map[px][j] = 2 * strd;
							strd = 0;
						}
						else {//다르면 기준 변경
							map[px][j] = strd;
							strd = map[i][j];
							sx = i;
						}
						if (n == 5)
							cnt = max(cnt, map[px][j]);
						px++;
					}
					map[i][j] = 0;
				}
			}
			if (strd != 0)
				map[px][j] = strd;
		}
	}

	if (n == 5) {
		result = max(cnt, result);
		return;
	}

	int copy[20][20];
	copymap(copy, map);

	for (int i = 0; i < 4; i++) {
		dfs(n + 1, i);
		copymap(map, copy);
	}
}

int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

	int copy[20][20];
	copymap(copy, map);
	for (int i = 0; i < 4; i++) {
		dfs(1, i);
		copymap(map, copy);
	}

	printf("%d\n", result);

	return 0;
}
