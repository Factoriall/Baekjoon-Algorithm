#include <iostream>
#include <algorithm>
using namespace std;
int dp[101][10];

int main() {
	int n;
	int i,j;
	int result=0;
	
	cin >> n;

	for (i = 1; i < 10; i++)
		dp[1][i] = 1;

	for (i = 1; i < n; i++) {
		for (j = 0; j < 10; j++) {
			if (j == 0)
				dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % 1000000000;
			else if (j == 9)
				dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % 1000000000;
			else {
				dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % 1000000000;
				dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % 1000000000;
			}
		}
	}
	for (i = 0; i < 10; i++)
		result = (result + dp[n][i]) % 1000000000;

	cout << result << '\n';

	return 0;
}
