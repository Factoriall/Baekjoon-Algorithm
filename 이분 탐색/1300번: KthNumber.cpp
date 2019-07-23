#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	int i, j;
	int n, k;

	scanf("%d", &n);
	scanf("%d", &k);

	int hi = 1000000000;
	int lo = 0;

	while (lo + 1 < hi) {
		int cnt = 0;
		int mid = (hi + lo) / 2;
		for (i = 1; i <= n; i++) {
			int tmp = mid / i;
			if (tmp <= n) {
				tmp -= mid % i == 0 ? 1 : 0;
				cnt += tmp;
			}
			else 
				cnt += n;
			
			//if (cnt >= k)
			//	break;
		}
		//printf("high: %lld, low: %lld, mid :%lld\n", hi, lo, mid);
		//printf("cnt : %lld\n\n", cnt);

		if (cnt >= k)
			hi = mid;
		else
			lo = mid;
	}

	printf("%d\n", lo);

	return 0;
}
