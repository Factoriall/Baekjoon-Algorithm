#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

struct P {
	int start, end;
	int status;//0: s=e여서 알 수 없음, 1: -2 차이, 2: 수가 같음
	P(){};
	P(int s, int e, int st) : start(s), end(e), status(st) {}
};

int h[100000];
int N;
P cluster[3];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		h[i] = num - 1 - i;
	}

	int cNum = 0;//특징을 가지는 모임들 개수

	//모임들 저장
	for (int i = 0; i < N; i++) {
		if (h[i] != 0) {
			int s = i;
			int st = 0;
			if (i < N-1 && h[i + 1] == h[i]) {
				st = 2;
				do {
					i++;
				} while (i < N - 1 && h[i + 1] == h[i]);
			}
			else if (i < N - 1 && h[i + 1] == h[i] - 2) {
				if (h[i + 1] == 0) {
					if (i == N - 2 || h[i + 2] != h[i + 1] - 2) {
						cluster[cNum++] = P(s, s, 0);
						continue;
					}
				}
				st = 1;
				do {
					i++;
				} while (h[i + 1] == h[i] - 2);
			}
			else if (i < N - 1 && h[i + 1] == h[i] + 2) {
				if (h[i + 1] == 0) {
					if (i == N - 2 || h[i + 2] != h[i + 1] + 2) {
						cluster[cNum++] = P(s, s, 0);
						continue;
					}
				}
				st = 1;
				do {
					i++;
				} while (h[i + 1] == h[i] + 2);
			}
			int e = i;
			cluster[cNum++] = P(s, e, st);
		}
	}

	for (int i = 0; i < cNum; i++) {
		printf("%d %d %d\n", cluster[i].start, cluster[i].end, cluster[i].status);
	}
	
	//status - 0: s=e여서 알 수 없음, 1: -2 차이, 2: 수가 같음
	if (cNum == 0) {//처음부터 정답
		printf("1 1\n1 1\n");
	}
	else if (cNum == 1) {//하나만 뒤집으면 됩니다.
		printf("1 1\n%d %d\n", cluster[0].start + 1, cluster[0].end + 1);
	}
	else if (cNum == 2) {//2개 뒤집기
		if (cluster[0].status == 1 && cluster[1].status == 1) {
			printf("%d %d\n%d %d\n", cluster[0].start + 1, cluster[0].end + 1, cluster[1].start + 1, cluster[1].end + 1);
		}
		else {
			if (cluster[0].status == 2) {
				printf("%d %d\n%d %d\n", cluster[0].start + 1, cluster[0].end + 1, cluster[0].start + 1, cluster[1].end + 1);
			}
			else {
				printf("%d %d\n%d %d\n", cluster[1].start + 1, cluster[1].end + 1, cluster[0].start + 1, cluster[1].end + 1);
			}
		}
	}
	//status - 0: s=e여서 알 수 없음, 1: -2 차이, 2: 수가 같음
	else {//3개 뒤집기
		if (cluster[0].status == 2) {
			printf("%d %d\n%d %d\n", cluster[0].start + 1, cluster[1].end + 1, cluster[2].start - (cluster[0].end - cluster[0].start + 1) + 1, cluster[2].end + 1);
		}
		else if (cluster[1].status == 2) {
			printf("%d %d\n%d %d\n", cluster[1].start + 1, cluster[1].end + 1, cluster[0].start + 1, cluster[2].end + 1);
		}
		else {
			printf("%d %d\n%d %d\n", cluster[1].start + 1, cluster[2].end + 1, cluster[0].start + 1, cluster[0].end + (cluster[2].end - cluster[2].start + 1) + 1);
		}
	}


	return 0;
}