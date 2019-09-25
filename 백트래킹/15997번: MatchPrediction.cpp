#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

double percent = 1;
struct Team {
	string name;
	int score = 0;
};

struct Match {
	string my;
	string op;
	double wp;
	double dp;
	double lp;

	Match() {}
	Match(string my1, string op1, double w, double d, double l)
		: my(my1), op(op1), wp(w), dp(d), lp(l) {}
};

struct R {
	int teamNum;
	int score;
	
	R() {}
	R(int n, int s) :teamNum(n), score(s) {}
};

bool cmp(R a, R b) {
	return a.score > b.score;
}

Team T[4];
Match M[6];

double result[4];

void dfs(int n) {
	if (percent == 0)//확률이 0이면 굳이 할 필요 없음
		return;
	if (n == 6) {
		vector<R> rank;
		for (int i = 0; i < 4; i++)
			rank.push_back(R(i, T[i].score));

		sort(rank.begin(), rank.end(), cmp);

		/*cout << "percent: " << percent << '\n';
		for (int i = 0; i < 4; i++) 
			cout << T[rank[i].teamNum].name << '\t' << rank[i].score << '\n';
		puts("=================");*/


		if (rank[0].score == rank[1].score && rank[1].score == rank[2].score && rank[2].score == rank[3].score) {//전체 승점 일치
			for (int t = 0; t < 4; t++)
				result[rank[t].teamNum] += percent * 0.5;
		}
		else if (rank[1].score == rank[2].score && rank[2].score == rank[3].score) {//하위 3위 팀 승점 일치
			result[rank[0].teamNum] += percent;
			for (int t = 1; t < 4; t++)
				result[rank[t].teamNum] += percent * 1.0 / 3.0;
		}
		else if (rank[0].score == rank[1].score && rank[1].score == rank[2].score) {//상위 3위 팀 승점 일치
			for (int t = 0; t < 3; t++)
				result[rank[t].teamNum] += percent * 2.0 / 3.0;
		}
		else if (rank[1].score == rank[2].score) {//중간 2팀 승점 일치
			result[rank[0].teamNum] += percent;
			for (int t = 1; t < 3; t++)
				result[rank[t].teamNum] += percent * 0.5;
		}
		else {//1-2위 명확
			result[rank[0].teamNum] += percent;
			result[rank[1].teamNum] += percent;
		}
		/*for (int i = 0; i < 4; i++)
			cout << result[i] << '\n';

		puts("=================");*/
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (T[i].name == M[n].my) {
			for (int j = 0; j < 4; j++) {
				if (T[j].name == M[n].op) {
					for (int t = 0; t < 3; t++) {
						double tmp = percent;
						if (t == 0) {//my팀 승리
							T[i].score += 3;
							percent *= M[n].wp;
							dfs(n + 1);
							//backtraking
							T[i].score -= 3;
						}
						if (t == 1) {//비김
							T[i].score += 1;
							T[j].score += 1;
							percent *= M[n].dp;
							dfs(n + 1);
							//backtracking
							T[i].score -= 1;
							T[j].score -= 1;
						}
						if (t == 2) {//패배
							T[j].score += 3;
							percent *= M[n].lp;
							dfs(n + 1);
							//backtraking
							T[j].score -= 3;
						}
						percent = tmp;
					}
				}
			}
		}
	}
}

int main() {
	cin >> T[0].name >> T[1].name >> T[2].name >> T[3].name;

	for (int t = 0; t < 6; t++) {
		string my;
		string op;

		double w;
		double d;
		double l;

		cin >> my >> op >> w >> d >> l;
		M[t] = Match(my, op, w, d, l);
	}

	dfs(0);

	cout << fixed;
	cout.precision(10);
	for (int i = 0; i < 4; i++)
		cout << result[i] << '\n';
	//cout << result[0] + result[1] + result[2] + result[3] << '\n';

	return 0;
}
