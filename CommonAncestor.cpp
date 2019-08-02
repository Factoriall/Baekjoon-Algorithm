#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

int parent[20000];

int main() {
	int T;

	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int parent[10000];
		
		int N;
		scanf("%d", &N);
		fill(parent, parent + N, -1);

		for (int i = 0; i < N - 1; i++) {
			int p, c;
			scanf("%d %d", &p, &c);
			parent[c - 1] = p - 1;
		}
		/*for (int i = 0; i < N; i++) {
			printf("%d ", parent[i]);
		}
		printf("\n");*/

		int f1, f2;
		vector<int> v1;
		vector<int> v2;

		scanf("%d %d", &f1, &f2);
		f1--; f2--;

		while (parent[f1] != -1) {
			v1.push_back(f1);
			f1 = parent[f1];
		}
		v1.push_back(f1);
		reverse(v1.begin(), v1.end());

		
		while (parent[f2] != -1) {
			v2.push_back(f2);
			f2 = parent[f2];
		}
		v2.push_back(f2);
		reverse(v2.begin(), v2.end());

		for (int n : v1)
			printf("%d ", n);
		printf("\n");
		for (int n : v2)
			printf("%d ", n);
		printf("\n");
		
		int k = 0;
		while (k<v1.size() && k<v2.size() && v1[k] == v2[k])
			k++;

		printf("%d ", v1[k - 1] + 1);
	}

	return 0;
}