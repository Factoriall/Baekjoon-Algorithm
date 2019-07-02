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
	visited[n] = true;//방문했으므로 true로 변경
	int next = stu[n];//n번째 학생이 고른 학생 번호
	if (visited[next] == false) {//만약 방문하지 않았으면 재귀함수 돌리기
		dfs(next);
	}
	else {
		if (finished[next] == false) {//만약 여기서 false면 현재 점과 cycle이 생성되었음을 의미
			for (int tmp = next; tmp != n; tmp = stu[tmp]) //next 통해서 cycle 정점 개수 확인
				cycle++;
			cycle++;//자신의 점 더하기
		}
	}
	finished[n] = true;//아예 끝났다는 걸 표시
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

		cout << stuNum - cycle << '\n';//전체 수 - 사이클 정점 수 = 팀 안 정해진 사람 수
	}

	return 0;
}
