#include <iostream>
using namespace std;

int lesson[100001];

int main() {
	int i;
	int n, m;
	cin >> n >> m;

	for (i = 0; i < n; i++) 
		cin >> lesson[i];
	
	int hi = 1000000000;
	int lo = 0;

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int cnt = 0;
		int total = 0;
		bool isImpossible = false;

		for (i = 0; i < n; i++) {
			total += lesson[i];
			if (total > mid) {
				cnt++;
				total = lesson[i];
				if (lesson[i] > mid) {
					isImpossible = true;
					break;
				}
			}
			if (cnt >= m)
				break;
		}
		cnt++;
		cout << "low: " << lo << ", high: " << hi << endl;
		cout << "mid:" << mid << endl;
		cout << cnt << endl;
		if (cnt > m || isImpossible)
			lo = mid;
		else
			hi = mid;
	}

	cout << hi << '\n';

	return 0;
}
