#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> assign[1001];

bool schedule[1001];//방문 확인

bool Pred(pair<int, int> a, pair<int, int> b) {//정렬 방법 - 일단 점수 높은거 부터, 같으면 데드라인이 짧은 순 
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

	sort(assign, assign + d, Pred);//정렬

	for (i = 0; i < d; i++)
		cout << assign[i].first << ' ' << assign[i].second << endl;
	cout << endl;

	for (i = 0; i < d; i++) {//이후 순서대로 과제를 제출할 수 있는 가장 늦은 날짜에 제출한다.
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
