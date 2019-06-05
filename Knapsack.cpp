#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int goods[30];
int n, c;

vector<int> v1, v2;

void dfs(int start, int end, int sum, vector<int>& v) {//vector에 &를 붙여줘야 매개변수로 저장되어 dfs에 저장된다. 안 그러면 바로 함수 벗어나자마자 바로 사라진다!!!
	if (sum > c)//먼저 조건이 나와야 a==n && sum>c인 조건이 겹치지 않는다.
		return;
	if (start > end) {//끝까지 도달했을시 값 저장
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

	//핵심: 2^30은 너무 오래 걸리기 때문에 반으로 쪼개서 2*2^15로 만든다
	dfs(0, n / 2 - 1, 0, v1);
	dfs(n / 2, n - 1, 0, v2);
	sort(v1.begin(), v1.end());//가지치기 위해 사용
	sort(v2.begin(), v2.end());
	/*for (vector<int>::size_type j = 0; j < v1.size(); j++)
		cout << v1[j] << ' ';
	cout << endl;
		
	for (vector<int>::size_type k = 0; k < v2.size(); k++) 
		cout << v2[k] << ' ';
	cout << endl;*/

	for (vector<int>::size_type j = 0; j < v1.size(); j++) {//두개 합해서 sum 넘어가지 않으면 조건 만족, cnt에 더한다.
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