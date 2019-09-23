#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
	while (b != 0) {
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int N;
	scanf("%d", &N);

	long long lowLimit = 0;
	long long gd = 0;
	long long rem = 0;
	bool isPossible = true;
	for (int i = 0; i < N; i++) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		if (a > 0) {
			rem += a;
			if (rem != b)
				isPossible = false;
		}
		else {//출금
			if (rem + a >= 0) {//양수일 시
				rem = rem + a;
				if (rem != b)
					isPossible = false;
			}
			else {//음수일 시
				lowLimit = max(lowLimit, b + 1);
				long long k = b - a - rem;
				if (gd == 0)
					gd = k;
				else
					gd = gcd(k, gd);

				//printf("gcd: %lld\n", gd);
				//printf("lowLimit: %lld\n", lowLimit);
				if (gd < lowLimit)
					isPossible = false;
				rem = b;
			}
		}
		//printf("rem: %lld\n", rem);
	}

	if (!isPossible)
		printf("-1\n");
	else if (gd != 0)
		printf("%lld\n", gd);
	else
		printf("1\n");

	return 0;
}