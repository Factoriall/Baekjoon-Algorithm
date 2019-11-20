#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int arr[10001];
int cpy[10001];
int N;
P flip[2];

void copyArr(int copy[10001], int origin[10001]) {
	for (int i = 1; i <= N; i++) {
		copy[i] = origin[i];
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) 
		scanf("%d", &arr[i]);
	
	copyArr(cpy, arr);
	int cnt = 0;
	bool isFinished = true;
	for (int i = 1; i <= N; i++) {//왼쪽부터 순방향으로 2번 뒤집기 시도
		if (cpy[i] != i) {
			if (cnt == 2) {//2번보다 더 나온다면 실패
				isFinished = false;
				break;
			}

			int d;
			if (cpy[i] > i) {
				d = i + 1;
				while (cpy[d] != i)//i가 포함되어있는 d의 위치 탐색
					d++;

				reverse(cpy + i, cpy + d + 1);
				flip[cnt++] = P(i, d);
			}
			else {
				int d = i - 1;
				while (cpy[d] != i)//i가 포함되어있는 d의 위치 탐색
					d--;

				reverse(cpy + d, cpy + i + 1);
				flip[cnt++] = P(d, i);
			}
		}
	}

	
	if (!isFinished) {//왼쪽 방향 실패 시 오른쪽 방향으로 시도
		/* 초기화 */
		copyArr(cpy, arr);
		cnt = 0;

		for (int i = N; i >= 1; i--) {//오른쪽부터 역방향으로 2번 뒤집기 시도
			if (cpy[i] != i) {
				int d;
				if (cpy[i] > i) {
					d = i + 1;
					while (cpy[d] != i)//i가 포함되어있는 d의 위치 탐색
						d++;

					reverse(cpy + i, cpy + d + 1);
					flip[cnt++] = P(i, d);
				}
				else {
					int d = i - 1;
					while (cpy[d] != i)//i가 포함되어있는 d의 위치 탐색
						d--;

					reverse(cpy + d, cpy + i + 1);
					flip[cnt++] = P(d, i);
				}
			}
		}
	}

	if (cnt == 0) {
		printf("1 1\n1 1\n");
	}
	else if (cnt == 1) {
		printf("1 1\n%d %d", flip[0].first, flip[0].second);
	}
	else {
		printf("%d %d\n%d %d", flip[0].first, flip[0].second, flip[1].first, flip[1].second);
	}
	
	return 0;
}