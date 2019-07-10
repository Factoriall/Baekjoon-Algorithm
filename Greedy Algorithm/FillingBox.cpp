#include <iostream>
#include <algorithm>
using namespace std;

long long int cubeNum[20];
long long int maxCube[20];

int main() {
	long long int l, w, h;
	long long int n;
	long long int i;

	cin >> l >> w >> h;
	cin >> n;

	long long int t = 1;
	long long int a = 0;
	while (t <= l && t <= w && t <= h) {
		maxCube[a++] = (l / t) * (w / t) * (h / t);
		t = t * 2;
	}

	for (i = 0; i < n; i++) {
		int p;
		cin >> p;
		cin >> cubeNum[p];
	}
	long long int total = 0;

	//for (i = a-1; i >= 0; i--) 
	//	cout << i << "-num: " << cubeNum[i] << ", max: " << maxCube[i] << endl;

	for (i = a-1; i >= 0; i--) {
		long long int rem = maxCube[i] - cubeNum[i] > 0 ? maxCube[i] - cubeNum[i] : 0;
		long long int num = maxCube[i] - rem;
		long long int mul = 1;

		long long int k = i;
		while (k >= 0) {
			maxCube[k] = maxCube[k] - mul * num > 0 ? maxCube[k] - mul * num : 0;
			mul *= 8;
			k--;
		}

		//cout << num << endl;
		total += num;
		if (maxCube[0] == 0) {
			cout << total << endl;
			break;
		}

		if (i == 0)
			cout << -1 << '\n';
	}

	return 0;
}