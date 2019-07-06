#include <iostream>
#include <set>
#include <string>
#include <queue>

using namespace std;
set<string> visited;

int digit[4] = { -3, 1, 3, -1 };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

string dest = "123456780";
string start = "";
queue<pair<string, int>> q;

void bfs() {
	int cnt = 0;
	int i, t;
	

	while (!q.empty()) {
		int qSize = q.size();

		for (t = 0; t < qSize; t++) {
			string s = q.front().first;
			int z = q.front().second;
			q.pop();

			if (s == dest) {
				cout << cnt << '\n';
				return;
			}

			int y = z / 3;
			int x = z % 3;
			for (i = 0; i < 4; i++) {
				if (y + dy[i] < 3 && y + dy[i] >= 0 && x + dx[i] < 3 && x + dx[i] >= 0) {
					string ns = s;
					int nz = z + digit[i];
					swap(ns[z], ns[nz]);
					//cout << '[' << s << ", " << ns << ']' << endl;

					if (visited.find(ns) == visited.end()) {
						visited.insert(ns);
						pair<string, int> tmp;
						tmp.first = ns;
						tmp.second = nz;
						q.push(tmp);
					}
				}
			}
			//cout << "===========Direction End ============" << endl;
		}
		cnt++;
	}

	cout << -1 << '\n';
}

int main() {
	int z;
	int input;
	for (int i = 0; i < 9; i++) {
		cin >> input;
		if (input == 0) 
			z = i;
		start += input + '0';
	}
	pair<string, int> tmp;
	tmp.first = start;
	tmp.second = z;
	q.push(tmp);
	visited.insert(start);

	bfs();

	//cout << start << endl;

	return 0;
}