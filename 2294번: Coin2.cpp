#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 10001;
int n;

int coin[101];
int dp[MAX];

int coinCnt(int k) {
	int i;
	if (k == 0)//base
		return 0;
	
	
	if (dp[k] != -1)//이미 계산시 dp에 저장된 것을 가져온다
		return dp[k];

	int result = MAX;//결과값은 10000보다 작거나 같기 때문에 MAX를 넘길 수 없다.
	for (i = 0; i < n; i++) {
		if (k - coin[i] >= 0)//음수가 되면 안됨
			result = min(result, coinCnt(k - coin[i]) + 1);
	}

	dp[k] = result;
	return result;
}

int main() {
	int k;
	int i;
	int result;

	cin >> n >> k;
	for (i = 0; i < n; i++)
		cin >> coin[i];

	fill(dp, dp + MAX, -1);
	result = coinCnt(k);

	if (result != MAX)//MAX값 나온다면 나올 수 없는 값이 나온 것.
		cout << result << '\n';
	else
		cout << -1 << '\n';

	return 0;
}
