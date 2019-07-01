#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<pair<int, int>> pillar;//first - x좌표, second - 높이 
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

	pair<int, int> tmp;//pillar vector에 저장하기 위한 임시 pair 변수
	for (i = 0; i < n; i++) {//저장
		cin >> tmp.first >> tmp.second;
		pillar.push_back(tmp);
	}

	sort(pillar.begin(), pillar.end(), cmp);//x좌표 순서에 맞게 정렬
		
	/*for (i = 0; i < pillar.size(); i++)
		cout << '[' << pillar[i].first << ", " << pillar[i].second << ']' << endl;*/
	
	//왼쪽부터 오른쪽으로 직사각형 더하기
	s1.push(pillar[0]);
	for (i = 1; i < n; i++) {
		if (s1.top().second < pillar[i].second) {
			size += s1.top().second * (pillar[i].first - s1.top().first);
			s1.push(pillar[i]);
		}
	}

	//오른쪽부터 왼쪽으로 가면서 직사각형 더하기
	s2.push(pillar[n - 1]);
	for (i = n-2; i >= 0; i--) {
		if (s2.top().second < pillar[i].second) {
			size += s2.top().second * (s2.top().first - pillar[i].first);
			s2.push(pillar[i]);
		}
	}

	//마지막으로 s1, s2 탑 높이(같음) * 그 둘의 x좌표 차이로 나머지 값 구하기.
	size += s1.top().second * (s2.top().first - s1.top().first + 1);

	cout << size << '\n';

	return 0;
}