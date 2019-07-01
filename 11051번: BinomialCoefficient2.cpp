#include <iostream>
#include <algorithm>
using namespace std;

int dp[1002][1003];
int n, k;

int calc(int n, int k){
	if (k == 0 || k == n) 
		return 1;
	
	if (dp[n][k] != 0)
		return dp[n][k];

	int result;

	result = (calc(n - 1, k - 1) + calc(n - 1, k))%10007;
	dp[n][k] = result;
	return result;
}

int main() {
	cin >> n >> k;

	cout << calc(n, k) << '\n';


	return 0;
}
