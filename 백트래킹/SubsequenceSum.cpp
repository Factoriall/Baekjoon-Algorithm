#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int N, S;
int cnt = 0;
int currentSum = 0;

int arr[20];

void dfs(int n) {
	if (n == N)
		return;
	if (currentSum + arr[n] == S)//이렇게 arr[n]이 더해지게 해야된다!
		cnt++;
	dfs(n + 1);
	currentSum += arr[n];
	dfs(n + 1);
	currentSum -= arr[n];
}

int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	dfs(0);
	printf("%d\n", cnt);
	return 0;
}