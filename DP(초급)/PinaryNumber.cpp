#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long int dp[91][2];
	dp[1][0] = 0; dp[1][1] = 1;
	
	int N;
	int i;

	cin >> N;

	for (i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[N][0] + dp[N][1] << '\n';


	return 0;
}