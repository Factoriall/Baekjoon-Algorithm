#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct {//
	int n;//대포 숫자
	double w;//가중치
}P;

typedef struct {
	double x;//x 위치
	double y;//y 위치
}C;

struct cmp {
	bool operator()(P a, P b) {//weight 따라 priority_queue 조절
		return a.w > b.w;
	}
};

double pythagoras(double x1, double y1, double x2, double y2) {//두 점 사이 거리 구하기
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

C cannon[101];
bool visited[101];
double dist[101];

int main() {
	double sy, sx;
	double ey, ex;

	ios::sync_with_stdio(false);

	cin >> sx >> sy;
	cin >> ex >> ey;


	int c;
	cin >> c;
	priority_queue<P, vector<P>, cmp> PQ;

	for (int i = 0; i < c; i++) {//걸어서 가는 거리 저장
		double cx, cy;

		cin >> cx >> cy;
		cannon[i].x = cx;
		cannon[i].y = cy;
		dist[i] = pythagoras(sx, sy, cx, cy) / 5;
		PQ.push(P{ i, dist[i] });
	}

	cannon[c].x = ex;
	cannon[c].y = ey;
	dist[c] = pythagoras(sx, sy, ex, ey) / 5;//목적지
	PQ.push(P{ c, dist[c] });

	while (!PQ.empty()) {
		int curr;
		do {
			curr = PQ.top().n;//현재 위치
			PQ.pop();
		} while (!PQ.empty() && visited[curr]);
		if (visited[curr]) break;

		visited[curr] = true;

		if (curr == c) {
			cout << fixed;
			cout.precision(6);
			cout << dist[c] << endl;
			break;
		}

		for (int i = 0; i <= c; i++) {
			if (i != curr) {
				if (dist[i] > dist[curr] + 2 + abs(pythagoras(cannon[curr].x, cannon[curr].y, cannon[i].x, cannon[i].y) - 50) / 5) {
					dist[i] = dist[curr] + 2 + abs(pythagoras(cannon[curr].x, cannon[curr].y, cannon[i].x, cannon[i].y) - 50) / 5;
					PQ.push(P{ i, dist[i] });
				}
			}
		}
	}

	return 0;
}
