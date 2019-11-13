#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int main() {
	int n;
	long long cnt = 0;//300000^2는 int 범위 벗어나므로 long long으로 설정
	map<int, int> m;//map 함수로 쉽게 표현 가능
	m.insert(P(0, -1));//하한선
	m.insert(P(300001, -1));//상한선

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int num;
		int depth;
		scanf("%d", &num);

		map<int, int>::iterator nextIter = m.upper_bound(num);//num이 가리키는 위치의 다음 노드 위치
		map<int, int>::iterator prevIter = --m.lower_bound(num);//num이 가리키는 위치의 전 노드 위치
		//printf("%d %d\n", prevIter->second, nextIter->second);
		depth = max(prevIter->second, nextIter->second) + 1;//양쪽의 위치 중 더 높은 것을 찾아 + 1 해준다.
			
		m.insert(P(num, depth));//구한 depth와 같이 num을 map에 삽입
		cnt += depth;
		printf("%lld\n", cnt);
	}
	return 0;
}
