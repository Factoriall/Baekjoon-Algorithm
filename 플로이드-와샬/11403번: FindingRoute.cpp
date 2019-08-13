#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int N;
	int dist[100][100];

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> dist[i][j];
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (dist[i][j] == 0) {
					if (dist[i][k] == 1 && dist[k][j] == 1)
						dist[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
