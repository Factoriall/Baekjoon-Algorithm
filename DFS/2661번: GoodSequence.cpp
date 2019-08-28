#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s = "";
bool e = false;

void dfs(char c, int cnt) {
	if (cnt == n + 1) {
		cout << s;
		e = true;
		return;
	}
	s += c;
	for (int i = 1; i <= cnt / 2; i++) {
		if (s.substr(cnt - i, i) == s.substr(cnt - 2 * i, i)) {
			s.erase(cnt - 1);
			return;
		}
	}

	for (int i = 1; i <= 3; i++) {
		if (e == false)		
			dfs(i + '0', cnt + 1);
	}
	s.erase(cnt - 1);
}

int main() {


	cin >> n;

	for (int i = 1; i <= 3; i++)
		dfs(i + '0', 1);


	return 0;
}
