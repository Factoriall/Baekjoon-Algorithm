#include <iostream>
#include <algorithm>
using namespace std;

bool visited[1001];
bool finished[1001];
int pick[1001];
int compo[1001];
int comNum = 1;

int vertex[1001];//컴포넌트 i 내의 정점의 수
int cycle[1001];//컴포넌트 i 내의 사이클 형성 정점 수

pair<int, int> dp[1001][1001];//first-최소, second-최대


void dfs(int t) {//dfs 통해 컴포넌트 내 사이클 수 및 전체 정점 개수를 구한다.
	visited[t] = true;
	int next = pick[t];

	if (visited[next]) {
		if (!finished[next]) {
			int c = 0;
			for (int tmp = next; tmp != t; tmp = pick[tmp]) {
				compo[tmp] = comNum;
				c++;
			}
			compo[t] = comNum;

			vertex[comNum] = cycle[comNum] = c + 1;
			comNum++;
		}
		else {
			if (compo[t] == 0) {
				compo[t] = compo[next];
				vertex[compo[next]]++;
			}
		}
	}
	else {
		dfs(next);
		if (compo[t] == 0) {
			compo[t] = compo[next];
			vertex[compo[next]]++;
		}
	}

	finished[t] = true;
}

int main() {
	
	int n, k;
	int i, j;

	cin >> n >> k;

	for (i = 1; i <= n; i++)
		cin >> pick[i];

	//사이클 및 컴포넌트 수 찾기
	for (i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	//for (i = 1; i < comNum; i++)
	//	cout << "컴포넌트 수: " << vertex[i] << ", 사이클 수: " << cycle[i] << endl;

	//dp과정, 냅색문제와 비슷하나 사이클 수가 최소이며 전체 컴포넌트의 정점 수가 최대로, 
	//일단 사이클이 들어가야 하고 들어간 후에는 최대값이 최대로 태울 수 있는 사람의 수이다.
	for (i = 1; i < comNum; i++) {
		for (j = 1; j <= k; j++) {
			if (j >= cycle[i]) {
				dp[i][j].first = max(dp[i - 1][j].first, cycle[i] + dp[i - 1][j - cycle[i]].first);
				
				if (dp[i][j].first == dp[i - 1][j].first)
					dp[i][j].second = dp[i - 1][j].second;
				else {
					int a = dp[i - 1][j - cycle[i]].second + vertex[i];
					dp[i][j].second = min(k, a);
				}
			}
			else {
				dp[i][j].first = dp[i - 1][j].first;
				dp[i][j].second = dp[i - 1][j].second;
			}
		}
	}

	cout << dp[comNum-1][k].second << '\n';//냅색문제와 동일하게 맨 오른쪽 아래 값이 최적의 값이다.

	return 0;
}