#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int g[4][8];

void clock(int n) {
	int tmp = g[n][7];
	for (int i = 7; i > 0; i--)
		g[n][i] = g[n][i - 1];
	g[n][0] = tmp;
}

void counterclock(int n) {
	int tmp = g[n][0];
	for (int i = 0; i < 7; i++)
		g[n][i] = g[n][i + 1];
	g[n][7] = tmp;
}

int main(){
	int K;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
			scanf("%1d", &g[i][j]);

	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int n, r;
		scanf("%d %d", &n, &r);
		n--;

		int rcnt = 0;//오른쪽 돌리는 톱니바퀴 개수
		int change;
		for (int rd = n + 1; rd < 4; rd++) {//오른쪽
			if (g[rd - 1][2] == g[rd][6])
				break;
			rcnt++;
		}
		int lcnt = 0;//왼쪽 돌리는 톱니바퀴 개수
		for (int ld = n - 1; ld >= 0; ld--) {//왼쪽
			if (g[ld + 1][6] == g[ld][2])
				break;
			lcnt++;
		}
		//printf("rcnt: %d, lcnt: %d\n", rcnt, lcnt);
		change = r;
		for (int t = 1; t <= lcnt; t++) {
			if (change == 1)
				counterclock(n - t);
			else
				clock(n - t);
			change = -change;//회전방향 변경
		}
		change = r;
		for (int t = 1; t <= rcnt; t++) {
			if (change == 1)
				counterclock(n + t);
			else
				clock(n + t);
			change = -change;//회전방향 변경
		}
		
		if (r == 1)
			clock(n);
		else
			counterclock(n);

		/*for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++)
				printf("%d", g[i][j]);
			printf("\n");
		}*/
	}

	printf("%d\n", g[0][0] + g[1][0] * 2 + g[2][0] * 4 + g[3][0] * 8);

	return 0;
}
