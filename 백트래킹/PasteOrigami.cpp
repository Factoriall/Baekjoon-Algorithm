#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 26;

int origami[10][10];
int matrixNum[5] = { 5,5,5,5,5 };
int result = INF;
int cnt = 0;

void dfs(int y, int x) {
	if (x == 10)
		dfs(y + 1, 0);
	if (y == 10) {
		result = min(result, cnt);
		return;
	}

	if (origami[y][x] == 0)
		dfs(y, x + 1);
	else {
		for (int t = 5; t > 0; t--) {
			if (y + t <= 10 && x + t <= 10) {
				bool isFinished = false;
				for (int i = y; i < y + t; i++) {
					for (int j = x; j < x + t; j++) {
						if (origami[i][j] == 0) {
							isFinished = true;
							break;
						}
					}
					if (isFinished)
						break;
				}
				if (!isFinished) {	
					if (matrixNum[t - 1] == 0)
						continue;

					matrixNum[t - 1]--;
					cnt++;
					for (int i = y; i < y + t; i++)
						for (int j = x; j < x + t; j++)
							origami[i][j] = 0;

					dfs(y, x + t);

					//백트래킹
					matrixNum[t - 1]++;
					for (int i = y; i < y + t; i++)
						for (int j = x; j < x + t; j++)
							origami[i][j] = 1;
					cnt--;
				}
			}
		}
	}
}

int main() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			scanf("%d", &origami[i][j]);


	dfs(0, 0);
	
	if (result == INF)
		printf("-1");
	else
		printf("%d", result);
	


	return 0;
}