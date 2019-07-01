#include <iostream>
#include <queue>
#include <string>
using namespace std;


int main() {
	int n, k;//n-�Է� ��, k-���� ģ���� �� �� �ִ� ��� ����
	string t;
	queue<int> q[21];//���̿� �����ϴ� queue �迭 ����
	long long int result = 0;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> t;

		int s = t.size();//s-���ڿ� ����
		//cout << s << endl;
		if(!q[s].empty()){//���� ������� ������ ���� ģ���� �� ���ϱ�
			//���� �ε����� ť �� ���� �ε��� ���̰� k���� ũ�� pop
			while (!q[s].empty() && i - q[s].front() > k)
				q[s].pop();
			//queue �� ���� �ε������� ��� ���� ���ԵǴ� �ε����� ���� ģ��!
			result += q[s].size();
		}
		q[s].push(i);//�� ���̿� �����ϴ� queue�� ����
	}

	cout << result << '\n';//��� ���
	
	return 0;
}