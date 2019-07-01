#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000001;

int dp[MAX];

int f(int n) {
	if (n == 1)//1이면 끝
		return 0;
	if (dp[n] != -1)//만약 이미 계산된 경우라면
		return dp[n];//이미 계산된 경우 return
	
	int result = f(n - 1) + 1;//일단 기본적인 경우

	if (n % 3 == 0) //3의 배수의 경우
		result = min(f(n / 3) + 1, result);
	if (n % 2 == 0)//2의 배수의 경우
		result = min(f(n / 2) + 1, result);

	dp[n] = result;
	return result;
}

int main() {
	int N;
	int result;

	cin >> N;
	fill(dp, dp + MAX, -1);//fill: 처음 위치부터 끝 위치까지 -1로 채우는 algorithm 함수
	result = f(N);
	cout << result << '\n';

	return 0;
}
