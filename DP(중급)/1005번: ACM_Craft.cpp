#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int build_time[1000];
int memo[1000];
vector<int> inv[1000];

int dynamic_programming(int curr) {
	//printf("curr: %d\n", curr);
	int& ret = memo[curr];
	if (ret != 0)
		return ret;
	if (inv[curr].size() == 0) 
		return ret = build_time[curr];

	int mx = 0;
	for (int prev : inv[curr]) 
		mx = max(mx, build_time[curr] + dynamic_programming(prev));
	
	printf("ret: %d\n", mx);
	return ret = mx;
}

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int N, K, W;//N: 건물개수, K: 규칙 수, W: 목표 건물
		
		scanf("%d %d", &N, &K);

		for (int i = 0; i < N; i++)
			scanf("%d", &build_time[i]);

		for (int i = 0; i < K; i++) {
			int s, e;

			scanf("%d %d", &s, &e);
			inv[e - 1].push_back(s - 1);
		}

		scanf("%d", &W);
		printf("%d\n", dynamic_programming(W-1));

		/*for (int i = 0; i < N; i++) {
			
			printf("%d, ", memo[i]);
		}
		printf("\n");*/

		for (int i = 0; i < N; i++) {
			inv[i].clear();
			memo[i] = 0;
		}
	}

	return 0;
}
