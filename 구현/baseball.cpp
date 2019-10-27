#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int maxScore = 0;
int N;
int hit[50][9];
int list[9];

void simulation() {
	int battingNum = 0;
	int score = 0;

	for (int i = 0; i < N; i++) {
		int out = 0;
		bool base[3] = { false, false, false };
		while (out != 3) {
			switch(hit[i][list[battingNum] - 1]) {
			case 0:
				out++;
				break;
			case 1:
				if (base[2]) {
					score++;
					base[2] = false;
				}
				if (base[1]) {
					base[2] = true;
					base[1] = false;
				}
				if (base[0]) {
					base[1] = true;
					base[0] = false;
				}
				base[0] = true;
				break;
			case 2:
				if (base[2]) {
					score++;
					base[2] = false;
				}
				if (base[1]) {
					score++;
					base[1] = false;
				}
				if (base[0]) {
					base[2] = true;
					base[0] = false;
				}
				base[1] = true;
				break;
			case 3:
				if (base[2]) {
					score++;
					base[2] = false;
				}
				if (base[1]) {
					score++;
					base[1] = false;
				}
				if (base[0]) {
					score++;
					base[0] = false;
				}
				base[2] = true;
				break;
			case 4:
				if (base[2]) {
					score++;
					base[2] = false;
				}
				if (base[1]) {
					score++;
					base[1] = false;
				}
				if (base[0]) {
					score++;
					base[0] = false;
				}
				score++;
				break;
			}
			battingNum++;
			if (battingNum == 9)
				battingNum = 0;
		}
	}

	maxScore = max(maxScore, score);
}

void dfs(int n) {
	if (n == 10) {
		simulation();
		return;
	}
	
	for (int j = 0; j < 9; j++) {
		if (list[j] == 0) {
			list[j] = n;
			dfs(n + 1);
			list[j] = 0;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < 9; j++) 
			scanf("%d", &hit[i][j]);
	
	list[3] = 1;
	dfs(2);

	printf("%d\n", maxScore);

	return 0;
}