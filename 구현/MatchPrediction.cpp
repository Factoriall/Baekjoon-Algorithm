#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Team {
	string name;
	double score[10] = { 1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
};

struct Match {
	string my;
	string op;
	double wp;
	double dp;
	double lp;

	Match() {}
	Match(string my1, string op1, double w, double d, double l) 
		: my(my1), op(op1), wp(w), dp(d), lp(l){}
};

struct R {
	int score;
	int num;
	double per;
	R(){}
	R(int s, int n, double p):score(s), num(n), per(p){}
};

bool cmp(R a, R b) {
	return a.score > b.score;
}

int cnt = 0;
Team T[4];
Match M[6];

double result[4];
int nIdx[4];

void dfs(int n) {
	if (n == 6) {
		vector<R> rank;
		cnt++;
		for (int i = 0; i < 4; i++) {
			for (int j = 9; j >= 0; j--) {
				if (T[i].score[j] != -1) {
					rank.push_back(R(j, i, T[i].score[j]));
					break;
				}
			}
		}
		/*for (int i = 0; i < 3; i++) {
			printf("%d %d %lf\n", rank[i].score, rank[i].num, rank[i].per);
		}*/

		sort(rank.begin(), rank.end(), cmp);
		/*for (int i = 0; i < 3; i++) {
			printf("%d %d %lf\n", rank[i].score, rank[i].num, rank[i].per);
		}*/

		if (rank[0].score == rank[1].score && rank[1].score == rank[2].score && rank[2].score == rank[3].score) {
			for (int t = 0; t < 4; t++) 
				result[rank[t].num] += rank[t].per * 0.25;
		}
		else if (rank[1].score == rank[2].score && rank[2].score == rank[3].score) {
			for (int t = 1; t < 4; t++)
				result[rank[t].num] += rank[t].per * (double)(1 / 3);
		}
		else if (rank[0].score == rank[1].score && rank[1].score == rank[2].score) {
			for (int t = 0; t < 3; t++)
				result[rank[t].num] += rank[t].per * (double)(2 / 3);
		}
		else {
			result[rank[0].num] += rank[0].per;
			result[rank[1].num] += rank[1].per;
		}


		
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (T[i].name == M[n].my) {
			for (int j = 0; j < 4; j++) {
				if (T[j].name == M[n].op) {
					for (int t = 0; t < 3; t++) {
						if (t == 0) {//myÆÀ ½Â¸®
							double tmp = T[j].score[nIdx[j]];
							T[i].score[nIdx[i] + 3] = T[i].score[nIdx[i]] * M[n].wp;
							T[j].score[nIdx[j]] = T[j].score[nIdx[j]] * M[n].lp;
							nIdx[i] += 3;
							dfs(n + 1);
							//backtracking
							nIdx[i] -= 3;
							T[i].score[nIdx[i] + 3] = -1;
							T[j].score[nIdx[j]] = tmp;
						}
						if (t == 1) {
							T[i].score[nIdx[i] + 1] = T[i].score[nIdx[i]] * M[n].dp;
							T[j].score[nIdx[j] + 1] = T[j].score[nIdx[j]] * M[n].dp;
							nIdx[i]++;
							nIdx[j]++;
							dfs(n + 1);
							//backtracking
							nIdx[i]--;
							nIdx[j]--;
							T[i].score[nIdx[i] + 1] = -1;
							T[i].score[nIdx[j] + 1] = -1;
						}
						if (t == 2) {
							double tmp = T[i].score[nIdx[i]];
							T[i].score[nIdx[i]] = T[i].score[nIdx[i]] * M[n].lp;
							T[j].score[nIdx[j] + 3] = T[j].score[nIdx[j]] * M[n].wp;
							nIdx[j] += 3;
							dfs(n + 1);
							//backtracking
							nIdx[j] -= 3;
							T[i].score[nIdx[i]] = tmp;
							T[j].score[nIdx[j] + 3] = -1;
						}

					}
				}
			}
		}
	}
}

int main() {
	cin >> T[0].name >> T[1].name >> T[2].name >> T[3].name;

	//cout << A << ' ' << B << ' ' << C << ' ' << D << '\n';

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

	for (int i = 0; i < 4; i++) 
		cout << result[i]/729.0 << '\n';
	


	return 0;
}