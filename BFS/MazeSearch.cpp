#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
int map[102][102];

int n, m;
pair<int, int> dir[4] = { {0,1}, {-1, 0}, {1, 0}, {0, -1} };//���� ��������
queue<pair<int, int>> q;

void bfs() {
	int t, i;
	int cnt = 1;
	pair<int, int> point;
	point.first = 1;
	point.second = 1;
	q.push(point);

	while (!q.empty()) {
		int qSize = q.size();
		for (t = 0; t < qSize; t++) {
			point.first = q.front().first;
			point.second = q.front().second;
			//cout << "pop: [" << point.first << ", " << point.second << ']' << endl;
			q.pop();

			for (i = 0; i < 4; i++) {//4���� Ž��
				int y = point.first + dir[i].first;
				int x = point.second + dir[i].second;
				if (y == n && x == m) {//������ ����
					cout << cnt + 1 << '\n';
					return;
				}
				if (map[y][x] == 1) {//�湮 ���� ���� Ž�� ��
					pair<int, int> tmp;
					tmp.first = y;
					tmp.second = x;
					//cout << "push: [" << tmp.first << ", " << tmp.second << ']' << endl;
					q.push(tmp);
					map[y][x] = 0;
				}
			}
		}
		cnt++;
	}
}

int main() {
	int i, j;
	

	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);//�߿�! �� ���ھ� �ް� ���� �� ����Ѵ�.
		}
	}
	bfs();
	
	return 0;
}