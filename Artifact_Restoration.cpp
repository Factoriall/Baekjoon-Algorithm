#include <iostream>
using namespace std;

int used[51][51];
int arr[51][51];

int n, m, k;

void print(int a[][51]) {
	int i, j;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			cout << a[i][j] << '\t';
		}
		cout << endl;
	}
}

void fillUsedArr() {
	int i, j;
	int a;
	int midN = n / 2; 
	int midM = m / 2;
	int down;

	used[0][1] = used[0][m] = m;
	used[1][0] = used[n][0] = n;
	//cout << midN <<  ' ' << midM << endl;

	down = n;
	a = 2;
	while (a <= midN) {
		down = down - 2;
		used[a][0] = used[a - 1][0] + down;
		used[n + 1 - a][0] = used[n + 2 - a][0] + down;
		a++;
	}
	if (n % 2 == 1) {
		used[a][0] = used[a - 1][0] + 1;
	}

	down = m;
	a = 2;
	while (a <= midM) {
		down = down - 2;
		used[0][a] = used[0][a - 1] + down;
		used[0][m + 1 - a] = used[0][m + 2 - a] + down;
		a++;
	}
	if (m % 2 == 1) {
		used[0][a] = used[0][a - 1] + 1;
	}

	

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			used[i][j] = (used[i][0] * used[0][j]) % k;
		}
	}
}

int main() {
	
	//int midN, midM;
	//int i, j;
	
	cin >> n >> m >> k;

	fillUsedArr();
	print(used);

	
}