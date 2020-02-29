#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

int N, K, L;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int sec_change[101];
char dir_change[101];
int cnt = 0;

typedef pair<int, int> P;
queue<P> snake;

int map[102][102];

void printMap() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void dummy_game(int y, int x, int d, int sec) {//y,x: 뱀 머리 위치, dir: 이동방향, cnt: 현재시간
	if (map[y][x] == 1 || y == 0 || x == 0 || y == N + 1 || x == N + 1) {
		printf("%d\n", sec);
		return;
	}
	snake.push(P(y, x));
	
	if (map[y][x] == 0) {
		//printf("%d %d\n", snake.front().first, snake.front().second);
		map[snake.front().first][snake.front().second] = 0;
		snake.pop();
	}
	map[y][x] = 1;

	if (cnt < L && sec == sec_change[cnt]) {
		if (dir_change[cnt] == 'D') 
			d = (d == 3) ? 0 : d + 1;
		else 
			d = (d == 0) ? 3 : d - 1;
		cnt++;
	}
	//printMap();
	dummy_game(y + dy[d], x + dx[d], d, sec + 1);
}

int main() {
	scanf("%d", &N);
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int n, m;
		scanf("%d %d", &n, &m);
		map[n][m] = 2;//사과 위치
	}

	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		int x; char c;

		scanf("%d %c", &x, &c);
		sec_change[i] = x;
		dir_change[i] = c;
	}

	map[1][1] = 1;//뱀 위치
	snake.push(P(1, 1));

	dummy_game(1, 2, 0, 1); // 미리 이동해서 시작
}