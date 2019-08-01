#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int h[500001], now[500001];

int main() {
	int n, m;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &h[i]);
	
	sort(h, h + n);

	/*for (int i = 0; i < n; i++)
		printf("%d ", h[i]);
	printf("\n");*/

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &now[i]);

	for (int i = 0; i < m; i++) {
		int find = now[i];
		int cnt = 0;
		int hi = n;
		int lo = 0;

		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (h[mid] == find) {
				int up = mid;
				int down = mid;

				while (up < hi) {
					int m = (up + hi) / 2;
					if (h[m] == find)
						up = m + 1;
					else
						hi = m;
				}

				while (lo < down) {
					int m = (lo + down) / 2;
					if (h[m] == find)
						down = m;
					else
						lo = m + 1;
				}
				cnt = up - down;
				break;
			}
			else if(h[mid] > find)
				hi = mid;
			else 
				lo = mid + 1;
			
		}
		printf("%d ", cnt);
	}

	return 0;
}