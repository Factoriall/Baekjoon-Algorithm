#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 102;

int dp[102][100002] = { 0 };//무게 몇에 대해 얻을 수 있는 최대 가치 기록
int value[MAX];
int weight[MAX];


int main() {
	int n;//물품 개수
	int k;//최대 무게
	int i, j;

	cin >> n >> k;
	
	for (i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];
	}
		
	
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= k; j++) {
			if (j >= weight[i])
				dp[i][j] = max(dp[i - 1][j], value[i] + dp[i - 1][j - weight[i]]);
			else
				dp[i][j] = dp[i-1][j];
		}
		
	}

	for (i = 0; i <= n; i++) {
		for (j = 0; j <= k; j++) {
			cout << dp[i][j] << '\t';
		}
		cout << '\n';
	}
	cout << '\n';

	cout << dp[n][k] << '\n';

	return 0;
}