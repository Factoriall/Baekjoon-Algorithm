#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	bool cmp[500][500] = { 0 };
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cmp[a - 1][b - 1] = true;
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (cmp[i][k] && cmp[k][j])
					cmp[i][j] = true;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << cmp[i][j] << ' ';
		}
		cout << '\n';
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int flag = true;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (!cmp[i][j] && !cmp[j][i]) {
				flag = false;
				break;
			}
		}
		if (flag)
			cnt++;
	}

	cout << cnt << '\n';

	return 0;
}
