#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

int dy[8] = { -1,0,1,1,1,0,-1,-1 };
int dx[8] = { 1,1,1,0,-1,-1,-1,0 };

int ground[10][10];
int robot[10][10];
int treeNum[10][10];
deque<int> tree[10][10];

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &robot[i][j]);
			ground[i][j] = 5;
		}
	}
		
	for (int t = 0; t < M; t++) {
		int i, j, age;
		scanf("%d %d %d", &i, &j, &age);
		tree[i - 1][j - 1].push_front(age);
		treeNum[i - 1][j - 1]++;
	}

	for (int k = 0; k < K; k++) {
		//봄, 여름
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (treeNum[i][j] != 0) {
					int died = 0;
					deque<int>::iterator it = tree[i][j].begin();
					for (int& tmp : tree[i][j]) {
						//printf("%d %d: %d\n", i, j, tmp);
						if (tmp <= ground[i][j]) {//봄
							ground[i][j] -= tmp;
							tmp++;
							it++;
						}
						else {//여름
							died += tmp / 2;
							treeNum[i][j]--;
						}
					}
					ground[i][j] += died;
					tree[i][j].erase(it, tree[i][j].end());
				}
			}
		}

		//가을
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (treeNum[i][j] != 0) {
					for (int tmp : tree[i][j]) {
						if (tmp % 5 == 0) {
							for (int d = 0; d < 8; d++) {
								if (i + dy[d] >= 0 && i + dy[d] < N && j + dx[d] >= 0 && j + dx[d] < N) {
									treeNum[i + dy[d]][j + dx[d]]++;
									tree[i + dy[d]][j + dx[d]].push_front(1);
								}
							}
						}
					}
				}
			}
		}
				
		//겨울
		
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				ground[i][j] += robot[i][j];
	}
	int result = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			result += treeNum[i][j];


	printf("%d\n", result);


	return 0;
}
