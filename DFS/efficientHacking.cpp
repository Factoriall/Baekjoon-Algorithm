#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> adjs;
bool visited[10000];
int n, m;

int dfs(int now);

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		vector<int> adj;
		adjs.push_back(adj);
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adjs[b - 1].push_back(a - 1);
	}

	vector<int> ansList;
	int maxCnt = 0;
	for (int i = 0; i < n; i++) {
		memset(visited, false, sizeof(visited));
		int ret = dfs(i);
		if (maxCnt < ret) {
			maxCnt = ret;
			ansList.clear();
			ansList.push_back(i+1);
		}
		else if (maxCnt == ret) {
			ansList.push_back(i+1);
		}
	}

	for (int ans : ansList) {
		printf("%d ", ans);
	}
}

int dfs(int now) {
	visited[now] = true;

	int answer = 0;
	for (int next : adjs[now]) {
		if(!visited[next])answer += dfs(next);
	}
	return answer + 1;
}

