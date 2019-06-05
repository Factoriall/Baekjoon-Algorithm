#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int goods[30];
int n, c;

vector<int> v1, v2;

void dfs(int start, int end, int sum, vector<int>& v) {//vector�� &�� �ٿ���� �Ű������� ����Ǿ� dfs�� ����ȴ�. �� �׷��� �ٷ� �Լ� ����ڸ��� �ٷ� �������!!!
	if (sum > c)//���� ������ ���;� a==n && sum>c�� ������ ��ġ�� �ʴ´�.
		return;
	if (start > end) {//������ ���������� �� ����
		v.push_back(sum);
		return;
	}
	
	dfs(start + 1, end, sum + goods[start], v);
	dfs(start + 1, end, sum, v);

}

int main() {
	
	int i;
	int cnt = 0;
	
	cin >> n >> c;

	for (i = 0; i < n; i++) {
		cin >> goods[i];
	}

	//�ٽ�: 2^30�� �ʹ� ���� �ɸ��� ������ ������ �ɰ��� 2*2^15�� �����
	dfs(0, n / 2 - 1, 0, v1);
	dfs(n / 2, n - 1, 0, v2);
	sort(v1.begin(), v1.end());//����ġ�� ���� ���
	sort(v2.begin(), v2.end());
	/*for (vector<int>::size_type j = 0; j < v1.size(); j++)
		cout << v1[j] << ' ';
	cout << endl;
		
	for (vector<int>::size_type k = 0; k < v2.size(); k++) 
		cout << v2[k] << ' ';
	cout << endl;*/

	for (vector<int>::size_type j = 0; j < v1.size(); j++) {//�ΰ� ���ؼ� sum �Ѿ�� ������ ���� ����, cnt�� ���Ѵ�.
		for (vector<int>::size_type k = 0; k < v2.size(); k++) {
			if (v1[j] + v2[k] <= c) {
				cnt++;
			}
			else
				break;
		}
	}

	cout << cnt << endl;

	return 0;
}