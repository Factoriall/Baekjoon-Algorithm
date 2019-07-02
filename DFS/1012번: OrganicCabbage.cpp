#include <iostream>
using namespace std;

int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };//동서남북 방향 
int map[52][52];

void dfs(int y, int x) {
	map[y][x] = -1;//지금 위치를 이미 방문한 것(-1)로 변경
	for (int i = 0; i < 4; i++) {//4방향 돌면서 조건에 맞을시 재귀함수 돌리기
		if (map[y + dir[i][0]][x + dir[i][1]] == 1)
			dfs(y + dir[i][0], x + dir[i][1]);
	}
}

int main() {
	int testCase;
	int m, n, k;
	int t, i, j;//반복자
	int result;//결과값

	cin >> testCase;
	for (t = 0; t < testCase; t++) {
		result = 0;
		cin >> m >> n >> k;

		for (i = 1; i <= n; i++) {//초기화
			for (j = 1; j <= m; j++) {
				map[i][j] = 0;
			}
		}

		
		for (i = 0; i < k; i++) {
			int a, b;
			cin >> b >> a;
			map[a+1][b+1] = 1;
		}

		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				if (map[i][j] == 1) {
					dfs(i, j);//맵 하나씩 돌아다니면서 dfs 시전
					result++;
				}
			}
		}

		cout << result << endl;
	}

	return 0;
}
