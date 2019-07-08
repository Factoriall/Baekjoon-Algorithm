#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> assign[1001];

bool schedule[1001];

bool Pred(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second)
		return a.second > b.second;
	else
		return a.first < b.first;
}

int main() {
	int d;
	int i;
	int score = 0;
	

	cin >> d;
	for (i = 0; i < d; i++)
		cin >> assign[i].first >> assign[i].second;

	int full = d;

	sort(assign, assign + d, Pred);

	for (i = 0; i < d; i++)
		cout << assign[i].first << ' ' << assign[i].second << endl;
	cout << endl;

	for (i = 0; i < d; i++) {
		int latest = assign[i].first;

		while (schedule[latest]) {
			latest--;
		}
		if (latest != 0) {
			schedule[latest] = true;
			score += assign[i].second;
		}
	}

	cout << score << endl;
	return 0;
}