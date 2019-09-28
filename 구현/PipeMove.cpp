#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int N;
int cnt = 0;
int dy[3] = { 0, 1, 1 };
int dx[3] = { 1, 1, 0 };

int map[16][16];

bool HorizontalChk(int y, int x) {
	if (x + 1 < N && map[y][x + 1] == 0)
		return true;
	return false;
}

bool VerticalChk(int y, int x) {
	if (y + 1 < N && map[y + 1][x] == 0)
		return true;
	return false;
}

bool DiagonalChk(int y, int x) {
	if (y + 1 < N && x + 1 < N && map[y + 1][x] == 0 && map[y][x + 1] == 0 && map[y + 1][x + 1] == 0)
		return true;
	return false;
}

void dfs(int y, int x, int status) {//status-0:가로, 1: 대각선 2: 세로
	if (y == N - 1 && x == N - 1) {
		cnt++;
		return;
	}
	
	if (status == 0) {//가로
		if (HorizontalChk(y, x))
			dfs(y, x + 1, 0);
		if (DiagonalChk(y, x))
			dfs(y + 1, x + 1, 1);
	}
	else if (status == 1) {//대각선
		if (HorizontalChk(y, x))
			dfs(y, x + 1, 0);
		if (DiagonalChk(y, x))
			dfs(y + 1, x + 1, 1);
		if (VerticalChk(y, x))
			dfs(y + 1, x, 2);
	}
	else {//세로
		if (DiagonalChk(y, x))
			dfs(y + 1, x + 1, 1);
		if (VerticalChk(y, x))
			dfs(y + 1, x, 2);
	}
}

int main() {
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

	dfs(0, 1, 0);

	printf("%d", cnt);


	return 0;
}