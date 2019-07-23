#include <iostream>
using namespace std;

int daily[100001];

int main() {
	int i, j;
	int n, m;

	cin >> n >> m;

	for (i = 0; i < n; i++) 
		cin >> daily[i];
	
	int lo = 0;
	int hi = 1000000000;
	
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		bool isImpossible = false;
		int cnt = 0;
		int total = 0;

		for (i = 0; i < n; i++) {
			if (daily[i] > mid) {
				isImpossible = true;
				break;
			}

			total += daily[i];
			if (total > mid) {
				total = daily[i];
				cnt++;
			}

			if (cnt >= m)
				break;
		}
		cnt++;
		//cout << "mid: " << mid << ", cnt: " << cnt << endl;

		if (cnt > m || isImpossible)
			lo = mid;
		else
			hi = mid;
	}
	
	cout << hi << '\n';

	return 0;
}