#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef pair<string, int> P;

int main() {
	int N, M, R, K;
	map<string, int> city;
	vector<int> travel;

	int dist[100][100];
	int naelro[100][100];
	const int INF = 1000000000;


	cin >> N >> R;

	for (int i = 0; i < N; i++) {//초기화
		for (int j = 0; j < N; j++) {
			if (i == j) {
				dist[i][j] = 0;
				naelro[i][j] = 0;
			}
			else {
				dist[i][j] = INF;
				naelro[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		city.insert(P(s, i));
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		int c = city.find(s)->second;
		//cout << c << '\n';
		travel.push_back(c);
	}
	cin >> K;

	for (int i = 0; i < K; i++) {
		string t, s, e;
		int c;

		cin >> t >> s >> e >> c;

		int start;
		int end;
		
		map<string, int>::iterator iter;
		iter = city.find(s);
		start = iter->second;
		iter = city.find(e);
		end = iter->second;

		dist[start][end] = min(dist[start][end], c);
		dist[end][start] = min(dist[end][start], c);
		if (t == "ITX-Saemaeul" || t == "ITX-Cheongchun" || t == "Mugunghwa") {
			naelro[start][end] = min(naelro[start][end], 0);
			naelro[end][start] = min(naelro[end][start], 0);
		}
		else if (t == "S-Train" || t == "V-Train") {
			naelro[start][end] = min(naelro[start][end], c / 2);
			naelro[end][start] = min(naelro[end][start], c / 2);
		}
		else {
			naelro[start][end] = min(naelro[start][end], c);
			naelro[end][start] = min(naelro[end][start], c);
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				naelro[i][j] = min(naelro[i][j], naelro[i][k] + naelro[k][j]);
			}
		}
	}

	int yes = R;
	int no = 0;
	for (size_t i = 0; i < travel.size() - 1; i++) {
		int now = travel[i];
		int next = travel[i + 1];

		//cout << '[' << now << "->" << next << ']' << '\n';
		//cout << "내일로: " << naelro[now][next] << ", 아님: " << dist[now][next] << '\n';
		yes += naelro[now][next];
		no += dist[now][next];
	}

	//cout << "Yes: " << yes << ", No: " << no << '\n';

	if (yes < no)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';



	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dist[i][j] == INF)
				cout << "INF\t";
			else
				cout << dist[i][j] << '\t';
		}
		cout << '\n';
	}
	cout << "=================================================================\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (naelro[i][j] == INF)
				cout << "INF\t";
			else
				cout << naelro[i][j] << '\t';
		}
		cout << '\n';
	}*/


	return 0;
}