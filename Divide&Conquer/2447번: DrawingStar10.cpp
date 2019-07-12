#include <iostream>
using namespace std;

char map[6561][6561];

void dac(int y, int x, int n) {
	int i, j;
	int d = n / 3;
	if (n == 1) {//기저 조건
		map[y][x] = '*';
		return;
	}
	for (i = y; i < y + n; i = i + d) {
		for (j = x; j < x + n; j = j + d) {
			if (i == y + d && j == x + d) {//9개 나눈 것 중 제일 가운데만 공백으로 만든다.
				for (int a = i; a < i + d; a++) {
					for (int b = j; b < j + d; b++) {
						map[a][b] = ' ';
					}
				}
			}
			else
				dac(i, j, d);//나머지는 계속 분할
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
