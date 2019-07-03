#include <iostream>
#include <algorithm>
using namespace std;

bool visited[1001];
bool finished[1001];
int pick[1001];
int compo[1001];
int comNum = 1;

int vertex[1001];//������Ʈ i ���� ������ ��
int cycle[1001];//������Ʈ i ���� ����Ŭ ���� ���� ��

pair<int, int> dp[1001][1001];//first-�ּ�, second-�ִ�


void dfs(int t) {//dfs ���� ������Ʈ �� ����Ŭ �� �� ��ü ���� ������ ���Ѵ�.
	visited[t] = true;
	int next = pick[t];

	if (visited[next]) {
		if (!finished[next]) {
			int c = 0;
			for (int tmp = next; tmp != t; tmp = pick[tmp]) {
				compo[tmp] = comNum;
				c++;
			}
			compo[t] = comNum;

			vertex[comNum] = cycle[comNum] = c + 1;
			comNum++;
		}
		else {
			if (compo[t] == 0) {
				compo[t] = compo[next];
				vertex[compo[next]]++;
			}
		}
	}
	else {
		dfs(next);
		if (compo[t] == 0) {
			compo[t] = compo[next];
			vertex[compo[next]]++;
		}
	}

	finished[t] = true;
}

int main() {
	
	int n, k;
	int i, j;

	cin >> n >> k;

	for (i = 1; i <= n; i++)
		cin >> pick[i];

	//����Ŭ �� ������Ʈ �� ã��
	for (i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	//for (i = 1; i < comNum; i++)
	//	cout << "������Ʈ ��: " << vertex[i] << ", ����Ŭ ��: " << cycle[i] << endl;

	//dp����, ���������� ����ϳ� ����Ŭ ���� �ּ��̸� ��ü ������Ʈ�� ���� ���� �ִ��, 
	//�ϴ� ����Ŭ�� ���� �ϰ� �� �Ŀ��� �ִ밪�� �ִ�� �¿� �� �ִ� ����� ���̴�.
	for (i = 1; i < comNum; i++) {
		for (j = 1; j <= k; j++) {
			if (j >= cycle[i]) {
				dp[i][j].first = max(dp[i - 1][j].first, cycle[i] + dp[i - 1][j - cycle[i]].first);
				
				if (dp[i][j].first == dp[i - 1][j].first)
					dp[i][j].second = dp[i - 1][j].second;
				else {
					int a = dp[i - 1][j - cycle[i]].second + vertex[i];
					dp[i][j].second = min(k, a);
				}
			}
			else {
				dp[i][j].first = dp[i - 1][j].first;
				dp[i][j].second = dp[i - 1][j].second;
			}
		}
	}

	cout << dp[comNum-1][k].second << '\n';//���������� �����ϰ� �� ������ �Ʒ� ���� ������ ���̴�.

	return 0;
}