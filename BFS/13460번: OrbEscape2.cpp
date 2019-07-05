#include <iostream>
#include <queue>
using namespace std;

pair<int, int> dir[4] = { {-1,0}, {0,1},{1,0},{0,-1} };//시계방향

pair<int, int> red;
pair<int, int> blue;

queue<pair<int, int>> rQueue;
queue<pair<int, int>> bQueue;

char map[10][10];
int n, m;


void print() {
	int i, j;

	map[rQueue.back().first][rQueue.back().second] = 'R';
	map[bQueue.back().first][bQueue.back().second] = 'B';

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	cout << '\n';

	map[rQueue.back().first][rQueue.back().second] = '.';
	map[bQueue.back().first][bQueue.back().second] = '.';
}

bool moveMap(int i, pair<int, int> r, pair<int, int> b, bool isRedFirst) {
	int Ry = r.first; int Rx = r.second;
	int By = b.first; int Bx = b.second;
	int yDir = dir[i].first; int xDir = dir[i].second;

	if (isRedFirst) {//빨간색 먼저
		while (map[Ry + yDir][Rx + xDir] == '.') {
			Ry += yDir; Rx += xDir;
		}

		if (map[Ry + yDir][Rx + xDir] == 'O') {
			while (map[By + yDir][Bx + xDir] == '.') {
				By += yDir; Bx += xDir;
			}

			if (map[By + yDir][Bx + xDir] == 'O')
				return false;
			else
				return true;
		}
		
		while (map[By + yDir][Bx + xDir] == '.') {
			By += yDir; Bx += xDir;
		}
		if (map[By + yDir][Bx + xDir] == 'O')
			return false;
		else {
			if (r.first == Ry && r.second == Rx && b.first == By && b.second == Bx)
				return false;
			if (By == Ry && Bx == Rx) {
				By -= yDir; Bx -= xDir;
			}
			r.first = Ry; r.second = Rx;
			b.first = By; b.second = Bx;
			
			rQueue.push(r);
			bQueue.push(b);

			return false;
		}
	}

	else {//파란색 먼저
		while (map[By + yDir][Bx + xDir] == '.') {
			By += yDir; Bx += xDir;
		}

		if (map[By + yDir][Bx + xDir] == 'O')
			return false;

		else {
			while (map[Ry + yDir][Rx + xDir] == '.') {
				Ry += yDir; Rx += xDir;
			}

			if (map[Ry + yDir][Rx + xDir] == 'O')
				return true;
			else {
				if (r.first == Ry && r.second == Rx && b.first == By && b.second == Bx)
					return false;

				if (By == Ry && Bx == Rx) {
					Ry -= yDir; Rx -= xDir;
				}
				r.first = Ry; r.second = Rx;
				b.first = By; b.second = Bx;

				rQueue.push(r);
				bQueue.push(b);
				
				return false;
			}
		}
	}
}

void bfs() {
	int i, t;
	int cnt = 1;

	rQueue.push(red);
	bQueue.push(blue);

	while (cnt <= 10) {
		int qSize = rQueue.size();//어차피 빨간색이랑 파랑색 큐 크기는 같으므로 이걸로 써도 된다.

		for (t = 0; t < qSize; t++) {
			red = rQueue.front();
			blue = bQueue.front();
			rQueue.pop();
			bQueue.pop();

			//움직이는 방향의 벽 쪽에 더 가까운 구슬을 먼저 움직인다.
			for (i = 0; i < 4; i++) {
				bool result;
				if (i == 0) {//북
					if (red.first < blue.first)
						result = moveMap(i, red, blue, true);
					else
						result = moveMap(i, red, blue, false);
				}
				
				if (i == 1) {//동
					if (red.second > blue.second)
						result = moveMap(i, red, blue, true);
					else
						result = moveMap(i, red, blue, false);
				}
				
				if (i == 2) {//남
					if (red.first > blue.first)
						result = moveMap(i, red, blue, true);
					else
						result = moveMap(i, red, blue, false);
				}
				
				if (i == 3) {//서
					if (red.second < blue.second)
						result = moveMap(i, red, blue, true);
					else
						result = moveMap(i, red, blue, false);
				}
				
				if (result) {//탈출 조건
					cout << cnt << '\n';
					return;
				}
			}
		}
		cnt++;
	}

	cout << -1 << '\n';
}

int main() {
	int i, j;
	

	cin >> n >> m;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') {
				blue.first = i; blue.second = j;
				map[i][j] = '.';
			}
			if (map[i][j] == 'R') {
				red.first = i; red.second = j;
				map[i][j] = '.';
			}
		}
	}

	bfs();

	return 0;
}
