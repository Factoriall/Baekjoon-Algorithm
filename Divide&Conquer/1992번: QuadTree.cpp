#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int video[64][64];

//y: 배열의 제일 위쪽 위치, x: 배열의 제일 왼쪽 위치, size: 배열의 크기
void dac(int y, int x, int size) {
	int i, j;
	int first = video[y][x];
	bool isSame = true;

	for (i = y; i < y + size; i++) {
		for (j = x; j < x + size; j++) {
			if (first != video[i][j]) {//다른게 있으면 isSame값 변경 및 탈출
				isSame = false;
				break;
			}
		}
		if (!isSame)
			break;
	}

	if (isSame) //같으면 first값 출력
		cout << first;
	else {//하나라도 다르면 4개로 쪼개기
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
			scanf("%1d", &video[i][j]);//띄어쓰기를 안하므로 하나씩 받아야한다.
		}
	}

	dac(0, 0, n);

	return 0;
}
