#include <iostream>
#include <algorithm>
using namespace std;

int H[100001];

int dac(int s, int e) {
	if (s == e)
		return 0;
	else if (s + 1 == e)
		return H[s];

	int mid = (s + e) / 2;
	int result = max(dac(s, mid), dac(mid, e));

	int h = H[mid];
	int w = 1;
	int l = mid;
	int r = mid;

	while (l != s || r != e - 1) {
		int lh = l > s ? min(H[l-1], h) : -1;
		int rh = r < e - 1 ? min(H[r+1], h) : -1;
		if (lh > rh) {
			l--;
			h = lh;
		}
		else {
			r++;
			h = rh;
		}
		w++;
		//cout << "s: " << s << ", e: " << e << endl;
		//cout << "l: " << l << ", r: " << r << endl;
		//cout << "mid: "<<mid <<", w: " << w << ", h: " << h << endl;
		result = max(result, w*h);
	}
	return result;
}

int main() {
	int i;
	int n;
	cin >> n;

	for (i = 0; i < n; i++) 
		cin >> H[i];

	cout << dac(0, n) << '\n';

	return 0;
}
