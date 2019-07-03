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
		if (graph[t][i] == 1 && !visited[i]) {//이동 가능하고(배열 체크) 방문 안했으면(사이클 체크) 방문 처리 후 dfs
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
		fill(visited, visited + 100, false);//visited 초기화
		dfs(i);
		for (j = 0; j < n; j++) {
			if (visited[j] == true)//방문한 것들 모두 넣기
				CanGo[i][j] = 1;
		}
	}

	for (i = 0; i < n; i++) {//결과
		for (j = 0; j < n; j++)
			cout << CanGo[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}