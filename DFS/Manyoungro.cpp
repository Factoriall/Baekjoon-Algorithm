#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct {
	int next;
	char alp;
}Info;

vector<Info> road[500000];
char alphabet[500000];
string P;
int cnt = 0;

void roadTrack(int now, int start, int len, string line) {
	for (Info nextP : road[now]) {
		int next = nextP.next;
		char a = nextP.alp;
		string copy = line;
		copy.push_back(a);

		//cout << "First - next: " << next << ", start: " << start << ", len: " << len << ", copy: " << copy << '\n';
		if (P[len] == a) {//만약 일치할 시 
			//cout << "correct\n";
			if (len == P.size() - 1) {//만약 모두 일치할 시 cnt 추가 및 조정 필요
				cout << "finished\n";
				cnt++;
				start++;
				while (start != now && copy.substr(start, now) != P.substr(0, len)) {
					start++;
					len--;
				}
			}
			else
				len++;
		}
		else {//일치 안할 시 조정
			//cout << "wrong\n";
			start++;
			while (start != now && copy.substr(start, now) != P.substr(0, len)) {
				start++;
				len--;
			}
		}
		//cout <<  "Last - next: "  << next  << ", start: " << start << ", len: " << len << ", copy: " << copy << '\n';
		roadTrack(next, start, len, copy);
	}
	//cout << "[ALL DONE]" << '\n';
}

int main() {
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int u, v;
		char c;
		cin >> u >> v >> c;
		road[u - 1].push_back(Info{v - 1, c});
	}

	/*for (int i = 0; i < N; i++) {
		cout << i << ":";
		for (Info next : road[i])
			cout << '(' << next.next << ',' << next.alp << ") ";
		cout << '\n';
	}*/

	cin >> P;

	roadTrack(0, 0, 0, "");

	printf("%d", cnt);

	return 0;
}