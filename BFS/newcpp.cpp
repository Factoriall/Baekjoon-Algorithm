#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0 ,0 };

int map[501][1001];

typedef struct {
	int p1y;
	int p1x;
	int p2y;
	int p2x;
	vector<int> prev;
}Tile;

queue<Tile> q;

void bfs() {
	Tile tmp;
	vector<int> biggest;
	int big = 1;
	tmp.p1y = 0; tmp.p1x = 0;
	tmp.p2y = 0; tmp.p2x = 1;
	tmp.prev.push_back(1);

	q.push(tmp);

	while (!q.empty()) {
		int qSize = q.size();
		for (int t = 0; t < qSize; t++) {
			int p1y = q.front().p1y; int p1x = q.front().p1x;
			int p2y = q.front().p2y; int p2x = q.front().p2x;
			vector<int> v = q.front().prev;
			q.pop();

			if (v[v.size() - 1] == n * n - n / 2) {//종료 조건
				cout << v.size() << endl;
				for (int i = 0; i < v.size(); i++) {
					cout << v[i] << ' ';
				}
				cout << endl;
				return;
			}

			Tile tmp;

			//cout << '(' << p1y << ',' << p1x << ')' << endl;
			
			//왼쪽 타일 대상
			if (p1x - 1 >= 0 && map[p1y][p1x - 1] != 0 && map[p1y][p1x - 1] == map[p1y][p1x]) {//왼쪽 이동
				tmp.prev = v;

				tmp.p2y = p1y; tmp.p2x = p1x - 1;
				tmp.p1y = p1y; tmp.p1x = p1x - 2;
				tmp.prev.push_back(v[v.size() - 1] - 1);

				if (big < tmp.prev[tmp.prev.size() - 1]) {
					big = tmp.prev[tmp.prev.size() - 1];
					biggest = tmp.prev;
				}

				q.push(tmp);

				/*for (int i = 0; i < tmp.prev.size(); i++) {
					cout << tmp.prev[i] << ' ';
				}
				cout << endl;*/
			}
			if (p1y - 1 >= 0 && map[p1y - 1][p1x] != 0 && map[p1y - 1][p1x] == map[p1y][p1x]) {//위 이동
				tmp.prev = v;

				tmp.p2y = p1y - 1; tmp.p2x = p1x;
				tmp.p1y = p1y - 1; tmp.p1x = p1x - 1;
				tmp.prev.push_back(v[v.size() - 1] - n);

				if (big < tmp.prev[tmp.prev.size() - 1]) {
					big = tmp.prev[tmp.prev.size() - 1];
					biggest = tmp.prev;
				}

				q.push(tmp);

				/*for (int i = 0; i < tmp.prev.size(); i++) {
					cout << tmp.prev[i] << ' ';
				}
				cout << endl;*/
			}
			if (p1y + 1 < n && map[p1y + 1][p1x] != 0 && map[p1y + 1][p1x] == map[p1y][p1x]) {//아래 이동
				tmp.prev = v;

				tmp.p2y = p1y + 1; tmp.p2x = p1x;
				tmp.p1y = p1y + 1; tmp.p1x = p1x - 1;
				tmp.prev.push_back(v[v.size() - 1] + n - 1);

				if (big < tmp.prev[tmp.prev.size() - 1]) {
					big = tmp.prev[tmp.prev.size() - 1];
					biggest = tmp.prev;
				}

				q.push(tmp);

				/*for (int i = 0; i < tmp.prev.size(); i++) {
					cout << tmp.prev[i] << ' ';
				}
				cout << endl;*/
			}

			//오른쪽 타일 대상
			if (p2x + 1 < 2 * n && map[p2y][p2x + 1] != 0 && map[p2y][p2x + 1] == map[p2y][p2x]) {//오른쪽 이동
				tmp.prev = v;

				tmp.p1y = p2y; tmp.p1x = p2x + 1;
				tmp.p2y = p2y; tmp.p2x = p2x + 2;
				tmp.prev.push_back(v[v.size() - 1] + 1);

				if (big < tmp.prev[tmp.prev.size() - 1]) {
					big = tmp.prev[tmp.prev.size() - 1];
					biggest = tmp.prev;
				}

				q.push(tmp);

				/*for (int i = 0; i < tmp.prev.size(); i++) {
					cout << tmp.prev[i] << ' ';
				}
				cout << endl;*/
			}
			if (p2y - 1 < n && map[p2y - 1][p2x] != 0 && map[p2y - 1][p2x] == map[p2y][p2x]) {//위 이동
				tmp.prev = v;

				tmp.p1y = p2y - 1; tmp.p1x = p2x;
				tmp.p2y = p2y - 1; tmp.p2x = p2x + 1;
				tmp.prev.push_back(v[v.size() - 1] - n + 1);

				if (big < tmp.prev[tmp.prev.size() - 1]) {
					big = tmp.prev[tmp.prev.size() - 1];
					biggest = tmp.prev;
				}

				q.push(tmp);

				/*for (int i = 0; i < tmp.prev.size(); i++) {
					cout << tmp.prev[i] << ' ';
				}
				cout << endl;*/
			}
			if (p2y + 1 < n && map[p2y + 1][p2x] != 0 && map[p2y + 1][p2x] == map[p2y][p2x]) {//아래 이동
				tmp.prev = v;

				tmp.p1y = p2y + 1; tmp.p1x = p2x;
				tmp.p2y = p2y + 1; tmp.p2x = p2x + 1;
				tmp.prev.push_back(v[v.size() - 1] + n);

				if (big < tmp.prev[tmp.prev.size() - 1]) {
					big = tmp.prev[tmp.prev.size() - 1];
					biggest = tmp.prev;
				}

				q.push(tmp);

				/*for (int i = 0; i < tmp.prev.size(); i++) {
					cout << tmp.prev[i] << ' ';
				}
				cout << endl;*/
			}
			
			map[p1y][p1x] = 0;
			map[p2y][p2x] = 0;
		}

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2 * n; j++) {
				cout << map[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;*/
	}

	cout << biggest.size() << endl;
	for (int i = 0; i < biggest.size(); i++) {
		cout << biggest[i] << ' ';
	}
	cout << endl;
}

int main() {
	int i, j;


	cin >> n;
	int tile = n * n - n / 2;

	for (i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (j = 0; j < 2 * n; j = j + 2) {
				cin >> map[i][j] >> map[i][j + 1];
			}
		}
		else {
			for (j = 1; j < 2 * n - 1; j = j + 2) {
				cin >> map[i][j] >> map[i][j + 1];
			}
		}
	}

	/*for (i = 0; i < n; i++) {
		for (j = 0; j < 2 * n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;*/

	bfs();

	for (i = 0; i < n; i++) {
		for (j = 0; j < 2 * n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}