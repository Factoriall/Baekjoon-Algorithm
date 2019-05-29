#include <iostream>
using namespace std;

int arr[100000];
int n;

int find() {
	int i;
	int cnt = 0;
	int down = 0;


	for (i = 0; i < n-1; i++) {
		if (arr[i] > arr[i + 1]) {//µÞ ¼ö°¡ ´õ ÀÛÀº °æ¿ì
			down++;
			if (down > 1) {
				return 0;
			}

			if (i < n - 2 && arr[i] <= arr[i + 2])
				cnt++;
			if (i > 0 && arr[i - 1] <= arr[i + 1])
				cnt++;
			if (i == n - 2)
				cnt++;
			if (i == 0)
				cnt++;
		}
	}

	if (down == 0)
		cnt = n;

	return cnt;
}

int main() {
	int i;
	int result;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	result = find();

	cout << result << endl;

	return 0;
}


