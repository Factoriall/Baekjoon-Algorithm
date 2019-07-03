#include <iostream>
#include <algorithm>
using namespace std;

int result;
int p[102][102];
int c[102][102];
int n;

int dir[4][2] = { {0,1}, {0,-1}, {1, 0}, {-1, 0} };//���� ��������

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
	for (k = 0; k < 4; k++) {//4���� ���� ħ�� �ȵ� ���� ���� �ִ��� Ȯ��
		if (c[i + dir[k][0]][j + dir[k][1]] > t)
			dfs(t, i + dir[k][0], j + dir[k][1]);
	}
}

int main() {
	int i, j;
	int t;
	int fin = 1;//�� �ȿö� ����


	cin >> n;

	//�Է�
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> p[i][j];
		}
	}

	for (t = 1; t <= 100; t++) {
		result = 0;
		copyMap(c, p);//�̸� copy�� �����ͼ� ���⿡ �湮ó������ �ϰ� �Ѵ�.
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (c[i][j] > t) {
					dfs(t, i, j);
					result++;
				}
			}
		}
		fin = max(fin, result);//���� ū �� üũ

		if (result == 0)//0�Ͻ� ��� ħ���� �����̹Ƿ� �� �� �ʿ� ����
			break;
	}
	cout << fin << '\n';

	return 0;
}