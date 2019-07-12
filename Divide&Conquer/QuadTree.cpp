#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int video[64][64];

void dac(int y, int x, int size) {
	int i, j;
	int first = video[y][x];
	bool isSame = true;

	for (i = y; i < y + size; i++) {
		for (j = x; j < x + size; j++) {
			if (first != video[i][j]) {
				isSame = false;
				break;
			}
		}
		if (!isSame)
			break;
	}

	if (isSame) 
		cout << first;
	else {
		cout << '(';
		int d = size / 2;
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 2; j++) {
				dac(y + (i*d), x + (j*d), d);
			}
		}
		cout << ')';
	}
}

int main() {
	int i, j;
	int n;
	cin >> n;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%1d", &video[i][j]);
		}
	}

	dac(0, 0, n);

	return 0;
}