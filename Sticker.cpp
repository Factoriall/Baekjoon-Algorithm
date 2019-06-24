#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100001;

int N;//���� ����
int dp[MAX][3];
int arr[2][MAX];

int sticker(int c, int s) {
	if (c == N)
		return 0;

	if (dp[c][s] != -1)
		return dp[c][s];

	int result = sticker(c + 1, 0);//�ϳ��� �� ���� ���� ��츦 result�� ����

	if (s != 1)//���� �� ���� �������� �ʾҴٸ� �� ���� �ִ� �͵� ����
		result = max(result, arr[1][c]+sticker(c + 1, 1));
	if (s != 2)//���� �Ʒ� ���� �������� �ʾҴٸ� �� ���� �ִ� �͵� ����
		result = max(result, arr[0][c]+sticker(c + 1, 2));

	dp[c][s] = result;
	return result;
}

int main() {
	int num;//�ݺ� Ƚ��
	int t, i, j;

	cin >> num;
	for (t = 0; t < num; t++) {
		cin >> N;
		for (i = 0; i < 2; i++) {
			for (j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < 3; j++) {
				dp[i][j] = -1;
			}
		}
		cout << sticker(0, 0) << '\n';
	}

	return 0;
}