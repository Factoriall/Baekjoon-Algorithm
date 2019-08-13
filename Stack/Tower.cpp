#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int, int> P;
int result[500000];

int main() {
	int N;
	vector<int> tower;
	stack<P> s;
	

	ios::sync_with_stdio(false);

	cin >> N;

	
	for (int i = 0; i < N; i++) {
		int h;
		cin >> h;
		tower.push_back(h);
	}


	for (int i = tower.size() - 1; i >= 0; i--) {
		if (s.empty() || s.top().second > tower[i]) {}
		else {
			while (!s.empty() && s.top().second <= tower[i]) {
				result[s.top().first] = i + 1;
				s.pop();
			}
		}
		s.push(P(i, tower[i]));
	}

	for (int i = 0; i < N; i++)
		cout << result[i] << ' ';
	cout << '\n';

	return 0;
}