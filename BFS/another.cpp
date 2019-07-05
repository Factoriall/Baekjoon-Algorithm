#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int y;
	int x;
	int c;
}info;

int n, m;
int xd[4] = { 0,1,0,-1 };
int yd[4] = { 1,0,-1,0 };

int map[1000][1000][2];
queue<info> q;

void print() {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << map[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

void bfs() {
	int cnt = 1;
	int t, i;
	info p;
	p.x = 0; p.y = 0; p.c = 0;
	map[0][0][0] = -1;
	q.push(p);

	while (!q.empty()) {
		int qSize = q.size();
		for (t = 0; t < qSize; t++) {
			p = q.front();
			q.pop();
			for (i = 0; i < 4; i++) {
				int y = p.y + yd[i];
				int x = p.x + xd[i];
				int c = p.c;
				if (y == n - 1 && x == m - 1) {
					cout << cnt + 1 << '\n';
					return;
				}
				if (x >= 0 && x < m && y >= 0 && y < n) {
					if (map[y][x][c] == 0) {
						info tmp;
						tmp.y = y;
						tmp.x = x;
						tmp.c = c;
						q.push(tmp);
						map[y][x][c] = -1;
						if (c == 0)
							map[y][x][1] = -1;
					}
					if (map[y][x][c] == 1 && c == 0) {
						info tmp;
						tmp.y = y;
						tmp.x = x;
						tmp.c = 1;
						q.push(tmp);
						map[y][x][1] = -1;
					}
				}
			}
		}
		//print();
		cnt++;
	}
	cout << -1 << '\n';
}

int main() {

	int i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &map[i][j][0]);
			map[i][j][1] = map[i][j][0];
		}
	}

	if (n == 1 && m == 1)
		cout << 1 << '\n';
	else
		bfs();

	return 0;
}