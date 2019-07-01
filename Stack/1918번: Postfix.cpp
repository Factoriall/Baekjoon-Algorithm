#include <iostream>
#include <string>
#include <stack>
using namespace std;

string funct;
stack<char> s;

bool Pred(char f) {//조건: 비어있거나 열린 괄호거나 우선순위에서 높거나
	if (s.empty() || s.top() == '(' || ((f == '*' || f == '/') && (s.top() == '+' || s.top() == '-')))
		return true;
	else
		return false;
}

int main() {
	
	int i;

	cin >> funct;

	for (i = 0; i < funct.size(); i++) {
		if (funct[i] == '(')//열린 괄호면 push
			s.push('(');

		else if (funct[i] == ')') {//닫힌 괄호면 열린 괄호 나올때까지 pop
			while (s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else if (funct[i] == '+' || funct[i] == '-' || funct[i] == '*' || funct[i] == '/') {//사칙연산일시
			if (Pred(funct[i]))//조건 맞으면 push
				s.push(funct[i]);
			else {//조건 안 맞으면 조건 맞을때까지 pop 후 push
				while (!Pred(funct[i])) {
					cout << s.top();
					s.pop();
				}
				s.push(funct[i]);
			}
		}
		else//피연산자일시 걍 출력
			cout << funct[i];
	}
	while (!s.empty()) {//끝 도달시 모든 stack 내용물 pop
		cout << s.top();
		s.pop();
	}

	return 0;
}
