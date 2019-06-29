#include <iostream>
#include <string>
#include <stack>
using namespace std;

string funct;
stack<char> s;

bool Pred(char f) {//����: ����ְų� ���� ��ȣ�ų� �켱�������� ���ų�
	if (s.empty() || s.top() == '(' || ((f == '*' || f == '/') && (s.top() == '+' || s.top() == '-')))
		return true;
	else
		return false;
}

int main() {
	
	int i;

	cin >> funct;

	for (i = 0; i < funct.size(); i++) {
		if (funct[i] == '(')//���� ��ȣ�� push
			s.push('(');

		else if (funct[i] == ')') {//���� ��ȣ�� ���� ��ȣ ���ö����� pop
			while (s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else if (funct[i] == '+' || funct[i] == '-' || funct[i] == '*' || funct[i] == '/') {//��Ģ�����Ͻ�
			if (Pred(funct[i]))//���� ������ push
				s.push(funct[i]);
			else {//���� �� ������ ���� ���������� pop �� push
				while (!Pred(funct[i])) {
					cout << s.top();
					s.pop();
				}
				s.push(funct[i]);
			}
		}
		else//�ǿ������Ͻ� �� ���
			cout << funct[i];
	}
	while (!s.empty()) {//�� ���޽� ��� stack ���빰 pop
		cout << s.top();
		s.pop();
	}

	return 0;
}