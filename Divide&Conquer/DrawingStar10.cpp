#include <iostream>
using namespace std;

char map[6561][6561];

void dac(int y, int x, int n) {
	int i, j;
	int d = n / 3;
	if (n == 1) {
		map[y][x] = '*';
		return;
	}
	for (i = y; i < y + n; i = i + d) {
		for (j = x; j < x + n; j = j + d) {
			if (i == y + d && j == x + d) {
				for (int a = i; a < i + d; a++) {
					for (int b = j; b < j + d; b++) {
						map[a][b] = ' ';
					}
				}
			}
			else
				dac(i, j, d);
		}
	}
}

int main() {
	int i, j;
	int n;
	cin >> n;

	dac(0, 0, n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}

	return 0;
}