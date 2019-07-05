#include <iostream>
#include <queue>
using namespace std;

int w, h;

queue<int, int> d;


pair<int, int> dir[4] = { {0,1},{0,-1},{1,0},{-1,0} };
queue<pair<int, int>> person;
queue<pair<int, int>> fire;
char map[1000][1000];


/*void print(pair<int, int> p) {
	map[p.first][p.second] = '@';
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	map[p.first][p.second] = '.';
	cout << endl;
}*/

void bfs() {
	int y, x;
	int t, i;
	int cnt = 1;

	while (!person.empty()) {
		int fSize = fire.size();
		
		for (t = 0; t < fSize; t++) {
			y = fire.front().first;
			x = fire.front().second;
			fire.pop();

			for (i = 0; i < 4; i++) {
				int hDir = dir[i].first;
				int wDir = dir[i].second;

				if (map[y + hDir][x + wDir] == '.' || map[y + hDir][x + wDir] == '@') {
					pair<int, int> f;
					f.first = y + hDir;
					f.second = x + wDir;
					fire.push(f);
					map[y + hDir][x + wDir] = '*';
				}
			}
		}

		int pSize = person.size();
		for (t = 0; t < pSize; t++) {
			y = person.front().first;
			x = person.front().second;
			person.pop();

			if (y == h-1 || y == 0 || x == w-1 || x == 0) {
				cout << cnt << '\n';
				return;
			}
			for (i = 0; i < 4; i++) {
				int hDir = dir[i].first;
				int wDir = dir[i].second;

				if (map[y + hDir][x + wDir] == '.') {
					pair<int, int> p;
					p.first = y + hDir;
					p.second = x + wDir;
					person.push(p);
					map[y + hDir][x + wDir] = '@';
				}
			}
		}
		cnt++;
	}
	cout << "IMPOSSIBLE" << '\n';
}

int main() {
	int i, j, t;
	int T;
	

	cin >> T;

	for (t = 0; t < T; t++) {
		cin >> w >> h;

		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				map[i][j] = 0;
			}
		}

		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				cin >> map[i][j];
				if (map[i][j] == '@') {
					pair<int, int> p;
					p.first = i;
					p.second = j;

					person.push(p);
				}
				else if (map[i][j] == '*') {
					pair<int, int> f;
					f.first = i;
					f.second = j;

					fire.push(f);
				}
			}
		}
		
		bfs();

		while (!fire.empty())
			fire.pop();
		while (!person.empty())
			person.pop();
	}

	return 0;
}
