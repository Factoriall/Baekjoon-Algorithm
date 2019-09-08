#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int lad[30][9];//0: 사용 안함, 1: 사다리, -1: 처음부터 설치 못함, -2:나중에 들어가는 설치 못하는 곳.
int result = 4;
int N, M, H;


void printmap(int map[30][9]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N - 1; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void copymap(int copy[30][9], int origin[30][9]) {
	for (int i = 0; i < H; i++)
		for (int j = 0; j < N - 1; j++)
			copy[i][j] = origin[i][j];
}

bool check(int map[30][9]) {
	int pnt[10];
	for (int i = 0; i < N; i++)
		pnt[i] = i;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				int tmp = pnt[j];
				pnt[j] = pnt[j + 1];
				pnt[j + 1] = tmp;
			}
		}
	}

	/*for (int i = 0; i < N; i++) {
		printf("%d ", pnt[i]);
	}
	printf("\n");*/

	for (int i = 0; i < N; i++) {
		if (pnt[i] != i)
			return false;
	}
	
	return true;
}



void dfs(int n, int a, int b) {
	if (n > 3)
		return;
	
	lad[a][b] = 1;
	if (b > 0 && lad[a][b-1] == 0)
		lad[a][b - 1] = -2;
	if (b < N - 2 && lad[a][b + 1] == 0)
		lad[a][b + 1] = -2;
	if (check(lad)) {
		result = min(result, n);
		return;
	}
	//printmap(lad);

	for (int i = a; i < H; i++) {
		int j = 0;
		if (i == a && b < N - 2)
			j = b + 1;
		while (j < N - 1) {
			if (lad[i][j] == 0) {
				dfs(n + 1, i, j);
				//백트래킹
				lad[i][j] = 0;
				if (j > 0 && lad[i][j - 1] == -2)
					lad[i][j - 1] = 0;
				if (j < N - 2 && lad[i][j + 1] == -2)
					lad[i][j + 1] = 0;
			}
			j++;
		}
	}
}

int main() {

	scanf("%d %d %d", &N, &M, &H);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		lad[a - 1][b - 1] = 1;

		if (b > 1)
			lad[a - 1][b - 2] = -1;
		if (b < N - 1)
			lad[a - 1][b] = -1;
	}
	

	if (check(lad)) {
		printf("0\n");
		return 0;
	}
	else 
		for (int i = 0; i < H; i++) 
			for (int j = 0; j < N - 1; j++) 
				if (lad[i][j] == 0) {
					if(lad[i][j] != -1)
					dfs(1, i, j);
					//백트래킹
					lad[i][j] = 0;
					if (j > 0 && lad[i][j - 1] == -2)
						lad[i][j - 1] = 0;
					if (j < N - 2 && lad[i][j + 1] == -2)
						lad[i][j + 1] = 0;
				}

	if (result == 4)
		printf("-1\n");
	else
		printf("%d\n", result);

	return 0;
}
