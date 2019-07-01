#include <iostream>
#include <queue>
#include <string>
using namespace std;


int main() {
	int n, k;//n-입력 수, k-좋은 친구가 될 수 있는 등수 차이
	string t;
	queue<int> q[21];//길이에 대응하는 queue 배열 생성
	long long int result = 0;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> t;

		int s = t.size();//s-문자열 길이
		//cout << s << endl;
		if(!q[s].empty()){//만약 비어있지 않을시 좋은 친구의 쌍 구하기
			//지금 인덱스와 큐 맨 앞의 인덱스 차이가 k보다 크면 pop
			while (!q[s].empty() && i - q[s].front() > k)
				q[s].pop();
			//queue 안 남은 인덱스들은 모두 지금 삽입되는 인덱스와 좋은 친구!
			result += q[s].size();
		}
		q[s].push(i);//각 길이에 대응하는 queue에 삽입
	}

	cout << result << '\n';//결과 출력
	
	return 0;
}
