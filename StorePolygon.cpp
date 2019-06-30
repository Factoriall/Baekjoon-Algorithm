#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<pair<int, int>> pillar;//first - x��ǥ, second - ���� 
stack<pair<int, int>> s1;
stack<pair<int, int>> s2;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
	return a.first < b.first;
}

int main() {
	int n;
	int i;
	int size = 0;

	cin >> n;

	pair<int, int> tmp;//pillar vector�� �����ϱ� ���� �ӽ� pair ����
	for (i = 0; i < n; i++) {//����
		cin >> tmp.first >> tmp.second;
		pillar.push_back(tmp);
	}

	sort(pillar.begin(), pillar.end(), cmp);//x��ǥ ������ �°� ����
		
	/*for (i = 0; i < pillar.size(); i++)
		cout << '[' << pillar[i].first << ", " << pillar[i].second << ']' << endl;*/
	
	//���ʺ��� ���������� ���簢�� ���ϱ�
	s1.push(pillar[0]);
	for (i = 1; i < n; i++) {
		if (s1.top().second < pillar[i].second) {
			size += s1.top().second * (pillar[i].first - s1.top().first);
			s1.push(pillar[i]);
		}
	}

	//�����ʺ��� �������� ���鼭 ���簢�� ���ϱ�
	s2.push(pillar[n - 1]);
	for (i = n-2; i >= 0; i--) {
		if (s2.top().second < pillar[i].second) {
			size += s2.top().second * (s2.top().first - pillar[i].first);
			s2.push(pillar[i]);
		}
	}

	//���������� s1, s2 ž ����(����) * �� ���� x��ǥ ���̷� ������ �� ���ϱ�.
	size += s1.top().second * (s2.top().first - s1.top().first + 1);

	cout << size << '\n';

	return 0;
}