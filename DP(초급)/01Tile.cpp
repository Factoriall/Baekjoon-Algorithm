#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 15746;
int dp[1000001];

int main() {
	int n;
	
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
	}

	cout << dp[n] << endl;

	return 0;
}