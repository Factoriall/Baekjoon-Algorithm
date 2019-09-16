#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int maxN = -1000000001;
int minN = 1000000001;
int num[11];
int op[4];

void dfs(int n, int oprd) {
	if (n == N) {
		maxN = max(maxN, oprd);
		minN = min(minN, oprd);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] != 0) {
			op[i]--;
			if (i == 0)
				dfs(n + 1, oprd + num[n]);
			else if (i == 1)
				dfs(n + 1, oprd - num[n]);
			else if (i == 2)
				dfs(n + 1, oprd * num[n]);
			else if (i == 3)
				dfs(n + 1, oprd / num[n]);
			op[i]++;
		}
	}


}

int main(){
	
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		scanf("%d", &num[i]);
	
	for (int i = 0; i < 4; i++)
		scanf("%d", &op[i]);

	dfs(1, num[0]);

	printf("%d\n%d\n", maxN, minN);

	return 0;
}
