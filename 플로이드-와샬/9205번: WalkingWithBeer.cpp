#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int main() {
	int T;

	ios::sync_with_stdio(false);

	cin >> T;
	for (int t = 0; t < T; t++) {
		int C;
		vector<P> pnt;
		bool dist[102][102];

		cin >> C;
		for (int n = 0; n < C + 2; n++) {
			int x, y;
			cin >> x >> y;
			pnt.push_back(P(x, y));
		}

		for (int i = 0; i < C + 2; i++)
			for (int j = i + 1; j < C + 2; j++) {
				dist[i][j] = (1000 - (abs(pnt[i].first - pnt[j].first) + abs(pnt[i].second - pnt[j].second)) >= 0);
				dist[j][i] = dist[i][j];
			}

		for (int k = 0; k < C + 2; k++) {
			for (int i = 0; i < C + 2; i++) {
				for (int j = 0; j < C + 2; j++) {
					if (dist[i][k] && dist[k][j]) {
						dist[i][j] = true;
					}
				}
			}
		}

		if (dist[0][C + 1])
			cout << "happy" << '\n';
		else
			cout << "sad" << '\n';

	}

	return 0;
}
