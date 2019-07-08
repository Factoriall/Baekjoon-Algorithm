#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int d[7] = { 1,10,100,1000,10000,100000, 1000000 };

int n, k;
int len;
bool visited[1000001];
queue<int> q;
int result = -1;

int swap(int n, int i, int j) {
	int a = (n / d[i]) % 10;
	int b = (n / d[j]) % 10;

	return n - (a * d[i] + b * d[j]) + (b * d[i] + a * d[j]);
}

void bfs(){
	int i, j;
	int cnt = 0;
	

	q.push(n);
	while (!q.empty()) {
		if (cnt == k) {
			while (!q.empty()) {
				result = max(result, q.front());
				q.pop();
			}
			
			return;
		}

		int qSize = q.size();
		fill(visited, visited + 1000001, false);//�ѹ� �������� �ʱ�ȭ!

		for (int t = 0; t < qSize; t++) {
			int num = q.front();
			q.pop();

			for (i = len-1; i >= 0; i--) {
				for (j = i - 1; j >= 0; j--) {
					if(i == len-1 && (num/d[j])%10 == 0){}
					else {
						int ret = swap(num, i, j);
						if (!visited[ret]) {
							//cout << ret << ", " << num << endl;
							q.push(ret);
							visited[ret] = true;
						}
					}
				}
			}
		}
		cnt++;
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < 7; i++) {
		if (n / d[i] > 0 && n / d[i] < 10) {
			len = i + 1;
			break;
		}
	}
	bfs();
	cout << result << '\n';
	return 0;
}