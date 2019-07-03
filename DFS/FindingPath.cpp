#include <iostream>
#include <algorithm>
using namespace std;

int n;
bool visited[100];
int graph[100][100];
int CanGo[100][100];

void dfs(int t) {
	int i;
	for (i = 0; i < n; i++) {
		if (graph[t][i] == 1 && !visited[i]) {//�̵� �����ϰ�(�迭 üũ) �湮 ��������(����Ŭ üũ) �湮 ó�� �� dfs
			visited[i] = true;
			dfs(i);
		}
	}
}

int main() {
	int i, j;

	cin >> n;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			cin >> graph[i][j];
	}

	for (i = 0; i < n; i++) {
		fill(visited, visited + 100, false);//visited �ʱ�ȭ
		dfs(i);
		for (j = 0; j < n; j++) {
			if (visited[j] == true)//�湮�� �͵� ��� �ֱ�
				CanGo[i][j] = 1;
		}
	}

	for (i = 0; i < n; i++) {//���
		for (j = 0; j < n; j++)
			cout << CanGo[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}