#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int s, e;
bool visited[10000];

typedef struct {
	int num;
	vector<char> cmd;
}Reg;

queue<Reg> q;

void print(vector<char> s) {
	for (vector<char>::size_type t = 0; t < s.size(); t++) {
		cout << s[t];
	}
	cout << '\n';
}

int doubleUp(int n) {
	return (n * 2) % 10000;
}

int subtract(int n) {
	if (n == 0)
		return 9999;
	else
		return n - 1;
}

int rotateL(int n) {
	int a = n / 1000;
	int b = (n % 1000) / 100;
	int c = (n % 100) / 10;
	int d = n % 10;

	int tmp = a;
	a = b; b = c; c = d; d = tmp;

	return a * 1000 + b * 100 + c * 10 + d;
}

int rotateR(int n) {
	int a = n / 1000;
	int b = (n % 1000) / 100;
	int c = (n % 100) / 10;
	int d = n % 10;

	int tmp = d;
	d = c; c = b; b = a; a = tmp;

	return a * 1000 + b * 100 + c * 10 + d;
}

void bfs() {
	Reg r;
	r.num = s;
	
	visited[s] = true;
	q.push(r);

	while (!q.empty()) {
		r.num = q.front().num;
		r.cmd = q.front().cmd;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int result;
			Reg save;
			save.num = r.num;
			save.cmd = r.cmd;
			if (i == 0) {
				result = doubleUp(save.num);
				save.cmd.push_back('D');
				save.num = result;
			}
			else if (i == 1) {
				result = subtract(save.num);
				save.cmd.push_back('S');
				save.num = result;
			}
			else if (i == 2) {
				result = rotateL(save.num);
				save.cmd.push_back('L');
				save.num = result;
			}
			else if (i == 3) {
				result = rotateR(save.num);
				save.cmd.push_back('R');
				save.num = result;
			}
			
			if (result == e) {
				print(save.cmd);
				return;
			}
			if (!visited[result]) {
				cout << "result: " << result << endl;
				q.push(save);
				visited[result] = true;
			}
		}
	}
}

int main() {
	int T;
	int t;

	cin >> T;

	for (t = 0; t < T; t++) {
		fill(visited, visited + 10000, false);
		cin >> s >> e;
		bfs();

		while (!q.empty())
			q.pop();
	}

	return 0;
}