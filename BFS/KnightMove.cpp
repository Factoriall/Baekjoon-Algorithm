#include <iostream>
#include <queue>
using namespace std;

pair<int, int> mv[8] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}, {-2, -1} };
//����Ʈ ���� ����

int len;
int map[300][300];
pair<int, int> knight;//����Ʈ ó�� ��ġ
pair<int, int> dest;//������
queue<pair<int, int>> q;

void print() {
	int i, j;
	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void bfs() {
	int t, i;
	int cnt = 1;

	q.push(knight);

	while (!q.empty()) {
		int qSize = q.size();
		for (t = 0; t < qSize; t++) {
			pair<int, int> point;
			point.first = q.front().first;
			point.second = q.front().second;
			q.pop();

			for (i = 0; i < 8; i++) {
				int y = point.first + mv[i].first;
				int x = point.second + mv[i].second;

				if (y >= 0 && x >= 0 && y < len && x < len) {
					if (map[y][x] == 2) {//������ ���޽� ��!
						cout << cnt << '\n';
						return;
					}
					if (map[y][x] == 0) {//�湮 ���� �� �� ��
						pair<int, int> next;
						next.first = y;
						next.second = x;
						q.push(next);
						map[y][x] = 1;//�湮 üũ
					}
				}
			}
		}
		//print();
		cnt++;
	}
}

int main() {
	int i, j, t;
	int T;
	
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> len;
		
		//�ʱ�ȭ
		for (i = 0; i < len; i++) {
			for (j = 0; j < len; j++) {
				map[i][j] = 0;
			}
		}

		cin >> knight.first >> knight.second;
		map[knight.first][knight.second] = 1;
		cin >> dest.first >> dest.second;

		if (dest.first == knight.first && dest.second == knight.second)//���� ��ġ ������ ������ �ʿ� ����
			cout << 0 << '\n';
		else {
			map[dest.first][dest.second] = 2;
			bfs();
		}

		while (!q.empty())//�߿�! �� ��� return ���� ť�� ���빰�� �������� �� �����Ƿ� ��� ���־��Ѵ�.
			q.pop();
	}


	return 0;
}