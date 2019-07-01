#include <iostream>
#include <string>
#include <stack>
using namespace std;

string postfix;


int main() {
	int n;
	double alp[27];//���ĺ� �� �Է�
	int i;
	double a, b;
	double result;
	stack<double> s;

	cin >> n;
	cin >> postfix;
	for (i = 0; i < n; i++)//alp[0]-A�� ��, alp[1]-B�� ��, ... 
		cin >> alp[i];

	for (i = 0; i < postfix.size(); i++) {
		
		if (postfix[i] >= 'A' && postfix[i] <= 'Z') {//�ǿ������Ͻ� push
			s.push(alp[postfix[i]-'A']);
		}
		else {//��Ģ����� 2�� pop �� �װ��� ����� �� �ٽ� push
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
	//������ �� �Ҽ��� 2�ڸ� ���� ���
	cout << fixed;
	cout.precision(2);
	cout << s.top() << endl;

	s.pop();

	return 0;
}