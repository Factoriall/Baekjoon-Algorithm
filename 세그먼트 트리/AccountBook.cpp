#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
int S = 1;

long long tree[2097152];

void update(int i, int val) {
	i += S;
	tree[i] += val;
	while (i > 1) {
		i /= 2;
		tree[i] = tree[2 * i] + tree[2 * i + 1];
	}
}

long long segmentSum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	//printf("%d %d\n", nodeNum, tree[nodeNum]);
	if (R < nodeL || L > nodeR) return 0;
	if (L <= nodeL && R >= nodeR) return tree[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return segmentSum(L, R, nodeNum * 2, nodeL, mid) + segmentSum(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}

int main() {
	int N, Q;

	scanf("%d %d", &N, &Q);

	while (S < N)
		S *= 2;

	for (int t = 0; t < Q; t++) {
		int idx, p, q;
		scanf("%d %d %d", &idx, &p, &q);
		if (idx == 1) 
			update(p - 1, q);
		else
			printf("%lld\n", segmentSum(p - 1, q - 1, 1, 0, S - 1));
	}

	return 0;
}