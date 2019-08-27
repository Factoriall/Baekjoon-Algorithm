#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int uf[501500];
vector<int> leftConnect;
vector<int> rightConnect;

int find(int a) {
	if (uf[a] == -1) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int u, int v) {//u에 무조건 벽의 정보
	if (u == -1) {//왼쪽 벽과 연결
		leftConnect.push_back(v);
		return true;
	}
	if (u == -2) {//오른쪽 벽과 연결
		rightConnect.push_back(v);
		return true;
	}
	int a = find(u);
	int b = find(v);
	if (a == b)
		return false;
	uf[a] = b;
	return true;
}

struct Sensor {
	int x, y, r;
	Sensor() {}
	Sensor(int x1, int y1, int r1) : x(x1), y(y1), r(r1) {}
};

struct Edge {
	int u, v;
	double w;
	Edge() {}
	Edge(int u1, int v1, double w1) : u(u1), v(v1), w(w1) {}
	bool operator<(const Edge& O) { return w < O.w; }
};

Sensor s[1000];
Edge e[501500];

int main() {
	int T;

	//freopen("new.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &T);
	

	for (int t = 0; t < T; t++) {
		int n;
		double w;
		
		scanf("%lf", &w);
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			int x, y, r;
			scanf("%d %d %d", &x, &y, &r);
			s[i] = Sensor(x, y, r);
		}
		//왼쪽 벽을 정점 -1, 오른쪽 벽을 -2로 설정,
		int edgeNum = 0;
		for (int i = 0; i < n; i++) {
			//벽과의 거리 정보 삽입
			e[edgeNum++] = Edge(-1, i, s[i].x - s[i].r);
			e[edgeNum++] = Edge(-2, i, w - s[i].x - s[i].r);
			for (int j = i + 1; j < n; j++) //나머지 점과 거리 정보 삽입
				e[edgeNum++] = Edge(j, i, 
					sqrt((long long)(s[i].x - s[j].x)*(s[i].x - s[j].x) + (long long)(s[i].y - s[j].y) * (s[i].y - s[j].y)) - (s[i].r + s[j].r));
		}

		sort(e, e + edgeNum);
		fill(uf, uf + n, -1);

		/*printf("sort\n");
		for (int i = 0; i < edgeNum; i++)
			printf("%d %d %f\n", e[i].u, e[i].v, e[i].w);

		printf("\n");*/


		bool isFinished = false;
		if (n == 0) {
			printf("%.6lf\n", w / 2);
		}
		else {
			for (int i = 0; ; i++) {
				if (merge(e[i].u, e[i].v)) {
					for (int right : rightConnect) {
						for (int left : leftConnect) {
							if (find(right) == find(left)) {
								isFinished = true;
								if (e[i].w <= 0)
									printf("0\n");
								else
									printf("%.6lf\n", e[i].w / 2);//%lf: 최대 유효 자리수 15개, %f: 6개
								break;
							}
						}
						if (isFinished)
							break;
					}
				}
				if (isFinished)
					break;
			}
		}

		rightConnect.clear();
		leftConnect.clear();
	}


	return 0;
}
