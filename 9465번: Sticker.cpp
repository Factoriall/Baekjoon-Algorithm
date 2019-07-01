#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100001;

int N;//행의 개수
int dp[MAX][3];
int arr[2][MAX];

int sticker(int c, int s) {
	if (c == N)
		return 0;

	if (dp[c][s] != -1)
		return dp[c][s];

	int result = sticker(c + 1, 0);//하나도 안 떼고 가는 경우를 result로 정의

	if (s != 1)//만약 위 것이 찢어지지 않았다면 그 옆에 있는 것도 존재
		result = max(result, arr[1][c]+sticker(c + 1, 1));
	if (s != 2)//만약 아래 것이 찢어지지 않았다면 그 옆에 있는 것도 존재
		result = max(result, arr[0][c]+sticker(c + 1, 2));

	dp[c][s] = result;
	return result;
}

int main() {
	int num;//반복 횟수
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
