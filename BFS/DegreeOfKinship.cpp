#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
bool kin[101][101];
int degree = 0;
int total;
int a, b;

void bfs() {
	int i, j;
	int level = 1;

	q.push(a);

	while (!q.empty()) {
		int qSize = q.size();

		for (i = 0; i < qSize; i++) {//level�� �����ϱ� ���� qSize��ŭ ���� ���� ����
			int h = q.front();
			q.pop();
			for (j = 1; j <= total; j++) {
				if (kin[h][j]) {//����Ǿ� �ִ��� üũ
					if (j == b) {//����ȴٸ� level ��� �� ����
						cout << level << '\n';
						return;
					}
					q.push(j);//���� �ȵɽ� push
					kin[h][j] = kin[j][h] = false;//�湮 üũ
				}
			}
		}
		level++;//���� �ø���
	}

	//������� ���Դٴ� ���� ������ ������ ������ ���ߴٴ� ��!
	cout << -1 << '\n';
	return;
}

int main() {
	int n;
	int i, j;

	cin >> total;
	cin >> a >> b;
	cin >> n;

	for (i = 1; i <= n; i++) {//���� �迭 ���·� ����
		int x, y;
		cin >> x >> y;
		kin[x][y] = kin[y][x] = true;
	}

	bfs();

	return 0;
}