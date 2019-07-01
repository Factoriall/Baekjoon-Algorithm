#include <iostream>
#include <string>
#include <stack>
using namespace std;

string postfix;


int main() {
	int n;
	double alp[27];//알파벳 값 입력
	int i;
	double a, b;
	double result;
	stack<double> s;

	cin >> n;
	cin >> postfix;
	for (i = 0; i < n; i++)//alp[0]-A의 값, alp[1]-B의 값, ... 
		cin >> alp[i];

	for (i = 0; i < postfix.size(); i++) {
		
		if (postfix[i] >= 'A' && postfix[i] <= 'Z') {//피연산자일시 push
			s.push(alp[postfix[i]-'A']);
		}
		else {//사칙연산시 2개 pop 후 그것을 계산한 뒤 다시 push
			b = s.top();
			s.pop();
			a = s.top();
			s.pop();

			switch (postfix[i]) {
			case '+':
				result = a + b;
				break;
			case '-':
				result = a - b;
				break;
			case '*':
				result = a * b;
				break;
			case '/':
				result = a / b;
			}
			
			s.push(result);
		}
	}
	//마지막 값 소수점 2자리 수로 출력
	cout << fixed;
	cout.precision(2);
	cout << s.top() << endl;

	s.pop();

	return 0;
}