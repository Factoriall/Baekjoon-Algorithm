#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int arr[1001];//저장용 배열
	int dp[1001];//메모이제이션 용 배열
	int i, j;
	int ans = 0;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//위치 i 에 대해서 그 전 위치 j랑 arr 비교, arr[i]>arr[j]면 증가함수 성립
	//dp[i]엔 그 증가함수가 성립되는 것 중 가장 큰 것을 저장한다.
	for (i = 0; i < n; i++) {
		int maxNum = 0;
		for (j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				maxNum = max(maxNum, dp[j]);
			}
		}
		dp[i] = maxNum + arr[i];
		ans = max(ans, dp[i]);//항상 끝의 것이 맞는 것이 아니므로 할 때마다 체크!
	}

	/*for (i = 0; i < n; i++) {
		cout << dp[i] << '\t';
	}
	cout << '\n';*/
	cout << ans << '\n';

	return 0;
}