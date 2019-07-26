#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[10001][10];
int init[10001];
int fin[10001];
int N;

int dfs(int n, int left) {
	int& ret = dp[n][left];
	if (dp[n][left] != -1)
		return ret;

	int rotate;//회전 수 기록
	int now = (init[n] + left) % 10;//n 위치에서 현재 위치(left 적용)
	int nowLeft;

	if (n == N)
		return ret = 0;

	//오른쪽으로 돌렸을 때, left 수 유지, 수가 줄어든다
	rotate = now >= fin[n] ? now - fin[n] : 10 + now - fin[n];
	nowLeft = left;

	ret = rotate + dfs(n + 1, nowLeft);

	//왼쪽으로 돌렸을 때, 수가 늘어난다.
	rotate = (now <= fin[n]) ? fin[n] - now : 10 + fin[n] - now;
	nowLeft = (left + rotate) % 10;
	
	ret = min(ret, rotate + dfs(n + 1, nowLeft));

	return ret;
}

void trackAnswer(int n, int left) {
	if (n == N)
		return;
	int now = (init[n] + left) % 10;//n 위치에서 현재 위치(left 적용)
	int nowLeft;
	int rotate;
	bool flag = true;

	//왼쪽
	rotate = (now <= fin[n]) ? fin[n] - now : 10 + fin[n] - now;
	nowLeft = (left + rotate) % 10;
	if (dfs(n, left) == (rotate + dfs(n + 1, nowLeft))) {
		if (rotate != 0)
			printf("%d %d\n", n + 1, rotate);
		trackAnswer(n + 1, nowLeft);
		flag = false;
	}

	//오른쪽
	rotate = now >= fin[n] ? now - fin[n] : 10 + now - fin[n];
	nowLeft = left;
	if (dfs(n, left) == (rotate + dfs(n + 1, nowLeft)) && flag) {
		if (rotate != 0)
			printf("%d -%d\n", n + 1, rotate);
		trackAnswer(n + 1, nowLeft);
	}
}

int main() {
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%1d", &init[i]);

	for (i = 0; i < N; i++)
		scanf("%1d", &fin[i]);

	for (i = 0; i < N; i++) {
		for (j = 0; j < 10; j++) {
			dp[i][j] = -1;
			//choice[i][j] = -1;
		}
	}

	printf("%d\n", dfs(0, 0));
	trackAnswer(0, 0);

	return 0;
}
