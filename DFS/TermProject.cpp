#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100000;

int stuNum;
int stu[MAX];
bool visited[MAX];//정점 방문 확인
bool finished[MAX];//정점 방문 함수가 끝났는지 확인
int cycle;

void dfs(int n) {
	//cout << "here" << endl;
	visited[n] = true;
	int next = stu[n];
	if (visited[next] == false) {
		dfs(next);
	}
	else {
		if (finished[next] == false) {
			for (int tmp = next; tmp != n; tmp = stu[tmp]) 
				cycle++;
			cycle++;
		}
	}
	finished[n] = true;
}

int main() {
	int t, i;
	int n;
	cin >> n;

	for (t = 0; t < n; t++) {
		cin >> stuNum;
		for (i = 0; i < stuNum; i++) {
			cin >> stu[i];
			stu[i]--;
		}
		fill(visited, visited + stuNum, false);
		fill(finished, finished + stuNum, false);

		cycle = 0;
		for (i = 0; i < stuNum; i++) {
			if (!visited[i]) 
				dfs(i);
		}

		cout << stuNum - cycle << '\n';
	}

	return 0;
}