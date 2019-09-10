#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
int con = 0;
int vow = 0;
vector<string> fullpw;
string pw;
char alp[15];

void dfs(int n) {
	if (n == C)
		return;
	if (pw.size() + 1 == L) {
		if (alp[n] == 'a' || alp[n] == 'e' || alp[n] == 'u' || alp[n] == 'i' || alp[n] == 'o') {
			if (con >= 2)
				fullpw.push_back(pw + alp[n]);
		}
		else {
			if(con >= 1 && vow >= 1)
				fullpw.push_back(pw + alp[n]);
		}
	}

	dfs(n + 1);
	pw += alp[n];
	if (alp[n] == 'a' || alp[n] == 'e' || alp[n] == 'u' || alp[n] == 'i' || alp[n] == 'o') 
		vow++;
	else
		con++;
	dfs(n + 1);

	//backtracking
	if (alp[n] == 'a' || alp[n] == 'e' || alp[n] == 'u' || alp[n] == 'i' || alp[n] == 'o')
		vow--;
	else
		con--;
	pw.erase(pw.end() - 1);
}

int main() {
	ios::sync_with_stdio(false);
	
	cin >> L >> C;
	
	for (int i = 0; i < C; i++)
		cin >> alp[i];

	sort(alp, alp + C);
	
	dfs(0);

	sort(fullpw.begin(), fullpw.end());

	for (string p : fullpw)
		cout << p << '\n';

	return 0;
}