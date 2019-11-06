#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 987654321;

int N;
int result = MAX;

int population[10];
vector<int> adj[10];
int area1[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
int area2[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

bool check(int arr[10], int num) {
	if (num == 0)
		return false;

	bool visited[10] = { 0, };
	queue<int> q;
	int connect = 0;

	q.push(arr[0]);
	visited[arr[0]] = true;
	connect++;

	while (!q.empty()) {
		int qSize = q.size();
		for (int t = 0; t < qSize; t++) {
			int city = q.front();
			q.pop();
			for (int a : adj[city]) {
				for (int i = 1; i < num; i++) {
					if (!visited[arr[i]] && arr[i] == a) {
						q.push(arr[i]);
						visited[arr[i]] = true;
						connect++;
					}
				}
			}
		}
	}
	if (connect == num)
		return true;
	else
		return false;
}

void dfs(int p1, int p2, int n) {
	if (n == N) {

		if (check(area1, p1) && check(area2, p2)) {
			int a1 = 0, a2 = 0;
			for (int i = 0; i < p1; i++)
				a1 += population[area1[i]];
			for (int i = 0; i < p2; i++)
				a2 += population[area2[i]];
			/*printf("area1: %d, ", p1);
			for (int i = 0; i < p1; i++) {
				printf("%d ", area1[i]+1);
			}
			printf("\n");
			printf("area2: %d, ", p2);
			for (int i = 0; i < p2; i++) {
				printf("%d ", area2[i]+1);
			}
			printf("\n");
			printf("%d %d\n", a1, a2);*/
			
			int cmp = a1 > a2 ? a1 - a2 : a2 - a1;
			result = min(result, cmp);
		}
		return;
	}
	
	//선거구1에 추가
	area1[p1] = n;
	dfs(p1 + 1, p2, n + 1);
	area1[p1] = -1;

	//선거구2에 추가
	area2[p2] = n;
	dfs(p1, p2 + 1, n + 1);
	area2[p2] = -1;
}

int main() {
	scanf("%d", &N);

	//도시 당 인구수 추가
	for (int i = 0; i < N; i++)
		scanf("%d", &population[i]);
	
	//어떤 도시가 연결되어 있는지 확인
	for (int i = 0; i < N; i++) {
		int n;//연결 개수
		scanf("%d", &n);
		for (int t = 0; t < n; t++) {
			int ad;
			scanf("%d", &ad);
			adj[i].push_back(ad - 1);
		}
	}

	dfs(0, 0, 0);

	if (result == MAX)
		printf("-1\n");
	else
		printf("%d\n", result);

	return 0;
}
