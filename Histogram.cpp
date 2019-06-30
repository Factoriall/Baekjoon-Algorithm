#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

stack<pair<int, int>> s;//first - x좌표, second - 높이
int histo[100001];

bool Pred(int i) {//조건자 - 스택이 비어있거나 지금 높이가 스택 맨 위의 높이보다 클 시 true
	if (s.empty() || histo[i] > s.top().second)
		return true;
	else
		return false;
}

int main() {
	int n;//좌표 개수	
	int i;//반복자
	int result = 0;
	int x, h, l;
	//x: 지금 가로 위치, h=높이, ㅣ=직사각형 가로 길이 

	cin >> n;
	for (i = 1; i <= n; i++) 
		cin >> histo[i];
	
	for (i = 1; i <= n; i++) {
		if (!Pred(i)) {//만약 pred 조건에 맞지 않다면 맞을 때 까지 반복
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
		//위 조건 상관없이 push하는 것은 기본
		pair<int, int> tmp;
		tmp.first = i;
		tmp.second = histo[i];
		s.push(tmp);
	}

	while (!s.empty()) {//끝까지 확인했을 시 스택이 빌 때까지 돌린다.
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