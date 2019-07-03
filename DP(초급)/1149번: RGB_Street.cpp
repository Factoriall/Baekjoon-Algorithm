#include <iostream>
#include <algorithm>
using namespace std;

int memo[1001][3];
int p[1001][3];

int dp(int t, int s) {
	if (t == 0)
		return p[0][s];
	if (memo[t][s] != -1)
		return memo[t][s];

	int result;
	if (s == 0)
		result = p[t][s] + min(dp(t - 1, 1), dp(t - 1, 2));
	if (s == 1) 
		result = p[t][s] + min(dp(t - 1, 0), dp(t - 1, 2));
	if (s == 2)
		result = p[t][s] + min(dp(t - 1, 0), dp(t - 1, 1));

	memo[t][s] = result;
	return result;
}

int main() {
	int i, j;
	int n;

	cin >> n;

	for (i = 0; i < n; i++) 
		cin >> p[i][0] >> p[i][1] >> p[i][2];

	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) {
			memo[i][j] = -1;
		}
	}
	
	cout << min(dp(n - 1, 0), min(dp(n - 1, 1), dp(n - 1, 2))) << '\;

	return 0;
}
