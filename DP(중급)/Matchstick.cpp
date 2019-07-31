#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int small;

int dp[101];
int order[4] = {1, 2, 6, 8};
vector<int> v;

int power(int n) {
	int ret = 1;
	for (int i = 0; i < n; i++) {
		ret *= 10;
	}
	return ret;
}

void dfs(int n) {

	if (n == 2) {
		v.push_back(1);
		return;
	}
	if (n == 3) {
		v.push_back(7);
		return;
	}
	if (n == 4) {
		v.push_back(4);
		return;
	}
	if (n == 5) {
		v.push_back(2);
		return;
	}
	if (n == 6) {
		v.push_back(6);
		return;
	}
	if (n == 7) {
		v.push_back(8);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if ((n - order[i] - 1) / 7 < (n - 1) / 7) {
			v.push_back(order[i]);
			dfs(n - order[i]);
			break;
		}
	}
}

int main() {
	int T;

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int n;
		v.clear();
		
		scanf("%d", &n);
		small = (n - 1) / 7;

		fill(dp, dp + 101, -1);
		dfs(n);

		for (int i = 0; i < v.size(); i++) {
			if (i != 0 && v[i] == 6)
				printf("0");
			else
				printf("%d", v[i]);
		}
		printf(" ");

		//큰 숫자 출력
		if (n % 2 == 0) {
			while (n > 0) {
				printf("1");
				n = n - 2;
			}
		}
		else {
			printf("7");
			while (n > 3) {
				printf("1");
				n = n - 2;
			}
		}
		printf("\n");
	}

	return 0;
}
