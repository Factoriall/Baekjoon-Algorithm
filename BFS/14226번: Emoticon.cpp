#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


typedef pair<int, int> P;

bool visited[1025][1025];
queue<P> Q;


int main() {
	int S;

	cin >> S;

	//큐에서 first: 화면 이모티 개수, second: 클립보드 이모티 개수

	Q.push(P(1, 0));
	visited[1][0] = true;
	int sec = 0;

	while (!Q.empty()) {
		int qSize = Q.size();
		for (int t = 0; t < qSize; t++) {
			int win = Q.front().first;
			int clip = Q.front().second;
			Q.pop();

			if (win == S) {
				cout << sec << '\n';
				return 0;
			}

			for (int i = 0; i < 3; i++) {
				int w = win;
				int c = clip;
				if (i == 0 && win != clip) 
					c = w;				
				if (i == 1) 
					w = w + c;
				if (i == 2) 
					w = w - 1;

				if (w >= 0 && w <= 1024 && !visited[w][c]) {
					cout << "win: " << w << ", clip: " << c << '\n';
					Q.push(P(w, c));
					visited[w][c] = true;
				}
			}
		}
		sec++;
		cout << '[' << sec << ']' << endl;
		cout << "=====================" << endl;
	}


	return 0;
}
