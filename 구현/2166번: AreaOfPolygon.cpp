#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

typedef pair<long long, long long> P;

double getSize(P a, P b) {
	return (a.first - b.first) * (a.second + b.second) / 2.0;
}

int main() {
	int N;
	double size = 0.0;
	scanf("%d", &N);
	
	P init;
	P prev;

	for (int i = 0; i < N; i++) {
		long long x, y;
		scanf("%lld %lld", &x, &y);
		if (i == 0) {
			init = P(x, y);
			prev = P(x, y);
			continue;
		}
		//printf("[%lld, %lld], [%d, %lld]", prev.first, prev.second, init.first, init.second);
		size += getSize(prev, P(x, y));
		prev = P(x, y);
		//printf("%.1lf\n", size);
	}
	
	size += getSize(prev, init);
	//printf("%.1lf\n", size);

	printf("%.1lf", size > 0 ? size : -size);
}
