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
	
	
	if (dp[k] != -1)//�̹� ���� dp�� ����� ���� �����´�
		return dp[k];

	int result = MAX;//������� 10000���� �۰ų� ���� ������ MAX�� �ѱ� �� ����.
	for (i = 0; i < n; i++) {
		if (k - coin[i] >= 0)//������ �Ǹ� �ȵ�
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

	if (result != MAX)//MAX�� ���´ٸ� ���� �� ���� ���� ���� ��.
		cout << result << '\n';
	else
		cout << -1 << '\n';

	return 0;
}