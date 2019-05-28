#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int card[100001];
int usedPnt[500001];

void reset() {
	int j;
	for (j = 1; j <= 500000; j++) {
		usedPnt[j] = 0;
	}
}

int main() {
	int i;
	int N, M;
	int ans = 1;

	cin >> N >> M;

	for (i = 1; i <= N; i++) {
		cin >> card[i];
	}

	int left = 1;
	int right = N / M;
	

	while (left <= right) {
		int cnt = 0;
		int start = 1;
		int mid = (right + left) / 2;
		reset();

		for (i = 1; i <= N; i++) {
			if (usedPnt[card[i]] != 0 && usedPnt[card[i]] >= start) {
				start = usedPnt[card[i]] + 1;
			}
			
			usedPnt[card[i]] = i;
			
			if (i + 1 - start == mid) {
				cnt++;
				start = i + 1;
			}
			if (cnt == M)
				break;
		}

		if (cnt == M) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	
	cout << ans << endl;

	return 0;
}