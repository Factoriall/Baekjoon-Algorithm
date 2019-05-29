#include <iostream>
#include <algorithm>
using namespace std;

int card[100001];//카드팩 정렬 
int usedPnt[500001];//중복 확인 및 위치 확인

void reset() {//usedPnt 리셋 함수
	int j;
	for (j = 1; j <= 500000; j++) {
		usedPnt[j] = 0;
	}
}

int main() {
	int i;
	int N, M;
	int ans = 1;

	cin >> N >> M;

	for (i = 1; i <= N; i++) {
		cin >> card[i];
	}

	//이진탐색 사용
	int left = 1;
	int right = N / M;
	

	while (left <= right) {
		int cnt = 0;
		int start = 1;
		int mid = (right + left) / 2;
		reset();

		for (i = 1; i <= N; i++) {
			if (usedPnt[card[i]] != 0 && usedPnt[card[i]] >= start) {//만약 이미 사용한 적이 있고 && start지점보다 뒤에 있다. -> 중복된다.
				start = usedPnt[card[i]] + 1;//스타트 지점 변경
			}
			
			usedPnt[card[i]] = i;
			
			if (i + 1 - start == mid) {//만약 실제 수랑 일치한다면 카운트 업
				cnt++;
				start = i + 1;
			}
			if (cnt == M)//만약 수 일치하면 빠져나감
				break;
		}

		if (cnt == M) {//만약 조건 만족하면 ans 값 대조, left 값 증가
			ans = max(ans, mid);
			left = mid + 1;
		}
		else {//만족 안하면 right 값 줄이기
			right = mid - 1;
		}
	}
	
	cout << ans << endl;

	return 0;
}
