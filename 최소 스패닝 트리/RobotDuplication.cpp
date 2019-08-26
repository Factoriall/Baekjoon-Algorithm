#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int map[50][50];
int uf[251];

int find(int a) {
	if (uf[a] == -1) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int u, int v) {
	int a = find(u);
	int b = find(v);
	if (a == b)
		return false;
	uf[a] = b;
	return true;
}

struct Vertex {
	int y, x;
	Vertex() {}
	Vertex(int y1, int x1) : y(y1), x(x1) {}
};

struct Edge {
	int u, v, w;
	Edge() {}
	Edge(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {}
	bool operator<(const Edge &O) { return w < O.w; }
};

vector<Vertex> v;
Edge e[31626];

int main() {
	int N, M;
	int en = 0;//���� ��
	int rn = 0;//�κ� ��ȣ

	scanf("%d %d", &N, &M);

	//���ϴ´�� ���Ĺ�����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c;
			scanf("%c", &c);
			if (c == '1')//���̸� -1��
				map[i][j] = -1;
			if (c == 'S' || c == 'K') {//�κ� �� ���� ��ġ�� ���� ��ȣ�� �ٿ��ش�
				map[i][j] = ++rn;
				v.push_back(Vertex(i, j));
			}
			if (c == '\n')//���� ���°Ŵ� ��������
				j--;
		}
	}
	
	//BFS ����
	bool isFirst = true;//ó�� �ִ°� Ȯ��
	int chk = 0;
	for (Vertex s : v) {
		queue<Vertex> q;
		bool visited[50][50] = { 0 };

		int start = map[s.y][s.x];
		q.push(s);
		visited[s.y][s.x] = true;
		map[s.y][s.x] = 0;//�ʱ�ȭ ���� ������ ������ Ž���� ���ϰ� �ȴ�, ������ ���̴� ȿ��
		int cnt = 0;
		while (!q.empty()) {
			int qSize = q.size();
			for (int t = 0; t < qSize; t++) {
				int y = q.front().y;
				int x = q.front().x;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (ny >= 0 && ny < N && nx >= 0 && nx < N && !visited[ny][nx]) {
						if (map[ny][nx] == 0) {//�� ����
							q.push(Vertex(ny, nx));
							visited[ny][nx] = true;
						}
						if (map[ny][nx] != 0 && map[ny][nx] != -1) {//���� ����
							chk++;
							q.push(Vertex(ny, nx));
							visited[ny][nx] = true;
							e[en++] = Edge(start - 1, map[ny][nx] - 1, cnt + 1);//���� ���� �ֱ�
						}
					}
				}
			}
			cnt++;
		}
		
		if (isFirst) {//ó���� chk ������ M���� ������ ��� ã�� ���� ��! �״�� ������.
			if (chk != M) {
				puts("-1");
				return 0;
			}
			isFirst = false;
		}
	}
	sort(e, e + en);

	int result = 0; int cnt = 0;
	fill(uf, uf + M + 1, -1);
	for (int i = 0; ; i++) {
		if (merge(e[i].u, e[i].v)) {//���� true�� ��ȯ�Ǿ��ٸ� result ���ϱ�
			result += e[i].w;
			if (++cnt == M)//���� �ľ��ؼ� ������.
				break;
		}
	}

	printf("%d\n", result);

	return 0;
}