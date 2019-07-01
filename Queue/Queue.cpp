#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int i;
	string cmd;
	queue<int> q;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> cmd;
		if (!cmd.compare("push")) {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (!cmd.compare("pop")) {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (!cmd.compare("front")) {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (!cmd.compare("back")) {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
		else if (!cmd.compare("size")) {
			cout << q.size() << '\n';
		}
		else if (!cmd.compare("empty")) {
			if (q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
	}

	return 0;
}