#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

typedef struct {
	int s;
	int e;
	int itv;
}Rule;

int main() {
	int i;
	int n, k, d;
	
	scanf("%d %d %d", &n, &k, &d);

	Rule r[10001];

	for (i = 0; i < k; i++)
		scanf("%d %d %d", &r[i].s, &r[i].e, &r[i].itv);
	
	int lo = 0;
	int hi = n;
	int mid;
	while (lo + 1 < hi) {
		mid = (lo + hi) / 2;
		//printf("low: %d, high: %d, mid: %d\n", lo, hi, mid);
		long long cnt = 0;
		for (i = 0; i < k; i++) {
			if (mid >= r[i].s) {
				cnt++;
				int maxNum = r[i].e < mid ? r[i].e : mid;
				cnt = cnt + (maxNum - r[i].s) / r[i].itv;
			}
		}
		//printf("cnt: %d\n\n", cnt);

		if (cnt >= d)
			hi = mid;
		else
			lo = mid;
	}

	printf("%d\n", hi);

	return 0;
}
