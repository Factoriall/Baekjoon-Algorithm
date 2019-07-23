#include <iostream>
//#include <algorithm>
using namespace std;

int n;
int maxH;

int tree[1000001];

void bsearch(int low, int high) {
	int i;
	long long t = 0;
	int mid = (low + high) / 2;

	for (i = 0; i < n; i++) {
		t = t + (tree[i] - mid > 0 ? tree[i] - mid : 0);
	}
	if (low == high) {
		if (t < maxH) {
			cout << mid - 1 << endl;
			return;
		}
		else {
			cout << mid << endl;
			return;
		}
	}

	if (t == maxH) {
		cout << mid << endl;
		return;
	}
	else if (t < maxH) 
		bsearch(low, mid);
	else 
		bsearch(mid + 1, high);
}

int main() {
	int i;
	
	//int high = 0;

	cin >> n >> maxH;

	for (i = 0; i < n; i++) {
		cin >> tree[i];
		//high = max(high, tree[i]);
	}

	bsearch(0, 1000000000);

	return 0;
}
