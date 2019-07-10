#include <iostream>
#include <algorithm>
using namespace std;

pair<long long int, long long int> stop[100001];//first - À§Ä¡, second - ¸ÀÀÖ´Â Á¤µµ

bool Pred(pair<long long int, long long int> i, pair<long long int, long long int> j) {
	if (i.second != j.second)
		return i.second > j.second;
	else
		return i.first > j.first;
}

int main() {
	long long int i;
	long long int l, n, f, b;

	cin >> l >> n >> f >> b;

	long long int c = f - b;

	for (i = 0; i < n; i++) {
		cin >> stop[i].first >> stop[i].second;
	}

	sort(stop, stop + n, Pred);

	/*for (i = 0; i < n; i++) {
		cout << stop[i].first << ' ' << stop[i].second << endl;
	}
	cout << endl;*/

	long long int now = 0;
	long long int total = 0;

	for (i = 0; i < n; i++) {
		if (stop[i].first < now) continue;
		
		total += (stop[i].first - now) * c * stop[i].second;
		now = stop[i].first;
		//cout << "now: " << now << ", total: " << total << endl;
	}
	
	cout << total << '\n';

	return 0;
}
