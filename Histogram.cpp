#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

stack<pair<int, int>> s;//first - x��ǥ, second - ����
int histo[100001];

bool Pred(int i) {//������ - ������ ����ְų� ���� ���̰� ���� �� ���� ���̺��� Ŭ �� true
	if (s.empty() || histo[i] > s.top().second)
		return true;
	else
		return false;
}

int main() {
	int n;//��ǥ ����	
	int i;//�ݺ���
	int result = 0;
	int x, h, l;
	//x: ���� ���� ��ġ, h=����, ��=���簢�� ���� ���� 

	cin >> n;
	for (i = 1; i <= n; i++) 
		cin >> histo[i];
	
	for (i = 1; i <= n; i++) {
		if (!Pred(i)) {//���� pred ���ǿ� ���� �ʴٸ� ���� �� ���� �ݺ�
			x = s.top().first;
			while (!Pred(i)) {
				h = s.top().second;
				s.pop();

				if (s.empty())
					l = 0;
				else
					l = s.top().first;

				result = max(result, (x - l)*h);
			}
		}
		//�� ���� ������� push�ϴ� ���� �⺻
		pair<int, int> tmp;
		tmp.first = i;
		tmp.second = histo[i];
		s.push(tmp);
	}

	while (!s.empty()) {//������ Ȯ������ �� ������ �� ������ ������.
		x = s.top().first;
		while (!Pred(i)) {
			h = s.top().second;
			s.pop();

			if (s.empty())
				l = 0;
			else
				l = s.top().first;

			result = max(result, (x - l)*h);
		}
	}


	cout << result << '\n';

	return 0;
}