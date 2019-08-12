#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int vNum = 0;
int map[50][50];
int save[50][50];
bool visited[10];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

typedef struct {
	int y, x;
}P;

P virus[10];

int result = 2501;

void spread() {
	int noVirus = 0;
	int spVirus = 0;
	queue<P> q;
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			save[i][j] = map[i][j];
			if (save[i][j] == 0)
				noVirus++;
		}
	}
	//cout << "NoVirus: " << noVirus << '\n';

	for (int i = 0; i < vNum; i++) {
		if (visited[i]) {
			save[virus[i].y][virus[i].x] = 9;
			q.push(P{ virus[i].y, virus[i].x });
		}
	}

	int cnt = 0;
	while (!q.empty()) {
		if (result <= cnt)
			return;

		int qSize = q.size();
		
		for (int t = 0; t < qSize; t++) {
			int y = q.front().y;
			int x = q.front().x;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < N && ny >= 0 && nx < N && nx >= 0) {
					if (save[ny][nx] == 0) {
						save[ny][nx] = 9;
						spVirus++;
						q.push(P{ ny, nx });
					}
					else if (save[ny][nx] == 2) {
						if (noVirus == spVirus && t == 0){
							
							result = min(result, cnt);
							return;
						}
						else {
							save[ny][nx] = 9;
							q.push(P{ ny, nx });
						}
					}
				}
			}
		}
		
		cnt++;
		
	}
	if (spVirus == noVirus) {
		
		result = min(result, cnt - 1);
	}

}

void chooseVirus(int k, int cnt) {
	if (cnt == M) {
		spread();
		return;
	}
	
	for (int i = k; i < vNum; i++) {
		visited[i] = true;
		chooseVirus(i + 1, cnt + 1);
		visited[i] = false;
	}
}


int main() {

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus[vNum].y = i;
				virus[vNum++].x = j;
			}
		}
	}

	chooseVirus(0, 0);

	if (result != 2501)
		cout << result << '\n';
	else
		cout << -1 << '\n';

	return 0;
}
