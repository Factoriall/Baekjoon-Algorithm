#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100001];
int n;

long long dac(int s, int e) {
	if (s == e)
		return 0;
	if (s + 1 == e)
		return arr[s]*arr[s];
	int mid = (e + s) / 2;

	long long result = max(dac(s, mid), dac(mid, e));
	long int l = mid;
	long int r = mid;
	long long h = arr[mid];
	long long w = arr[mid];
	while (l >= s && r <= e-1) {
		int p = l > s ? min(h, arr[l - 1]) : -1;
		int q = r < e-1 ? min(h, arr[r + 1]) : -1;
		if (p > q) {
			w += arr[--l];
			h = p;
		}
		else {
			w += arr[++r];
			h = q;
		}
		result = max(result, w*h);
	}
	return result;
}

int main() {
	int i;

	cin >> n;
	for (i = 0; i < n; i++)
		cin >> arr[i];

	cout << dac(0, n) << endl;
	return 0;
}