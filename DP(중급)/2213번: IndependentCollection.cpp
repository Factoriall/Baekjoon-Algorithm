#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[10000], child[10000], ans;
bool visited[10000];
int weight[10000];
int dp[10000][2];


void dfs(int n) {
	visited[n] = true;
	for (int next : adj[n]) {
		if (!visited[next]) {
			child[n].push_back(next);
			dfs(next);
		}
	}
}

int findWeight(int n, bool pe) {
	int& ret = dp[n][pe];
	if (ret != -1)
		return ret;

	int notpick = 0;
	int pick = -1;
	//기본적으로 자신이 선택 안될 경우는 어떤 상황에서도 가능하다
	for (int next : child[n]) {
		notpick += findWeight(next, false);
	}
	if (!pe) {//부모가 집합에 포함되지 않을 시 자신 포함 가능
		pick = weight[n];
		for(int next : child[n])
			pick += findWeight(next, true);
	}

	return ret = max(pick, notpick);
}

void trackAnswer(int n, bool pe) {
	int notpick = 0;
	int pick = -1;
	//기본적으로 자신이 선택 안될 경우는 어떤 상황에서도 가능하다
	for (int next : child[n]) {
		notpick += findWeight(next, false);
	}
	if (!pe) {//부모가 집합에 포함되지 않을 시 자신 포함 가능
		pick = weight[n];
		for (int next : child[n])
			pick += findWeight(next, true);
	}

	if (notpick < pick) {
		ans.push_back(n+1);
		for (int next : child[n])
			trackAnswer(next, true);
	}
	else {
		for (int next : child[n])
			trackAnswer(next, false);
	}
}

int main() {
	int i;
	int N;
	int u, v;

	scanf("%d", &N);
	for (i = 0; i < N; i++) 
		scanf("%d", &weight[i]);
	
	for (i = 0; i < N - 1; i++) {
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(0);

	for (i = 0; i < N; i++) {//초기화
		dp[i][0] = -1;
		dp[i][1] = -1;
	}

	printf("%d\n", findWeight(0, false));//부모 노드는 기본적으로 포함x

	trackAnswer(0, false);
	sort(ans.begin(), ans.end());
	for (i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);

	return 0;
}

