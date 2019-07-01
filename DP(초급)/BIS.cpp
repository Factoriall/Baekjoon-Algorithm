#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int arr[1001];//����� �迭
	int dp[1001];//�޸������̼� �� �迭
	int i, j;
	int ans = 0;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//��ġ i �� ���ؼ� �� �� ��ġ j�� arr ��, arr[i]>arr[j]�� �����Լ� ����
	//dp[i]�� �� �����Լ��� �����Ǵ� �� �� ���� ū ���� �����Ѵ�.
	for (i = 0; i < n; i++) {
		int maxNum = 0;
		for (j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				maxNum = max(maxNum, dp[j]);
			}
		}
		dp[i] = maxNum + arr[i];
		ans = max(ans, dp[i]);//�׻� ���� ���� �´� ���� �ƴϹǷ� �� ������ üũ!
	}

	/*for (i = 0; i < n; i++) {
		cout << dp[i] << '\t';
	}
	cout << '\n';*/
	cout << ans << '\n';

	return 0;
}