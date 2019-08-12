#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int team[20][20];

int result = 100000;

void teamChoose(int s, int l, int k, vector<int> start, vector<int> link) {
	if(s==N/2 || l == N/2){
		if (s == N / 2) {
			for (int i = k; i < N; i++)
				link.push_back(i);
		}
		else if (l == N / 2) {
			for (int i = k; i < N; i++)
				start.push_back(i);
		}

		int sp = 0;
		int lp = 0;
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				if (i != j) {
					sp += team[start[i]][start[j]];
					lp += team[link[i]][link[j]];
				}
			}
		}
		if (result > abs(sp - lp)) {
			/*for (int i = 0; i < N / 2; i++)
				cout << start[i] << ' ';
			cout << '\n';
			for (int i = 0; i < N / 2; i++)
				cout << link[i] << ' ';
			cout << '\n';
			cout << "result: " << abs(sp - lp) << '\n';*/
			result = min(result, abs(sp - lp));
		}

		return;
	}

	
	start.push_back(k);
	teamChoose(s+1, l, k+1, start, link);
	start.erase(start.begin() + s);
		
	link.push_back(k);
	teamChoose(s, l + 1, k + 1, start, link);
	link.erase(link.begin() + l);

}

int main() {

	vector<int> start;
	vector<int> link;
	ios::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> team[i][j];
		}
	}

	teamChoose(0, 0, 0, start, link);

	cout << result << '\n';

	return 0;
}