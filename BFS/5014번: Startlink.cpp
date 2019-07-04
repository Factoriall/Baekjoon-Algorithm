#include <iostream>
#include <queue>
using namespace std;

bool visited[1000001];
queue<int> q;

void bfs(int f, int s, int g, int u, int d) {//bfs 사용
	int i;
	int cnt = 1;
	int tmp;
	q.push(s);
	visited[s] = true;

	while (!q.empty()) {
		int qSize = q.size();
		for (i = 0; i < qSize; i++) {
			int now = q.front();
			q.pop();

			tmp = now + u;
			if (tmp == g) {
				cout << cnt << '\n';
				return;
			}
			if (!visited[tmp] && tmp <= f) {
				//cout << "push: " << tmp << endl;
				q.push(tmp);
				visited[tmp] = true;
				//중요! 이 부분에서 true로 바꿔줘야 중복으로 방문하는 곳을 없앨 수 있다!
			}
			
			tmp = now - d;
			if (tmp == g) {
				cout << cnt << '\n';
				return;
			}
			if (!visited[tmp] && tmp > 0) {
				//cout << "push: " << tmp << endl;
				q.push(tmp);
				visited[tmp] = true;
				//위와 동일하게 중요!
			}
		}
		cnt++;
	}

	//마지막까지 탈출 못할 시 못 갔다는 의미
	cout << "use the stairs" << '\n';
}

int main() {
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	if (s == g)
		cout << 0 << '\n';
	else
		bfs(f, s, g, u, d);

	return 0;
}
