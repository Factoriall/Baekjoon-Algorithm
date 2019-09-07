#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

bool coor[101][101];

typedef pair<int, int> P;

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);

		vector<P> DC;
		coor[y][x] = true;
		coor[y + dy[d]][x + dx[d]] = true;
		//printf("first curve: (%d %d)\n", y,x);
		//printf("first curve: (%d %d)\n", y + dy[d], x + dx[d]);
		DC.push_back(P(y, x));
		DC.push_back(P(y + dy[d], x + dx[d]));
		for (int i = 0; i < g; i++) {
			int vSize = DC.size();
			P center = DC[vSize - 1];
			for (int t = vSize - 2; t >=0 ; t--) {
				int zy = DC[t].first - center.first;
				int zx = DC[t].second - center.second;

				int tmp = zy;
				zy = zx;
				zx = -tmp;

				//printf("curve: (%d %d)\n", zy + center.first, zx + center.second);
				DC.push_back(P(zy + center.first, zx + center.second));
				coor[zy + center.first][zx + center.second] = true;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (coor[i][j] && coor[i + 1][j] && coor[i][j + 1] && coor[i + 1][j + 1])
				cnt++;
		}
	}

	printf("%d\n", cnt);


	return 0;
}