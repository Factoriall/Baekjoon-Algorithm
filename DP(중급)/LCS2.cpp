#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string l1;
string l2;
int dp[1002][1002];
bool flag;

int dfs(int p1, int p2) {
	if (dp[p1][p2] != -1) {
		return dp[p1][p2];
	}
	if (p1 == l1.size() || p2 == l2.size()) 
		return 0;

	int ret = max(dfs(p1 + 1, p2), dfs(p1, p2 + 1));
	if (l1[p1] == l2[p2])
		ret = max(ret, 1 + dfs(p1 + 1, p2 + 1));

	
	dp[p1][p2] = ret;
	return ret;
}

void trackAnswer(int p1, int p2, int cnt, vector<char> v) {
	if (flag)
		return;
	if ((p1 == l1.size() || p2 == l2.size()) && cnt == dfs(0,0)) {
		for (int i = 0; i < v.size(); i++)
			printf("%c", v[i]);
		flag = true;
		return;
	}

	if (l1[p1] == l2[p2] && 1 + dfs(p1 + 1, p2 + 1) == dfs(p1, p2)) {
		v.push_back(l1[p1]);
		trackAnswer(p1 + 1, p2 + 1, cnt + 1, v);
	}
	
	if (dfs(p1 + 1, p2) == dfs(p1, p2))
		trackAnswer(p1 + 1, p2, cnt, v);
	else if (dfs(p1, p2 + 1) == dfs(p1, p2))
		trackAnswer(p1, p2 + 1, cnt, v);
}

int main() {
	int i, j;
	ios::sync_with_stdio(false);
	vector<char> v;

	cin >> l1 >> l2;


	for (i = 0; i <= l1.size(); i++) {
		for (j = 0; j <= l2.size(); j++) {
			dp[i][j] = -1;
		}
	}

	
	printf("%d\n", dfs(0, 0));
	trackAnswer(0, 0, 0, v);
	printf("\n");
	for (i = 0; i <= l1.size(); i++) {
		for (j = 0; j <= l2.size(); j++) {
			printf("%d\t", dp[i][j]);
		}
		printf("\n");
	}

	return 0;
}