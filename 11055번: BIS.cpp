#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int arr[1001];//100
	int dp[1001];
	int i, j;
	int ans = 0;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (i = 0; i < n; i++) {
		int maxNum = 0;
		for (j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				maxNum = max(maxNum, dp[j]);
			}
		}
		dp[i] = maxNum + arr[i];
		ans = max(ans, dp[i]);
	}

	/*for (i = 0; i < n; i++) {
		cout << dp[i] << '\t';
	}
	cout << '\n';*/
	cout << ans << '\n';

	return 0;
}
