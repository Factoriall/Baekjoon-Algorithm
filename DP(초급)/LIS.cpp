#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int dp[1001];
	int arr[1001];
	int n;
	int i,j;
	int ans = 0;

	cin >> n;
	for (i = 0; i < n; i++)
		cin >> arr[i];

	for (i = 0; i < n; i++) {
		int maxNum = 0;
		for (j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				maxNum = max(maxNum, dp[j]);
			}
		}
		dp[i] = maxNum + 1;
		ans = max(dp[i], ans);
	}
	
		
	cout << ans << '\n';

	return 0;
}