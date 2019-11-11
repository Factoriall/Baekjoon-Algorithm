#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int, char> P;

int main() {
	string str;
	string cmp;
	stack<P> st;

	cin >> str;
	cin >> cmp;

	int n = cmp.size();//스택의 특성상 뒤에서 시작이 편해보임
	for (int i = str.size() - 1; i >= 0; i--) {//str의 탐색
		//cout << "str: " << str[i] << ", cmp: " << cmp[n-1] << '\n';
		if (str[i] != cmp[n - 1]) {//일치하지 않으면 그대로 스택에 넣기
			//cout << n << ", " << str[i] << '\n';
			if (str[i] != cmp[cmp.size() - 1]) {
				n = cmp.size();//초기화
			}
			else {
				n = cmp.size() - 1;//초기화
			}
			st.push(P(n, str[i]));
		}
		else {//같을 시 숫자 저장
			//cout << n - 1 << ", " << str[i] << '\n';
			st.push(P(n - 1, str[i]));
			n--;
		}

		if (n == 0) {
			for (int t = 0; t < cmp.size(); t++)
				st.pop();

			if (!st.empty())
				n = st.top().first;
			else
				n = cmp.size();
		}
	}

	if (st.empty())
		cout << "FRULA\n";
	else {
		while (!st.empty()) {
			cout << st.top().second;
			st.pop();
		}
	}


	return 0;
}
