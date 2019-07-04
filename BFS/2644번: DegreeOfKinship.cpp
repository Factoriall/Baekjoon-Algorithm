#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
bool kin[101][101];
int degree = 0;
int total;
int a, b;

void bfs() {
	int i, j;
	int level = 1;

	q.push(a);

	while (!q.empty()) {
		int qSize = q.size();

		for (i = 0; i < qSize; i++) {//level을 지정하기 위해 qSize만큼 따로 먼저 진행
			int h = q.front();
			q.pop();
			for (j = 1; j <= total; j++) {
				if (kin[h][j]) {//연결되어 있는지 체크
					if (j == b) {//연결된다면 level 출력 및 종료
						cout << level << '\n';
						return;
					}
					q.push(j);//연결 안될시 push
					kin[h][j] = kin[j][h] = false;//방문 체크
				}
			}
		}
		level++;//깊이 늘리기
	}

	//여기까지 나왔다는 것은 끝까지 갔지만 만나지 못했다는 뜻!
	cout << -1 << '\n';
	return;
}

int main() {
	int n;
	int i, j;

	cin >> total;
	cin >> a >> b;
	cin >> n;

	for (i = 1; i <= n; i++) {//인접 배열 형태로 저장
		int x, y;
		cin >> x >> y;
		kin[x][y] = kin[y][x] = true;
	}

	bfs();

	return 0;
}
