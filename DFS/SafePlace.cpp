#include <iostream>
#include <algorithm>
using namespace std;

int result;
int p[102][102];
int c[102][102];
int n;

int dir[4][2] = { {0,1}, {0,-1}, {1, 0}, {-1, 0} };//방향 동서남북

void copyMap(int copy[102][102], int origin[102][102]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			copy[i][j] = origin[i][j];
		}
	}
}

void dfs(int t, int i, int j) {
	int k;
	c[i][j] = -1;
	for (k = 0; k < 4; k++) {//4방향 따라 침몰 안된 인접 공간 있는지 확인
		if (c[i + dir[k][0]][j + dir[k][1]] > t)
			dfs(t, i + dir[k][0], j + dir[k][1]);
	}
}

int main() {
	int i, j;
	int t;
	int fin = 1;//비 안올때 상정


	cin >> n;

	//입력
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> p[i][j];
		}
	}

	for (t = 1; t <= 100; t++) {
		result = 0;
		copyMap(c, p);//미리 copy맵 가져와서 여기에 방문처리까지 하게 한다.
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (c[i][j] > t) {
					dfs(t, i, j);
					result++;
				}
			}
		}
		fin = max(fin, result);//가장 큰 것 체크

		if (result == 0)//0일시 모두 침몰한 상태이므로 더 할 필요 없음
			break;
	}
	cout << fin << '\n';

	return 0;
}