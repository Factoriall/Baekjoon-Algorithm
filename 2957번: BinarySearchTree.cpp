#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int main() {
	int n;
	long long cnt = 0;
	map<int, int> m;
	m.insert(P(0, -1));
	m.insert(P(300001, -1));

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int num;
		int depth;
		scanf("%d", &num);

		map<int, int>::iterator nextIter = m.upper_bound(num);
		map<int, int>::iterator prevIter = --m.lower_bound(num);
		//printf("%d %d\n", prevIter->second, nextIter->second);
		depth = max(prevIter->second, nextIter->second) + 1;
			
		m.insert(P(num, depth));//¼ýÀÚ¸¦ ¸Ê¿¡ »ðÀÔ = depth;
		cnt += depth;
		printf("%lld\n", cnt);
	}
	return 0;
}
