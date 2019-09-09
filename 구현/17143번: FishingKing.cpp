#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };
int R, C, M;

struct Shark{
	int s;
	int d;
	int z;
	Shark() : s(-1), d(-1), z(-1) {}
	Shark(int s1, int d1, int z1) : s(s1), d(d1), z(z1) {}
};

Shark f[100][100];

void printmap() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (f[i][j].s == -1)
				printf("(x x x)\t");
			else
				printf("(%d %d %d)\t", f[i][j].s, f[i][j].d, f[i][j].z);
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
	

	scanf("%d %d %d", &R, &C, &M);
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		f[r - 1][c - 1] = Shark(s, d - 1, z);
	}

	//printmap();

	int result = 0;
	for (int t = 0; t < C; t++) {
		//낚시왕이 상어 낚는 차례
		for (int i = 0; i < R; i++) {
			if (f[i][t].s != -1) {
				result += f[i][t].z;
				f[i][t] = Shark();
				break;
			}
		}

		//상어가 움직이는 차례
		Shark copy[100][100];
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (f[i][j].d != -1) {
					int m;//상어 속도
					if (f[i][j].d > 1) {//왼쪽&오른쪽
						m = f[i][j].s % (2*(C - 1));
						//printf("%d\n", m);
						int nc;
						if (f[i][j].d == 2) { //오른쪽
							nc = (j + m) % (2 * (C - 1));
							if (nc > (C - 1)) {
								nc = 2 * (C - 1) - nc;
								f[i][j].d = 3;
							}
						}
						else { //왼쪽
							
							nc = (j - m) % (2 * (C - 1));
							if (nc < 0)
								nc += (2 * (C - 1));
							//printf("%d\n", nc);
							if (nc > (C - 1)) {
								nc = 2 * (C - 1) - nc;
								f[i][j].d = 2;
							}
							//printf("%d\n", nc);
						}
						//printf("prev: (%d %d) now: (%d %d)\n", i, j, i, nc);
						if (copy[i][nc].d != -1 && copy[i][nc].z > f[i][j].z)
							continue;
						copy[i][nc] = f[i][j];
					}
					else {//위&아래
						m = f[i][j].s % (2*(R - 1));
						//printf("%d\n", m);
						int nr;
						if (f[i][j].d == 0) {//위
							nr = (i - m) % (2 * (R - 1));
							if (nr < 0)
								nr += (2 * (R - 1));
							if (nr > (R - 1)) {
								nr = 2 * (R - 1) - nr;
								f[i][j].d = 1;
							}
						}
						else {
							nr = (i + m) % (2 * (R - 1));
							if (nr > (R - 1)) {
								nr = 2 * (R - 1) - nr;
								f[i][j].d = 0;
							}
						}
						//printf("prev: (%d %d) now: (%d %d)\n", i, j, nr, j);
						if (copy[nr][j].d != -1 && copy[nr][j].z > f[i][j].z)
							continue;
						copy[nr][j] = f[i][j];
					}
				}
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				f[i][j] = copy[i][j];
			}
		}
		//printmap();
	}

	printf("%d\n", result);

	return 0;
}
