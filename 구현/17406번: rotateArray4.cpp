#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, K;
int map[50][50];
int rotateList[6][3];
int order[6];
bool isvisited[6];
int result = 987654321;

void rotate(int y, int x, int l, int arr[][50]) {
	int tmp = arr[y - l][x - l];
	for (int i = y - l + 1; i <= y + l; i++) {//¿ÞÂÊ 
		arr[i - 1][x - l] = arr[i][x - l];
	}
	for (int i = x - l + 1; i <= x + l; i++) {//¾Æ·¡ 
		arr[y + l][i - 1] = arr[y + l][i];
	}
	for (int i = y + l - 1; i >= y - l; i--) {//¿À¸¥ÂÊ
		arr[i + 1][x + l] = arr[i][x + l];
	}
	for (int i = x + l - 1; i > x - l; i--) {//À§ 
		arr[y - l][i + 1] = arr[y - l][i];
	}
	arr[y - l][x - l + 1] = tmp;
}

void ordering(int n) {
	if (n == K) {
		int copy[50][50];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copy[i][j] = map[i][j];
			}
		}
		for (int t = 0; t < K; t++) {
			int y = rotateList[order[t]][0];
			int x = rotateList[order[t]][1];
			int l = rotateList[order[t]][2];
			for (int i = 1; i <= l; i++)
				rotate(y - 1, x - 1, i, copy);
			
		}
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf("%d ", copy[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/

		for (int i = 0; i < N; i++) {
			int sum = 0;
			for (int j = 0; j < M; j++) {
				sum += copy[i][j];
			}
			result = min(result, sum);
		}

		return;
	}
	for (int i = 0; i < K; i++) {
		if (!isvisited[i]) {
			order[n] = i;
			isvisited[i] = true;
			ordering(n + 1);
			isvisited[i] = false;
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			scanf("%d", &map[i][j]);

	for (int t = 0; t < K; t++) {
		scanf("%d %d %d", &rotateList[t][0],
				&rotateList[t][1], &rotateList[t][2]);
	}

	ordering(0);
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/

	printf("%d\n", result);


	return 0;
}
