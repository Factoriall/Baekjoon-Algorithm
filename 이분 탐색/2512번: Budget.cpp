#include <iostream>
using namespace std;

int region[10001];

int main() {
	int n;
	int maxB;
	int lo = 0;
	int hi = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> region[i];
		hi = (hi < region[i] ? region[i] : hi);
	}
	hi++;
	cin >> maxB;

	while (lo+1 < hi) {
		int mid = (hi + lo) / 2;
		int total = 0;
		for (int i = 0; i < n; i++) {
			total += (region[i] < mid ? region[i] : mid);
		}
		if (total > maxB)
			hi = mid;
		else
			lo = mid;
	}
	cout << lo << '\n';

	return 0;
}
