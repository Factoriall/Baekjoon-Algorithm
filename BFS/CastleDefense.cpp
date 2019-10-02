#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int dx[3] = { -1, 0, 1 };
int dy[3] = { 0, -1, 0 };

int N, M, D;
int map[20][20];
int archor[3];
int last = 0;
int result = 0;

struct pnt {
	int y, x;
	pnt(){}
	pnt(int y1, int x1):y(y1), x(x1){}
};

void printMap(int arr[][20]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void copyMap(int copy[][20], int origin[][20]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy[i][j] = origin[i][j];
		}
	}
}

void defense() {
	queue<pnt> q;
	int enemyLast = last;
	int copy[20][20];
	int kill = 0;

	//puts("map");
	//printMap(map);
	copyMap(copy, map);

	
	while (enemyLast < N) {
		for (int i = 0; i < 3; i++) {
			int cnt = 1;
			bool isVisited[20][20] = { 0, };
			bool isFinished = false;

			if (copy[N-1][archor[i]] != 0) {
				if (copy[N - 1][archor[i]] == 1) {
					kill++;
					copy[N - 1][archor[i]] = 2;
				}
				continue;
			}
			q.push(pnt(N - 1, archor[i]));
			isVisited[N - 1][archor[i]] = true;
			while (!q.empty() && cnt < D) {//BFS 진행
				int qSize = q.size();
				for (int t = 0; t < qSize; t++) {
					pnt point = q.front();
					q.pop();
					for (int d = 0; d < 3; d++) {
						int ny = point.y + dy[d];
						int nx = point.x + dx[d];

						if (ny >= enemyLast && nx >= 0 && nx < M && !isVisited[ny][nx]) {
							if (copy[ny][nx] != 0) {
								if (copy[ny][nx] == 1) {
									copy[ny][nx] = 2;//이미 죽였다는 것을 알려줌, 나중에 무시
									kill++;
								}
								isFinished = true;
							}
							else{
								//printf("%d %d\n", ny, nx);
								isVisited[ny][nx] = true;
								q.push(pnt(ny, nx));
							}
						}

						if (isFinished) break;
					}
					if (isFinished) break;
				}
				
				if (isFinished) break;
				cnt++;
				//printf("===================\n");
			}


			while (!q.empty())//q 초기화
				q.pop();
		}
		//printf("enemyLast: %d\n", enemyLast);
		//printMap(copy);
		for (int i = N - 2; i >= enemyLast - 1; i--)//적을 앞으로 한칸씩 땡기기
			for (int j = 0; j < M; j++) {
				if (copy[i][j] == 2)
					copy[i + 1][j] = 0;
				else
					copy[i + 1][j] = copy[i][j];
			}

		//puts("copy");
		//printMap(copy);

		enemyLast++;
	}

	result = max(result, kill);
}

void selectLocation(int num, int loc) {
	if (num == 3) {
		/*for (int i = 0; i < 3; i++)
			printf("%d ", archor[i]);
		printf("\n");*/
		defense();
		return;
	} 

	for (int i = loc; i < M; i++) {
		archor[num] = i;
		selectLocation(num + 1, i + 1);
	}
}

int main() {
	int i, j;

	bool isFirst = false;
	scanf("%d %d %d", &N, &M, &D);

	for (i = 0; i < N; i++) 
		for (j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1 && !isFirst) {
				last = i;
				isFirst = true;
			}
		}

	selectLocation(0, 0);

	printf("%d", result);

	return 0;
}